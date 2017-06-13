#include "mainwindow.h"
#include "ui_mainwindow.h"
//Morphological edge detection
void MainWindow::OnShowMorphologicalEdgeDetectionClicked()
{
    typedef   unsigned char  InputPixelType;
    typedef   unsigned char  OutputPixelType;
    typedef itk::Image< InputPixelType,  2 >   InputImageType;
    typedef itk::Image< OutputPixelType, 2 >   OutputImageType;
      typedef itk::Image<unsigned char, 2>    ImageType;
      typedef itk::ImageFileReader<InputImageType> ReaderType;
      typedef itk::ImageToVTKImageFilter<OutputImageType>       ConnectorType;
      ReaderType::Pointer reader = ReaderType::New();
      reader->SetFileName((const char*)filename.toStdString().c_str());

     unsigned int radius = 2;
     ui->radiusSlider->setMinimum(0);
     ui->radiusSlider->setMaximum(50);
     radius = ui->radiusSlider->value();

     typedef itk::BinaryBallStructuringElement<ImageType::PixelType, ImageType::ImageDimension>
                   StructuringElementType;
       StructuringElementType structuringElement;
       structuringElement.SetRadius(radius);
       structuringElement.CreateStructuringElement();

       typedef itk::BinaryDilateImageFilter <ImageType, ImageType, StructuringElementType>
           BinaryDilateImageFilterType;

         BinaryDilateImageFilterType::Pointer dilateFilter
           = BinaryDilateImageFilterType::New();
         dilateFilter->SetInput(reader->GetOutput());
         dilateFilter->SetKernel(structuringElement);



         typedef itk::BinaryErodeImageFilter <ImageType, ImageType, StructuringElementType>
             BinaryErodeImageFilterType;

           BinaryErodeImageFilterType::Pointer erodeFilter
             = BinaryErodeImageFilterType::New();
           erodeFilter->SetInput(reader->GetOutput());
           erodeFilter->SetKernel(structuringElement);

           typedef itk::SubtractImageFilter<ImageType> SubtractType;
           SubtractType::Pointer diff = SubtractType::New();
           diff->SetInput2(erodeFilter->GetOutput());
           diff->SetInput1(dilateFilter->GetOutput());

           ConnectorType::Pointer connector = ConnectorType::New();
           connector->SetInput(diff->GetOutput());
           vtkSmartPointer<vtkImageActor> actor =
             vtkSmartPointer<vtkImageActor>::New();
         #if VTK_MAJOR_VERSION <= 5
           actor->SetInput(connector->GetOutput());
         #else
           connector->Update();
           actor->GetMapper()->SetInputData(connector->GetOutput());
         #endif

           vtkSmartPointer<vtkRenderer> diffRenderer =
             vtkSmartPointer<vtkRenderer>::New();
           diffRenderer->AddActor(actor);
           diffRenderer->ResetCamera();

           ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(diffRenderer);
           //ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(originalRenderer);
           ui->qvtkWidget_4->GetRenderWindow()->Render();
}
