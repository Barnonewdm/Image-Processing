#include "mainwindow.h"
#include "ui_mainwindow.h"
//Morphological distance transform
void MainWindow::OnShowMorphologicalDistanceTransformClicked()
{
   /* vtkSmartPointer<vtkJPEGReader> reader = vtkSmartPointer<vtkJPEGReader>::New();
    reader->SetFileName((const char*)filename.toStdString().c_str());
    reader->Update();

    vtkSmartPointer<vtkImageCast> castFilter =
        vtkSmartPointer<vtkImageCast>::New();
      castFilter->SetOutputScalarTypeToShort();
      castFilter->SetInputConnection(reader->GetOutputPort());

      vtkSmartPointer<vtkImageCityBlockDistance> cityBlockDistanceFilter =
        vtkSmartPointer<vtkImageCityBlockDistance>::New();
      cityBlockDistanceFilter->SetInputConnection(castFilter->GetOutputPort());
      cityBlockDistanceFilter->SetDimensionality(2);
      cityBlockDistanceFilter->Update();

      // Create actors
      vtkSmartPointer<vtkImageCast> inputCastFilter =
        vtkSmartPointer<vtkImageCast>::New();
      inputCastFilter->SetOutputScalarTypeToUnsignedChar();
      inputCastFilter->SetInputConnection(reader->GetOutputPort());

      vtkSmartPointer<vtkImageActor> inputActor =
        vtkSmartPointer<vtkImageActor>::New();
      inputActor->GetMapper()->SetInputConnection(inputCastFilter->GetOutputPort());

      vtkSmartPointer<vtkImageCast> distanceCastFilter =
        vtkSmartPointer<vtkImageCast>::New();
      distanceCastFilter->SetOutputScalarTypeToUnsignedChar();
      distanceCastFilter->SetInputConnection(cityBlockDistanceFilter->GetOutputPort());

      vtkSmartPointer<vtkImageActor> distanceActor =
        vtkSmartPointer<vtkImageActor>::New();
      distanceActor->GetMapper()->SetInputConnection(
        distanceCastFilter->GetOutputPort());

      // Define viewport ranges
      // (xmin, ymin, xmax, ymax)
      double inputViewport[4] = {0.0, 0.0, 0.5, 1.0};
      double distanceViewport[4] = {0.5, 0.0, 1.0, 1.0};

      // Setup renderers
      vtkSmartPointer<vtkRenderer> inputRenderer =
        vtkSmartPointer<vtkRenderer>::New();
      inputRenderer->SetViewport(inputViewport);
      inputRenderer->AddActor(inputActor);
      inputRenderer->ResetCamera();
      inputRenderer->SetBackground(.4, .5, .9);

      vtkSmartPointer<vtkRenderer> distanceRenderer =
        vtkSmartPointer<vtkRenderer>::New();
      distanceRenderer->SetViewport(distanceViewport);
      distanceRenderer->AddActor(distanceActor);
      distanceRenderer->ResetCamera();
      distanceRenderer->SetBackground(.4, .5, .7);

    ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(inputRenderer);
    ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(distanceRenderer);
    ui->qvtkWidget_4->GetRenderWindow()->Render();

*/
    typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
    typedef itk::Image<float, 2>          FloatImageType;
    UnsignedCharImageType::Pointer image = UnsignedCharImageType::New();
    typedef   unsigned char  InputPixelType;
    typedef   unsigned char  OutputPixelType;
    typedef itk::Image< InputPixelType,  2 >   InputImageType;
    typedef itk::Image< OutputPixelType, 2 >   OutputImageType;
      typedef itk::Image<unsigned char, 2>    ImageType;
      typedef itk::ImageFileReader<InputImageType> ReaderType;
      typedef itk::ImageToVTKImageFilter<FloatImageType>       ConnectorType;
      ReaderType::Pointer reader = ReaderType::New();
      reader->SetFileName((const char*)filename.toStdString().c_str());
      reader->Update();
      image = reader->GetOutput();

      typedef  itk::ApproximateSignedDistanceMapImageFilter< UnsignedCharImageType, FloatImageType  >
              ApproximateSignedDistanceMapImageFilterType;
       ApproximateSignedDistanceMapImageFilterType::Pointer approximateSignedDistanceMapImageFilter =
         ApproximateSignedDistanceMapImageFilterType::New();
       approximateSignedDistanceMapImageFilter->SetInput(image);
       approximateSignedDistanceMapImageFilter->SetInsideValue(255);
       approximateSignedDistanceMapImageFilter->SetOutsideValue(0);
       ConnectorType::Pointer connector = ConnectorType::New();
       connector->SetInput(approximateSignedDistanceMapImageFilter->GetOutput());

       vtkSmartPointer<vtkImageActor> actor =
         vtkSmartPointer<vtkImageActor>::New();
     #if VTK_MAJOR_VERSION <= 5
       actor->SetInput(connector->GetOutput());
     #else
       connector->Update();
       actor->GetMapper()->SetInputData(connector->GetOutput());
     #endif

       vtkSmartPointer<vtkRenderer> distanceRenderer =
         vtkSmartPointer<vtkRenderer>::New();
       distanceRenderer->AddActor(actor);
       distanceRenderer->ResetCamera();

       ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(distanceRenderer);
       //ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(originalRenderer);
       ui->qvtkWidget_4->GetRenderWindow()->Render();
}
