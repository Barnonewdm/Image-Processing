#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::OnShowNoiseReductionClicked()
{
    /*
    vtkSmartPointer<vtkJPEGReader> src = vtkSmartPointer<vtkJPEGReader>::New();
    src->SetFileName((const char*)filename.toStdString().c_str());
    src->Update();
    */
    typedef   unsigned char  InputPixelType;
    typedef   unsigned char  OutputPixelType;
    typedef itk::Image< InputPixelType,  2 >   InputImageType;
    typedef itk::Image< OutputPixelType, 2 >   OutputImageType;
    //typedef itk::Image<itk::RGBPixel<unsigned char>, 2> ImageType;
   // typedef itk::ImageFileReader<ImageType>             ReaderType;
    typedef itk::ImageToVTKImageFilter<OutputImageType>       ConnectorType;

    typedef itk::ImageFileReader< InputImageType  >  ReaderType1;
    //typedef itk::ImageFileWriter< OutputImageType >  WriterType;

    typedef itk::DiscreteGaussianImageFilter<InputImageType, OutputImageType >  FilterType;
    FilterType::Pointer medianFilter = FilterType::New();

    ReaderType1::Pointer reader = ReaderType1::New();
    reader->SetFileName((const char*)filename.toStdString().c_str());
   // WriterType::Pointer writer = WriterType::New();

    int radius=5;
    ui->radiusSlider->setMinimum(0);
    ui->radiusSlider->setMaximum(50);
    radius = ui->radiusSlider->value();
    medianFilter->SetVariance(radius);
    medianFilter->SetInput(reader->GetOutput());
    //medianFilter->SetInput(src->GetOutput());

/*
    vtkDataObject<vtkDataObject> data = vtkDataObject<vtkDataObject>::New();
    data->

    vtkSmartPointer<vtkJPEGReader> result = vtkSmartPointer<vtkJPEGReader>::New();
    result->SetInputData();
    result->SetFileName((const char*)filename.toStdString().c_str());
    result->Update();

    //vtkSmartPointer<vtkImageActor>
    //writer->SetInput( medianfilter->GetOutput() );
    //writer->Update();
*/
    //writer->SetInput(medianFilter->GetOutput());
    //writer->Update();
    //ReaderType::Pointer reader1 = ReaderType::New();
   ConnectorType::Pointer connector = ConnectorType::New();
    //reader1->SetInput(reader->GetOutput());
    //reader1->SetFileName((const char*)filename.toStdString().c_str());
    connector->SetInput(medianFilter->GetOutput());
    //connector->SetInput(reader->GetOutput());

    vtkSmartPointer<vtkImageActor> actor =
      vtkSmartPointer<vtkImageActor>::New();
  #if VTK_MAJOR_VERSION <= 5
    actor->SetInput(connector->GetOutput());
  #else
    connector->Update();
    actor->GetMapper()->SetInputData(connector->GetOutput());
  #endif
    vtkSmartPointer<vtkRenderer> renderer =
      vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);
    renderer->ResetCamera();
    ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(renderer);
    ui->qvtkWidget_4->GetRenderWindow()->Render();
}
