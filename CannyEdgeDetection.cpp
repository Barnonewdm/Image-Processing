#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::OnShowCannyEdgeDetectorClicked()
{
    vtkSmartPointer<vtkJPEGReader> src = vtkSmartPointer<vtkJPEGReader>::New();
    src->SetFileName((const char*)filename.toStdString().c_str());
    src->Update();
    // Define viewport ranges
     // (xmin, ymin, xmax, ymax)
     double originalViewport[4] = {0.0, 0.0, 0.5, 1.0};
     double edgeViewport[4] = {0.5, 0.0, 1.0, 1.0};

     vtkSmartPointer<vtkRenderer> originalRenderer =
         vtkSmartPointer<vtkRenderer>::New();
       originalRenderer->SetViewport(originalViewport);
       vtkSmartPointer<vtkRenderer> edgeRenderer =
         vtkSmartPointer<vtkRenderer>::New();
       edgeRenderer->SetViewport(edgeViewport);

       vtkSmartPointer<vtkImageActor> imageActor =
           vtkSmartPointer<vtkImageActor>::New();
       #if VTK_MAJOR_VERSION <= 5
         imageActor->SetInput(src->GetOutput());
       #else
         imageActor->SetInputData(src->GetOutput());
       #endif
         originalRenderer->AddActor(imageActor);

           vtkSmartPointer<vtkImageLuminance> il =
             vtkSmartPointer<vtkImageLuminance>::New();
           il->SetInputConnection(src->GetOutputPort());

           vtkSmartPointer<vtkImageCast> ic =
             vtkSmartPointer<vtkImageCast>::New();
           ic->SetOutputScalarTypeToFloat();
           ic->SetInputConnection(il->GetOutputPort());

           // Smooth the image
           vtkSmartPointer<vtkImageGaussianSmooth> gs =
             vtkSmartPointer<vtkImageGaussianSmooth>::New();
           gs->SetInputConnection(ic->GetOutputPort());
           gs->SetDimensionality(2);
           gs->SetRadiusFactors(1, 1, 0);

           // Gradient the image
           vtkSmartPointer<vtkImageGradient> imgGradient =
             vtkSmartPointer<vtkImageGradient>::New();
           imgGradient->SetInputConnection(gs->GetOutputPort());
           imgGradient->SetDimensionality(2);

           vtkSmartPointer<vtkImageMagnitude> imgMagnitude =
             vtkSmartPointer<vtkImageMagnitude>::New();
           imgMagnitude->SetInputConnection(imgGradient->GetOutputPort());

           // Non maximum suppression
           vtkSmartPointer<vtkImageNonMaximumSuppression> nonMax =
             vtkSmartPointer<vtkImageNonMaximumSuppression>::New();
         #if VTK_MAJOR_VERSION <= 5
           nonMax->SetMagnitudeInput(imgMagnitude->GetOutput());
           nonMax->SetVectorInput(imgGradient->GetOutput());
         #else
           imgMagnitude->Update();
           nonMax->SetMagnitudeInputData(imgMagnitude->GetOutput());
           imgGradient->Update();
           nonMax->SetVectorInputData(imgGradient->GetOutput());
         #endif
           nonMax->SetDimensionality(2);

           vtkSmartPointer<vtkImageConstantPad> pad =
             vtkSmartPointer<vtkImageConstantPad>::New();
           pad->SetInputConnection(imgGradient->GetOutputPort());
           pad->SetOutputNumberOfScalarComponents(3);
           pad->SetConstant(0);

           vtkSmartPointer<vtkImageToStructuredPoints> i2sp1 =
             vtkSmartPointer<vtkImageToStructuredPoints>::New();
           i2sp1->SetInputConnection(nonMax->GetOutputPort());
         #if VTK_MAJOR_VERSION <= 5
           i2sp1->SetVectorInput(pad->GetOutput());
         #else
           pad->Update();
          i2sp1->SetVectorInputData(pad->GetOutput());
         #endif

           // Link edgles
           vtkSmartPointer<vtkLinkEdgels> imgLink =
             vtkSmartPointer<vtkLinkEdgels>::New();
           imgLink->SetInputConnection(i2sp1->GetOutputPort());
           imgLink->SetGradientThreshold(2);

           // Threshold links
           vtkSmartPointer<vtkThreshold> thresholdEdgels =
             vtkSmartPointer<vtkThreshold>::New();
           thresholdEdgels->SetInputConnection(imgLink->GetOutputPort());
           thresholdEdgels->ThresholdByUpper(10);
           thresholdEdgels->AllScalarsOff();

           vtkSmartPointer<vtkGeometryFilter> gf =
             vtkSmartPointer<vtkGeometryFilter>::New();
           gf->SetInputConnection(thresholdEdgels->GetOutputPort());

           vtkSmartPointer<vtkImageToStructuredPoints> i2sp =
             vtkSmartPointer<vtkImageToStructuredPoints>::New();
           i2sp->SetInputConnection(imgMagnitude->GetOutputPort());
         #if VTK_MAJOR_VERSION <= 5
           i2sp->SetVectorInput(pad->GetOutput());
         #else
           pad->Update();
           i2sp->SetVectorInputData(pad->GetOutput());
         #endif

           // Subpixel them
           vtkSmartPointer<vtkSubPixelPositionEdgels> spe =
             vtkSmartPointer<vtkSubPixelPositionEdgels>::New();
           spe->SetInputConnection(gf->GetOutputPort());
         #if VTK_MAJOR_VERSION <= 5
           spe->SetGradMaps(i2sp->GetStructuredPointsOutput());
         #else
           i2sp->Update();
           spe->SetGradMapsData(i2sp->GetStructuredPointsOutput());
         #endif

           vtkSmartPointer<vtkStripper> strip =
             vtkSmartPointer<vtkStripper>::New();
           strip->SetInputConnection(spe->GetOutputPort());

           vtkSmartPointer<vtkPolyDataMapper> dsm =
             vtkSmartPointer<vtkPolyDataMapper>::New();
           dsm->SetInputConnection(strip->GetOutputPort());
           dsm->ScalarVisibilityOff();

           vtkSmartPointer<vtkActor> planeActor =
             vtkSmartPointer<vtkActor>::New();
           planeActor->SetMapper(dsm);
           planeActor->GetProperty()->SetAmbient(1.0);
           planeActor->GetProperty()->SetDiffuse(0.0);

           // Add the actors to the renderer, set the background and size
           edgeRenderer->AddActor(planeActor);

           //ui->qvtkWidget_4->resetInputContext();
           ui->qvtkWidget_4->GetRenderWindow()->SetMultiSamples(0);
           ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(originalRenderer);
           ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(edgeRenderer);
           ui->qvtkWidget_4->GetRenderWindow()->Render();
}
