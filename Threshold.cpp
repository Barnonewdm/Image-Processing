#include "mainwindow.h"
#include "ui_mainwindow.h"
//Threshold
void MainWindow::OnShowThresholdClicked()
{
    vtkSmartPointer<vtkJPEGReader> src = vtkSmartPointer<vtkJPEGReader>::New();
    src->SetFileName((const char*)filename.toStdString().c_str());
    src->Update();

    vtkSmartPointer<vtkImageThreshold> imageThreshold =
        vtkSmartPointer<vtkImageThreshold>::New();
    imageThreshold->SetInputConnection(src->GetOutputPort());
    unsigned char lower = 100;
    unsigned char upper = 255;
    //ui->thresholdingSlider->lower(0);
    ui->thresholdingSlider->setMinimum(0);
    ui->thresholdingSlider->setMaximum(255);
    lower = ui->thresholdingSlider->value();
    imageThreshold->ThresholdBetween(lower, upper);
    imageThreshold->ReplaceInOn();
    imageThreshold->SetInValue(255);
    imageThreshold->SetOutValue(0);
    imageThreshold->Update();
    //Create Actors
    vtkSmartPointer<vtkImageActor> inputActor =
        vtkSmartPointer<vtkImageActor>::New();
    inputActor->GetMapper()->SetInputConnection(
    src->GetOutputPort());

    vtkSmartPointer<vtkImageActor> thresholdedActor =
        vtkSmartPointer<vtkImageActor>::New();
    thresholdedActor->GetMapper()->SetInputConnection(
    imageThreshold->GetOutputPort());
    //add render
    vtkSmartPointer<vtkRenderer>thresholdeRenderer =
            vtkSmartPointer<vtkRenderer>::New();
    thresholdeRenderer->AddActor(thresholdedActor);

    ui->qvtkWidget_3->GetRenderWindow()->AddRenderer(thresholdeRenderer);
    ui->qvtkWidget_3->GetRenderWindow()->Render();

}
