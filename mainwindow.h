#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include "QFileDialog"
#include "qstring.h"
#include "qfiledialog.h"
#include "qmessagebox.h"
#include <QFileDialog>
#include <QString>
#include <QLabel>
#include <vtkDataObjectToTable.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkQtTableView.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkSmartPointer.h>
#include <itkAbsImageAdaptor.h>
#include <vtkDataSetMapper.h>
#include <vtkImageData.h>
#include <vtkImageReader.h>
#include <vtkActor2D.h>
#include <vtkMapper2D.h>
#include <vtkImageMapper.h>
#include <vtkJPEGReader.h>
#include <vtkImageActor.h>
#include <vtkBMPReader.h>
//#include "histogramwindow.h"

#include "itkRGBAPixel.h"
#include "itkImageToHistogramFilter.h"
#include "itkImageRandomIteratorWithIndex.h"
#include "itkImage.h"
#include "itkRGBAPixel.h"
#include "itkImageToHistogramFilter.h"
#include "itkImageRandomIteratorWithIndex.h"

#include <vtkSmartPointer.h>
#include <string>
#include <vtkActor.h>
#include <vtkImageAccumulate.h>
#include <vtkImageExtractComponents.h>
#include <vtkJPEGReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkXYPlotActor.h>
#include <vtkRenderer.h>

//Threshold
#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkImageThreshold.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkImageMapper3D.h>
#include <vtkImageActor.h>
#include <vtkImageCast.h>
#include <vtkImageMandelbrotSource.h>

//sobel
#include <vtkSmartPointer.h>
#include <vtkJPEGReader.h>
#include <vtkImageSobel2D.h>
#include <vtkImageExtractComponents.h>
#include <vtkImageMathematics.h>
#include <vtkImageData.h>
#include <vtkImageShiftScale.h>
#include <vtkImageActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>

//edge detection: CannyEdgeDetector
#include <vtkVersion.h>
#include <vtkRenderer.h>
#include <vtkImageActor.h>
#include <vtkStructuredPoints.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPNGReader.h>
#include <vtkImageLuminance.h>
#include <vtkProperty.h>
#include <vtkImageGaussianSmooth.h>
#include <vtkImageCast.h>
#include <vtkImageGradient.h>
#include <vtkImageMagnitude.h>
#include <vtkImageNonMaximumSuppression.h>
#include <vtkImageConstantPad.h>
#include <vtkImageToStructuredPoints.h>
#include <vtkLinkEdgels.h>
#include <vtkThreshold.h>
#include <vtkGeometryFilter.h>
#include <vtkSubPixelPositionEdgels.h>
#include <vtkStripper.h>
#include <vtkPolyDataMapper.h>
#include <vtkCamera.h>

//Noise Reduction
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkBinaryMedianImageFilter.h"
#include <itkImageToVTKImageFilter.h>
#include <itkDiscreteGaussianImageFilter.h>

//Dilation
#include "itkImage.h"
#include "itkBinaryDilateImageFilter.h"
#include "itkImageFileReader.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkGrayscaleDilateImageFilter.h"

//Erosion
#include "itkImage.h"
#include "itkBinaryErodeImageFilter.h"
#include "itkImageFileReader.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkGrayscaleErodeImageFilter.h"

//Opening
#include "itkImage.h"
#include "itkBinaryMorphologicalOpeningImageFilter.h"
#include "itkImageFileReader.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkSubtractImageFilter.h"

//Closing
#include "itkImage.h"
#include "itkBinaryMorphologicalClosingImageFilter.h"
#include "itkImageFileReader.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkSubtractImageFilter.h"

//Morphological distance transform
#include "itkMorphologicalDistanceTransformImageFilter.h"
#include <vtkImageData.h>
#include <vtkImageMapper3D.h>
#include <vtkImageCast.h>
#include <vtkImageThreshold.h>
#include <vtkJPEGReader.h>
#include <vtkPNGReader.h>
#include <vtkSmartPointer.h>
#include <vtkImageExtractComponents.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkJPEGReader.h>
#include <vtkImageActor.h>
#include <vtkImageCityBlockDistance.h>
#include "itkApproximateSignedDistanceMapImageFilter.h"

//Morphological skeleton
#include <vtkImageSkeleton2D.h>
#include "itkBinaryThinningImageFilter.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkRescaleIntensityImageFilter.h"

//Binary Dilation on grayscale
#include "itkImage.h"
#include "itkGrayscaleDilateImageFilter.h"
#include "itkImageFileReader.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkSubtractImageFilter.h"


//Binary Erosion on grayscale
#include "itkImage.h"
#include "itkGrayscaleErodeImageFilter.h"
#include "itkImageFileReader.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkSubtractImageFilter.h"
#include "itksys/SystemTools.hxx"

//Opening on grayscale
#include <itkGrayscaleConnectedOpeningImageFilter.h>

//Closing on grayscael
#include <itkGrayscaleConnectedClosingImageFilter.h>


//Morphological Grayscale reconstruction
#include <itkBinaryReconstructionByErosionImageFilter.h>
#include <itkReconstructionByErosionImageFilter.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString filename;
    int histSize[1];
    float hranges[2];
    const float* ranges[1];
    int channel[1];

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
  virtual void slotExit();
    
private slots:
    void OnShowImageCliked();
    void OnShowHistogramClicked();
    void OnShowThresholdClicked();
    void OnShowSobelClicked();
    void OnShowCannyEdgeDetectorClicked();
    void OnShowNoiseReductionClicked();
    void OnShowDilationBinaryClicked();
    void OnShowErosionBinaryClicked();
    void OnShowOpeningBinaryClicked();
    void OnShowClosingBinaryClicked();
    void OnShowMorphologicalDistanceTransformClicked();
    void OnShowMorphologicalSkeletonClicked();
    void OnShowDilationGrayscaleClicked();
    void OnShowErosionGrayscaleClicked();
    void OnShowOpeningGrayscaleClicked();
    void OnShowClosingGrayscaleClicked();
    void OnShowMorphologicalEdgeDetectionClicked();
    void OnShowMorphologicalGradientClicked();
    void OnShowMorphologicalSkeletonRestorationClicked();
    void OnShowMorphologicalGrayscaleReconstructionClicked();


private:
    Ui::MainWindow *ui;
    //Histogramwindow hist;
};



#endif // MAINWINDOW_H
