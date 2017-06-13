#include "mainwindow.h"
#include "ui_mainwindow.h"

//Closing (morphology)
void MainWindow::OnShowClosingBinaryClicked()
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

      unsigned int radius = 5;
      ui->radiusSlider->setMinimum(0);
      ui->radiusSlider->setMaximum(50);
      radius = ui->radiusSlider->value();
      typedef itk::BinaryBallStructuringElement<ImageType::PixelType, ImageType::ImageDimension>
                    StructuringElementType;
        StructuringElementType structuringElement;
        structuringElement.SetRadius(radius);
        structuringElement.CreateStructuringElement();

        typedef itk::BinaryMorphologicalClosingImageFilter <ImageType, ImageType, StructuringElementType>
                BinaryMorphologicalClosingImageFilterType;
        BinaryMorphologicalClosingImageFilterType::Pointer closingFilter
                = BinaryMorphologicalClosingImageFilterType::New();
        closingFilter->SetInput(reader->GetOutput());
        closingFilter->SetKernel(structuringElement);
        closingFilter->Update();

        typedef itk::SubtractImageFilter<ImageType> SubtractType;
        SubtractType::Pointer diff = SubtractType::New();
        diff->SetInput1(closingFilter->GetOutput());
        diff->SetInput2(reader->GetOutput());

        ConnectorType::Pointer connector = ConnectorType::New();
        connector->SetInput(closingFilter->GetOutput());
        vtkSmartPointer<vtkImageActor> actor =
          vtkSmartPointer<vtkImageActor>::New();
      #if VTK_MAJOR_VERSION <= 5
        actor->SetInput(connector->GetOutput());
      #else
        connector->Update();
        actor->GetMapper()->SetInputData(connector->GetOutput());
      #endif

        vtkSmartPointer<vtkRenderer> closingRenderer =
          vtkSmartPointer<vtkRenderer>::New();
        closingRenderer->AddActor(actor);
        closingRenderer->ResetCamera();

        ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(closingRenderer);
        //ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(originalRenderer);
        ui->qvtkWidget_4->GetRenderWindow()->Render();
}
