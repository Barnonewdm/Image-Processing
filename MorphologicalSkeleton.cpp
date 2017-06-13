#include "mainwindow.h"
#include "ui_mainwindow.h"
//Morphological Skeleton
void MainWindow::OnShowMorphologicalSkeletonClicked()
{
    /*vtkSmartPointer<vtkImageReader> src = vtkSmartPointer<vtkImageReader>::New();
    src->SetFileName((const char*)filename.toStdString().c_str());
    src->Update();


    vtkSmartPointer<vtkImageSkeleton2D> imageSkeleton =
        vtkSmartPointer<vtkImageSkeleton2D>::New();
    imageSkeleton->SetInputConnection(src->GetOutputPort());
    //imageSkeleton->SetPrune(2);

    imageSkeleton->Update();
    //Create Actors
    vtkSmartPointer<vtkImageActor> inputActor =
        vtkSmartPointer<vtkImageActor>::New();
    inputActor->GetMapper()->SetInputConnection(
    src->GetOutputPort());

    vtkSmartPointer<vtkImageActor> skeletonActor =
        vtkSmartPointer<vtkImageActor>::New();
    skeletonActor->GetMapper()->SetInputConnection(
    imageSkeleton->GetOutputPort());*/
    typedef   unsigned char  InputPixelType;
    typedef   unsigned char  OutputPixelType;
    typedef itk::Image< InputPixelType,  2 >   InputImageType;
    typedef itk::Image< OutputPixelType, 2 >   OutputImageType;
      typedef itk::Image<unsigned char, 2>    ImageType;
      typedef itk::ImageFileReader<InputImageType> ReaderType;
      typedef itk::ImageToVTKImageFilter<OutputImageType>       ConnectorType;
      ReaderType::Pointer reader = ReaderType::New();
      reader->SetFileName((const char*)filename.toStdString().c_str());

      typedef itk::BinaryThinningImageFilter <ImageType, ImageType> BinaryThinningImageFilterType;
        BinaryThinningImageFilterType::Pointer binaryThinningImageFilter = BinaryThinningImageFilterType::New();
        binaryThinningImageFilter->SetInput(reader->GetOutput());
        binaryThinningImageFilter->Update();

        typedef itk::RescaleIntensityImageFilter< ImageType, ImageType > RescaleType;
         RescaleType::Pointer rescaler = RescaleType::New();
         rescaler->SetInput( binaryThinningImageFilter->GetOutput() );
         rescaler->SetOutputMinimum(0);
         rescaler->SetOutputMaximum(255);
         rescaler->Update();

      ConnectorType::Pointer connector = ConnectorType::New();
      connector->SetInput(rescaler->GetOutput());
      vtkSmartPointer<vtkImageActor> skeletonActor =
        vtkSmartPointer<vtkImageActor>::New();
    #if VTK_MAJOR_VERSION <= 5
      actor->SetInput(connector->GetOutput());
    #else
      connector->Update();
      skeletonActor->GetMapper()->SetInputData(connector->GetOutput());
    #endif
    //add render
    vtkSmartPointer<vtkRenderer>skeletonRenderer =
            vtkSmartPointer<vtkRenderer>::New();
    skeletonRenderer->AddActor(skeletonActor);
    skeletonRenderer->ResetCamera();



    ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(skeletonRenderer);
    ui->qvtkWidget_4->GetRenderWindow()->Render();

}
