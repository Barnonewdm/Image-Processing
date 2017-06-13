#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::OnShowImageCliked()
{
    //QString filename;
    QString jpg_str=".jpg";
    QString png_str=".png";
    QString bmp_str=".bmp";
    filename=QFileDialog::getOpenFileName(this,
                                              tr("Open image"), "",
                                              tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));

    if(filename.isEmpty())
    {
        return;
    }
    else{
        QImage* img=new QImage;
        img->load(filename);
        //image read
        //vtkSmartPointer<vtkPNGReader> imageReader_1 =
          //      vtkSmartPointer<vtkPNGReader>::New();


        //vtkSmartPointer<vtkPNGReader> imageReader_1 =
          //        vtkSmartPointer<vtkPNGReader>::New();

        vtkSmartPointer<vtkBMPReader>imageReader_3 =
                vtkSmartPointer<vtkBMPReader>::New();
        imageReader_3->SetFileName((const char*)filename.toStdString().c_str());
        imageReader_3->Update();

        vtkSmartPointer<vtkJPEGReader>imageReader_2 =
                vtkSmartPointer<vtkJPEGReader>::New();
        imageReader_2->SetFileName((const char*)filename.toStdString().c_str());
        imageReader_2->Update();

        vtkSmartPointer<vtkPNGReader> imageReader_1 =
                vtkSmartPointer<vtkPNGReader>::New();

        // imageReader_1->SetFileName((const char*)filename.toStdString().c_str());
        imageReader_1->SetFileName((const char*)filename.toStdString().c_str());
        imageReader_1->Update();


        //mapper
        vtkSmartPointer<vtkImageMapper> imageMapper_1 =
            vtkSmartPointer<vtkImageMapper>::New();

        //if(filename.right(4).compare(jpg_str)==0)
            imageMapper_1->SetInputData(imageReader_2->GetOutput());
        //else
          //  imageMapper_1->SetInputData(imageReader_1->GetOutput());
        imageMapper_1->SetColorWindow(255);
        imageMapper_1->SetColorLevel(127.5);
        //imageMapper_1->GetInput();

        //actor
        vtkSmartPointer<vtkImageActor> imageActor_1 =
        vtkSmartPointer<vtkImageActor>::New();

        //vtkSmartPointer<vtkActor2D> imageActor_1 = vtkSmartPointer<vtkActor2D>::New();
        //imageActor_1->SetMapper(imageMapper_1);
        if(filename.right(4).compare(png_str)==0)
            imageActor_1->GetMapper()->SetInputData(imageReader_1->GetOutput());
        else if(filename.right(4).compare(jpg_str)==0)
            imageActor_1->GetMapper()->SetInputData(imageReader_2->GetOutput());
        else if(filename.right(4).compare(bmp_str)==0)
            imageActor_1->GetMapper()->SetInputData(imageReader_3->GetOutput());
        //imageActor_1->SetPosition(20,20);
        //render
        vtkSmartPointer<vtkRenderer> imageRenderer_1 =
            vtkSmartPointer<vtkRenderer>::New();
        imageRenderer_1->AddActor(imageActor_1);
        imageRenderer_1->ResetCamera();
        //imageRenderer_1->SetViewPoint();
        //show

        ui->qvtkWidget_1->GetRenderWindow()->AddRenderer(imageRenderer_1);
        ui->qvtkWidget_1->GetRenderWindow()->Render();

        if(! ( img->load(filename) ) ) //加载图像
        {
                    QMessageBox::information(this,
                                             tr("打开图像失败"),
                                             tr("打开图像失败!"));
                    delete img;
                    return;
        }
    }
}
