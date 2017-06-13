#include "mainwindow.h"
#include "ui_mainwindow.h"
//Binary Erosion on grayscale
void MainWindow::OnShowErosionGrayscaleClicked()
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

    typedef itk::GrayscaleErodeImageFilter <ImageType, ImageType, StructuringElementType>
          GrayscaleErodeImageFilterType;

    GrayscaleErodeImageFilterType::Pointer erodeFilter
          = GrayscaleErodeImageFilterType::New();
    erodeFilter->SetKernel(structuringElement);
    erodeFilter->SetInput(reader->GetOutput());
    erodeFilter->Update();


    ConnectorType::Pointer connector = ConnectorType::New();
    connector->SetInput(erodeFilter->GetOutput());

    vtkSmartPointer<vtkImageActor> actor =
          vtkSmartPointer<vtkImageActor>::New();
      #if VTK_MAJOR_VERSION <= 5
        actor->SetInput(connector->GetOutput());
      #else
        connector->Update();
        actor->GetMapper()->SetInputData(connector->GetOutput());
      #endif

    vtkSmartPointer<vtkRenderer> erodeRenderer =
          vtkSmartPointer<vtkRenderer>::New();
    erodeRenderer->AddActor(actor);
    erodeRenderer->ResetCamera();

    ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(erodeRenderer);
        //ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(originalRenderer);
    ui->qvtkWidget_4->GetRenderWindow()->Render();
}
