#include "mainwindow.h"
#include "ui_mainwindow.h"

//Morphological Gradient
void MainWindow::OnShowMorphologicalGradientClicked()
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

       typedef itk::GrayscaleDilateImageFilter <ImageType, ImageType, StructuringElementType>
           GrayscaleDilateImageFilterType;

         GrayscaleDilateImageFilterType::Pointer dilateFilter
           = GrayscaleDilateImageFilterType::New();
         dilateFilter->SetInput(reader->GetOutput());
         dilateFilter->SetKernel(structuringElement);



         typedef itk::GrayscaleErodeImageFilter <ImageType, ImageType, StructuringElementType>
             GrayscaleErodeImageFilterType;

           GrayscaleErodeImageFilterType::Pointer erodeFilter
             = GrayscaleErodeImageFilterType::New();
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
