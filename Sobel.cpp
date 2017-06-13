#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::OnShowSobelClicked()
{
    vtkSmartPointer<vtkJPEGReader> src = vtkSmartPointer<vtkJPEGReader>::New();
    src->SetFileName((const char*)filename.toStdString().c_str());
    src->Update();
    vtkSmartPointer<vtkImageSobel2D> sobelFilter =
            vtkSmartPointer<vtkImageSobel2D>::New();
    sobelFilter->SetInputConnection(src->GetOutputPort());//包含横向和竖向边缘

        //提取X向边缘成分
    vtkSmartPointer<vtkImageExtractComponents> xSobel =
        vtkSmartPointer<vtkImageExtractComponents>::New();
    xSobel->SetComponents(0);//提取第一成分即X向梯度
    xSobel->SetInputConnection(sobelFilter->GetOutputPort());
    xSobel->Update();

    vtkSmartPointer<vtkImageMathematics> absFilter =
        vtkSmartPointer<vtkImageMathematics>::New();
    absFilter->SetOperationToAbsoluteValue();//将属性设置为绝对值模式
    absFilter->SetInputConnection(xSobel->GetOutputPort());
    absFilter->Update();

    double xRange[2];
    absFilter->GetOutput()->GetScalarRange(xRange);

    vtkSmartPointer<vtkImageShiftScale> xShiftScale =
         vtkSmartPointer<vtkImageShiftScale>::New();
    xShiftScale->SetOutputScalarTypeToUnsignedChar();//强制类型转换 方便显示
    xShiftScale->SetScale(255 / xRange[1]);//设置属性
    xShiftScale->SetInputConnection(absFilter->GetOutputPort());
    xShiftScale->Update();

        //提取Y向边缘成分
    vtkSmartPointer<vtkImageExtractComponents> ySobel =
         vtkSmartPointer<vtkImageExtractComponents>::New();
    ySobel->SetComponents(1);
    ySobel->SetInputConnection(sobelFilter->GetOutputPort());
    ySobel->Update();

    vtkSmartPointer<vtkImageMathematics> absYsobel =
         vtkSmartPointer<vtkImageMathematics>::New();
    absYsobel->SetOperationToAbsoluteValue();
    absYsobel->SetInputConnection(ySobel->GetOutputPort());
    absYsobel->Update();

    double yRange[2];
    absYsobel->GetOutput()->GetScalarRange(yRange);

    vtkSmartPointer<vtkImageShiftScale> yShiftScale =
            vtkSmartPointer<vtkImageShiftScale>::New();
    yShiftScale->SetOutputScalarTypeToUnsignedChar();
    yShiftScale->SetScale(255 / yRange[1]);
    yShiftScale->SetInputConnection(absYsobel->GetOutputPort());
    yShiftScale->Update();
        ////////////////////////////////////////////////////////////
    vtkSmartPointer<vtkImageActor> origActor =
            vtkSmartPointer<vtkImageActor>::New();
    origActor->SetInputData(src->GetOutput());

    vtkSmartPointer<vtkImageActor> xSobelActor =
         vtkSmartPointer<vtkImageActor>::New();
    xSobelActor->SetInputData(xShiftScale->GetOutput());

    vtkSmartPointer<vtkImageActor> ySobelActor =
            vtkSmartPointer<vtkImageActor>::New();
    ySobelActor->SetInputData(yShiftScale->GetOutput());
    ////////////////////////////////////////////////////////////////
    double origView[4] = { 0, 0, 0.33, 1 };
    double xSobelView[4] = { 0.33, 0, 0.66, 1 };
    double ySobelView[4] = { 0.66, 0, 1, 1 };
    vtkSmartPointer<vtkRenderer> origRender =
            vtkSmartPointer<vtkRenderer>::New();
    origRender->SetViewport(origView);
    origRender->AddActor(origActor);
    origRender->ResetCamera();
    origRender->SetBackground(1, 0, 0);

    vtkSmartPointer<vtkRenderer> xSobelRender =
            vtkSmartPointer<vtkRenderer>::New();
    xSobelRender->SetViewport(xSobelView);
    xSobelRender->AddActor(xSobelActor);
    xSobelRender->ResetCamera();
    xSobelRender->SetBackground(0, 1, 0);

    vtkSmartPointer<vtkRenderer> ySobelRender =
            vtkSmartPointer<vtkRenderer>::New();
    ySobelRender->SetViewport(ySobelView);
    ySobelRender->AddActor(ySobelActor);
    ySobelRender->ResetCamera();
    ySobelRender->SetBackground(0, 0, 1);

    ///////
    ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(origRender);
    ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(xSobelRender);
    ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(ySobelRender);
    ui->qvtkWidget_4->GetRenderWindow()->Render();
}
