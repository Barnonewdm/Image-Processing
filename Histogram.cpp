#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow:: OnShowHistogramClicked()
{
    histSize[0] = 256;
    // BGR values range
    hranges[0] = 0.0;
    hranges[1] = 255.0;
    ranges[0] = hranges;
    channel[0] = 0;
    //const unsigned int MeasurementVectorSize = 1;
    //const unsigned int binsPerDimension = 30;
    vtkSmartPointer<vtkJPEGReader> src = vtkSmartPointer<vtkJPEGReader>::New();
    src->SetFileName((const char*)filename.toStdString().c_str());
    src->Update();
    int numComponents = src->GetOutput()->GetNumberOfScalarComponents();
    /*if( numComponents > 3 )
        {
        std::cout << "Error: cannot process an image with "
                  << numComponents << " components!" << std::endl;
        return EXIT_FAILURE;
        }*/
/*
    typedef itk::Statistics::ImageToHistogramFilter<ImageType> ImageToHistogramFilterType;
    ImageToHistogramFilterType::HistogramType::MeasurementVectorType lowerBound(binsPerDimension);
    lowerBound.Fill(hranges[0]);

    ImageToHistogramFilterType::HistogramType::MeasurementVectorType upperBound(binsPerDimension);
    upperBound.Fill(hranges[1]);

    ImageToHistogramFilterType::HistogramType::SizeType size(MeasurementVectorSize);
    size.Fill(binsPerDimension);

    ImageToHistogramFilterType::Pointer imageToHistogramFilter=ImageToHistogramFilterType::New();
    imageToHistogramFilter->SetInput(src);
    imageToHistogramFilter->SetHistogramBinMinimum(lowerBound);
    imageToHistogramFilter->SetHistogramBinMaximum(upperBound);
    imageToHistogramFilter->SetHistogramSize(size);
    imageToHistogramFilter->SetAutoMinimumMaximum(false);
    imageToHistogramFilter->Update();

    //ImageToHistogramFilterType::HistogramType* histogram = imageToHistogramFilter->GetOutput();

    unsigned int totalBins = 1;
*/


    vtkSmartPointer<vtkXYPlotActor> plot=
            vtkSmartPointer<vtkXYPlotActor>::New();
    plot->ExchangeAxesOff();
    plot->SetLabelFormat("%g");
    plot->SetXTitle("Level");
    plot->SetYTitle("Frequency");
    plot->SetXValuesToValue();

    double xmax = 0.;
    double ymax = 0.;

    double colors[3][3]={
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    const char* labels[3] = {"Red","Green","Blue"};
    for( int i = 0; i < numComponents; ++i )
        {
        vtkSmartPointer<vtkImageExtractComponents> extract =
          vtkSmartPointer<vtkImageExtractComponents>::New();
        extract->SetInputConnection( src->GetOutputPort() );
        extract->SetComponents( i );
        extract->Update();

        double range[2];
        extract->GetOutput()->GetScalarRange( range );

        vtkSmartPointer<vtkImageAccumulate> histogram =
          vtkSmartPointer<vtkImageAccumulate>::New();
        histogram->SetInputConnection( extract->GetOutputPort() );
        histogram->SetComponentExtent(
          0,
          static_cast<int>(range[1])-static_cast<int>(range[0])-1,0,0,0,0 );
        histogram->SetComponentOrigin( range[0],0,0 );
        histogram->SetComponentSpacing( 1,0,0 );
        int ignoreZero = 0;
        histogram->SetIgnoreZero( ignoreZero );
        histogram->Update();

        if( range[1] > xmax )
          {
          xmax = range[1];
          }
        if( histogram->GetOutput()->GetScalarRange()[1] > ymax )
          {
          ymax = histogram->GetOutput()->GetScalarRange()[1];
          }

    #if VTK_MAJOR_VERSION <= 5
        plot->AddInput( histogram->GetOutput() );
    #else
        plot->AddDataSetInputConnection( histogram->GetOutputPort() );
    #endif
        if( numComponents > 1 )
          {
          plot->SetPlotColor(i,colors[i]);
          plot->SetPlotLabel(i,labels[i]);
          plot->LegendOn();
          }
        }

      plot->SetXRange( 0, xmax );
      plot->SetYRange( 0, ymax );


      // Visualize the histogram(s)
      vtkSmartPointer<vtkRenderer> histRenderer =
        vtkSmartPointer<vtkRenderer>::New();
      histRenderer->AddActor(plot);
      histRenderer->ResetCamera();

      ui->qvtkWidget_2->GetRenderWindow()->AddRenderer(histRenderer);

      ui->qvtkWidget_2->GetRenderWindow()->Render();
      //ui->qvtkWidget_2->GetInteractor()->SetRenderWindow();
      //ui->qvtkWidget_2->GetInteractor()->Render();
      //ui->qvtkWidget_2->GetRenderWindow()->SetSize(640,480);
/*
      vtkSmartPointer<vtkRenderWindowInteractor> interactor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();
      interactor->SetRenderWindow(
                  ui->qvtkWidget_2->GetRenderWindow() );

      // Initialize the event loop and then start it
      interactor->Initialize();
      interactor->Start();
*/
      //return EXIT_SUCCESS;

}
