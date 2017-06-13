#include "mainwindow.h"
#include "ui_mainwindow.h"

typedef itk::RGBPixel<unsigned char> RGBPixelType;
typedef itk::Image<RGBPixelType, 2>ImageType;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
   //this->setWindowState(Qt::WindowMaximized);
    //open image

    connect(
                ui->actionOpen_image,SIGNAL(triggered()),
                this,
                SLOT(OnShowImageCliked())
                );
    //Histogramwindow histogramwindow;
    connect(
                ui->HistogramButton,SIGNAL(clicked()),
                this, SLOT(OnShowHistogramClicked())
                );
    //Thresholding
    connect(
                ui->ThresholdingButton,SIGNAL(clicked()),
                this,SLOT(OnShowThresholdClicked())
                );
    //Thresholding slider
    connect(
                ui->thresholdingSlider,SIGNAL(valueChanged(int)),
                this, SLOT(OnShowThresholdClicked())
                );
    //Sobel
    connect(
                ui->SobelButton, SIGNAL(clicked()),
                this, SLOT(OnShowSobelClicked())
                );
    //Edge Detection
    connect(
                ui->EdgeDectectionButton,SIGNAL(clicked()),
                this,SLOT(OnShowCannyEdgeDetectorClicked())
                );
    //Noise Reduction
    connect(
                ui->NoiseReductionButton,SIGNAL(clicked()),
                this,SLOT(OnShowNoiseReductionClicked())
                );
    //connect(
      //          ui->radiusSlider,SIGNAL(valueChanged(int)),
        //        this,SLOT(OnShowNoiseReductionClicked())
          //      );
    //Dilation
    connect(
                ui->DilationpushButton, SIGNAL(clicked()),
                this, SLOT(OnShowDilationBinaryClicked())
                );
    //connect(
      //          ui->radiusSlider,SIGNAL(valueChanged(int)),
        //        this,SLOT(OnShowDilationClicked())
          //      );
    //Erosion
    connect(
                ui->ErosionpushButton,SIGNAL(clicked()),
                this, SLOT(OnShowErosionBinaryClicked())
                );
    //connect(
      //          ui->radiusSlider,SIGNAL(valueChanged(int)),
        //        this,SLOT(OnShowErosionClicked())
          //      );
    //opening and closing(Morphological operation)
    connect(
                ui->OpenpushButton,SIGNAL(clicked()),
                this,SLOT(OnShowOpeningBinaryClicked())
                );
    //connect(
      //          ui->radiusSlider,SIGNAL(valueChanged(int)),
        //        this,SLOT(OnShowOpeningClicked())
          //      );

    connect(
                ui->ClosingpushButton,SIGNAL(clicked()),
                this,SLOT(OnShowClosingBinaryClicked())
                );
    //connect(
      //          ui->radiusSlider,SIGNAL(valueChanged(int)),
        //        this,SLOT(OnShowClosingClicked())
          //      );
    //Morphological city distance transform
    connect(
                ui->MorphologicalDistancepushButton,SIGNAL(clicked()),
                this,SLOT(OnShowMorphologicalDistanceTransformClicked())
                );
    //Morphological skeleton
    connect(
                ui->MorphologicalSkeletonpushButton,SIGNAL(clicked()),
                this,SLOT(OnShowMorphologicalSkeletonClicked())
                );
    //Binary Dilation on grayscale
    connect(
                ui->DilationGraypushButton,SIGNAL(clicked()),
                this,SLOT(OnShowDilationGrayscaleClicked())
                );
  //  connect(
    //            ui->radiusSlider,SIGNAL(valueChanged(int)),
      //          this,SLOT(OnShowDilationGrayscaleClicked())
        //        );
    //Binary Erosion on grayscale
    connect(
                ui->ErosionGraypushButton,SIGNAL(clicked()),
                this,SLOT(OnShowErosionGrayscaleClicked())
                );
    //connect(
      //          ui->radiusSlider,SIGNAL(valueChanged(int)),
        //        this,SLOT(OnShowErosionGrayscaleClicked())
          //      );
    //Opening on grayscale
    connect(
                ui->OpenGraypushButton,SIGNAL(clicked()),
                this,SLOT(OnShowOpeningGrayscaleClicked())
                );
    //connect(
      //          ui->radiusSlider,SIGNAL(valueChanged(int)),
        //        this,SLOT(OnShowOpeningGrayscaleClicked())
          //      );
    //Closing on grayscale
    connect(
                ui->CloseGraypushButton,SIGNAL(clicked()),
                this,SLOT(OnShowClosingGrayscaleClicked())
                );
    //connect(
      //          ui->radiusSlider,SIGNAL(valueChanged(int)),
        //        this,SLOT(OnShowClosingGrayscaleClicked())
          //      );
    //Morphological edge detection
    connect(
                ui->MorphEdgeDetectionpushButton,SIGNAL(clicked()),
                this,SLOT(OnShowMorphologicalEdgeDetectionClicked())
                );
    //connect(
      //          ui->radiusSlider,SIGNAL(valueChanged(int)),
        //        this,SLOT(OnShowMorphologicalEdgeDetectionClicked())
          //      );
    //Morphological Gradient
    connect(
                ui->MorphGradientpushButton,SIGNAL(clicked()),
                this,SLOT(OnShowMorphologicalGradientClicked())
                );
    //connect(
      //          ui->radiusSlider,SIGNAL(valueChanged(int)),
        //        this,SLOT(OnShowMorphologicalGradientClicked())
          //      );
    //Morphological skeleton restoration
    connect(
                ui->MorphologicalSkeletonRestorationpushButton,SIGNAL(clicked()),
                this,SLOT(OnShowMorphologicalSkeletonRestorationClicked())
            );
    //Morphological Grayscale Reconstruction
    connect(
                ui->MorphReconstructionpushButton,SIGNAL(clicked()),
                this,SLOT(OnShowMorphologicalGrayscaleReconstructionClicked())
                );
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotExit()
{
  qApp->exit();
}



















