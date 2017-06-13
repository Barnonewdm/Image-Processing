#include "mainwindow.h"
#include "ui_mainwindow.h"
//Opening in grayscale
void MainWindow::OnShowOpeningGrayscaleClicked()
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

    unsigned int radius=2;
    ui->radiusSlider->setMinimum(0);
    ui->radiusSlider->setMaximum(50);
    radius = ui->radiusSlider->value();
        typedef itk::BinaryBallStructuringElement<ImageType::PixelType, 2>
              StructuringElementType;
        StructuringElementType structuringElement;
        structuringElement.SetRadius(radius);
        structuringElement.CreateStructuringElement();

        typedef itk::GrayscaleConnectedOpeningImageFilter <ImageType, ImageType>
          GrayscaleConnectedOpeningImageFilterType;

        GrayscaleConnectedOpeningImageFilterType::Pointer openingFilter
          = GrayscaleConnectedOpeningImageFilterType::New();
        //openingFilter->SetKernel(structuringElement);
        openingFilter->SetInput(reader->GetOutput());
        openingFilter->Update();


        ConnectorType::Pointer connector = ConnectorType::New();
        connector->SetInput(openingFilter->GetOutput());
        vtkSmartPointer<vtkImageActor> actor =
          vtkSmartPointer<vtkImageActor>::New();
      #if VTK_MAJOR_VERSION <= 5
        actor->SetInput(connector->GetOutput());
      #else
        connector->Update();
        actor->GetMapper()->SetInputData(connector->GetOutput());
      #endif


        vtkSmartPointer<vtkRenderer> openingRenderer =
          vtkSmartPointer<vtkRenderer>::New();
        openingRenderer->AddActor(actor);
        openingRenderer->ResetCamera();

        ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(openingRenderer);
        //ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(originalRenderer);
        ui->qvtkWidget_4->GetRenderWindow()->Render();
}
