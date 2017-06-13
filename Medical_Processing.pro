#-------------------------------------------------
#
# Project created by QtCreator 3017-05-34T17:57:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Medical_Processing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Histogram.cpp \
    NoiseReduction.cpp \
    ShowImage.cpp \
    Threshold.cpp \
    CannyEdgeDetection.cpp \
    Sobel.cpp \
    ErosionBinary.cpp \
    MorphologicalDistanceTransform.cpp \
    MorphologicalSkeleton.cpp \
    ErosionGrayscale.cpp \
    ClosingGrayscale.cpp \
    MorphologicalEdgeDetection.cpp \
    MorphologicalGradient.cpp \
    OpeningGrayscale.cpp \
    DilationBinary.cpp \
    OpeningBinary.cpp \
    DilationGrayscale.cpp \
    ClosingBinary.cpp \
    MorphologicalSkeletonRestoration.cpp \
    MorphologicalGrayscaleReconstruction.cpp
    #histogramwindow.cpp


HEADERS  += mainwindow.h
    #histogramwindow.h

FORMS    += mainwindow.ui
#LIBS    += -L/usr/local/lib/cmake/vtk-6.3 -lvtkCommon -lvtksys -lQVTK -lvtkQtChart -lvtkViews -lvtkWidgets -lvtkInfovis -lvtkRendering -lvtkGraphics -lvtkImaging -lvtkIO -lvtkFiltering -lvtklibxml3 -lvtkDICOMParser -lvtkpng -lvtkpng -lvtktiff -lvtkzlib -lvtkjpeg -lvtkalglib -lvtkexpat -lvtkverdict -lvtkmetaio -lvtkNetCDF -lvtksqlite -lvtkexoIIc -lvtkftgl -lvtkfreetype -lvtkHybrid


#INCLUDEPATH += /home/dongming/VTK/VTK-6.3.0/build/
#LIBS+=-L /usr/local/lib #-lvtkRendering#/home/dongming/VTK/VTK-6.3.0
#LIBS+=-L /home/dongming/VTK/VTK-6.3.0/build/lib
#LIBS+= -L /home/dongming/VTK/VKT-6.3.0/lib -lvtkCommon
 LIBS+=-L/usr/local/lib -lvtkalglib-6.3\
 -lvtkChartsCore-6.3\
 -lvtkCommonColor-6.3\
 -lvtkCommonComputationalGeometry-6.3\
 -lvtkCommonCore-6.3\
 -lvtkCommonDataModel-6.3\
 -lvtkCommonExecutionModel-6.3\
 -lvtkCommonMath-6.3\
 -lvtkCommonMisc-6.3\
 -lvtkCommonSystem-6.3\
 -lvtkCommonTransforms-6.3\
 -lvtkDICOMParser-6.3\
 -lvtkDomainsChemistry-6.3\
 -lvtkexoIIc-6.3\
 -lvtkexpat-6.3\
 -lvtkFiltersAMR-6.3\
 -lvtkFiltersCore-6.3\
 -lvtkFiltersExtraction-6.3\
 -lvtkFiltersFlowPaths-6.3\
 -lvtkFiltersGeneral-6.3\
 -lvtkFiltersGeneric-6.3\
 -lvtkFiltersGeometry-6.3\
 -lvtkFiltersHybrid-6.3\
 -lvtkFiltersHyperTree-6.3\
 -lvtkFiltersImaging-6.3\
 -lvtkFiltersModeling-6.3\
 -lvtkFiltersParallel-6.3\
 -lvtkFiltersParallelImaging-6.3\
 -lvtkFiltersProgrammable-6.3\
 -lvtkFiltersSelection-6.3\
 -lvtkFiltersSMP-6.3\
 -lvtkFiltersSources-6.3\
 -lvtkFiltersStatistics-6.3\
 -lvtkFiltersTexture-6.3\
 -lvtkFiltersVerdict-6.3\
 -lvtkfreetype-6.3\
 -lvtkftgl-6.3\
 -lvtkGeovisCore-6.3\
 #-lvtkgl3ps-6.3\
 -lvtkGUISupportQt-6.3\
 -lvtkGUISupportQtOpenGL-6.3\
 -lvtkGUISupportQtSQL-6.3\
 -lvtkGUISupportQtWebkit-6.3\
 -lvtkhdf5-6.3\
 -lvtkhdf5_hl-6.3\
 -lvtkImagingColor-6.3\
 -lvtkImagingCore-6.3\
 -lvtkImagingFourier-6.3\
 -lvtkImagingGeneral-6.3\
 -lvtkImagingHybrid-6.3\
 -lvtkImagingMath-6.3\
 -lvtkImagingMorphological-6.3\
 -lvtkImagingSources-6.3\
 -lvtkImagingStatistics-6.3\
 -lvtkImagingStencil-6.3\
 -lvtkInfovisCore-6.3\
 -lvtkInfovisLayout-6.3\
 -lvtkInteractionImage-6.3\
 -lvtkInteractionStyle-6.3\
 -lvtkInteractionWidgets-6.3\
 -lvtkIOAMR-6.3\
 -lvtkIOCore-6.3\
 -lvtkIOEnSight-6.3\
 -lvtkIOExodus-6.3\
 -lvtkIOExport-6.3\
 -lvtkIOGeometry-6.3\
 -lvtkIOImage-6.3\
 -lvtkIOImport-6.3\
 -lvtkIOInfovis-6.3\
 -lvtkIOLegacy-6.3\
 -lvtkIOLSDyna-6.3\
 -lvtkIOMINC-6.3\
 -lvtkIOMovie-6.3\
 -lvtkIONetCDF-6.3\
 -lvtkIOParallel-6.3\
 -lvtkIOParallelXML-6.3\
 -lvtkIOPLY-6.3\
 -lvtkIOSQL-6.3\
 -lvtkIOVideo-6.3\
 -lvtkIOXML-6.3\
 -lvtkIOXMLParser-6.3\
 -lvtkjpeg-6.3\
 -lvtkjsoncpp-6.3\
 #-lvtklibxml3-6.3\
 -lvtkmetaio-6.3\
 -lvtkNetCDF-6.3\
 -lvtkNetCDF_cxx-6.3\
 -lvtkoggtheora-6.3\
 -lvtkParallelCore-6.3\
 -lvtkpng-6.3\
 -lvtkproj4-6.3\
 -lvtkRenderingAnnotation-6.3\
 -lvtkRenderingContext2D-6.3\
 -lvtkRenderingContextOpenGL-6.3\
 -lvtkRenderingCore-6.3\
 -lvtkRenderingFreeType-6.3\
 -lvtkRenderingOpenGL-6.3\
 #-lvtkRenderingFreeTypeOpenGL-6.3\
 -lvtkRenderingGL2PS-6.3\
 -lvtkRenderingImage-6.3\
 -lvtkRenderingLabel-6.3\
 -lvtkRenderingLIC-6.3\
 -lvtkRenderingLOD-6.3\
 -lvtkRenderingOpenGL-6.3\
 -lvtkRenderingQt-6.3\
 -lvtkRenderingVolume-6.3\
 -lvtkRenderingVolumeOpenGL-6.3\
 -lvtksqlite-6.3\
 -lvtksys-6.3\
 -lvtktiff-6.3\
 -lvtkverdict-6.3\
 -lvtkViewsContext2D-6.3\
 -lvtkViewsCore-6.3\
 -lvtkViewsInfovis-6.3\
 -lvtkViewsQt-6.3\
 -lvtkzlib-6.3\
# -lvtkCommon-6.3\
# -lvktRendering-6.3\

#LIBS+=-L/usr/local/lib/cmake/vtk-6.3 -lvtkCommon -lvtksys -lQVTK -lvtkQtChart -lvtkViews -lvtkWidgets -lvtkInfovis -lvtkRendering -lvtkGraphics -lvtkImaging -lvtkIO -lvtkFiltering -lvtklibxml3 -lvtkDICOMParser -lvtkpng -lvtkpng -lvtktiff -lvtkzlib -lvtkjpeg -lvtkalglib -lvtkexpat -lvtkverdict -lvtkmetaio -lvtkNetCDF -lvtksqlite -lvtkexoIIc -lvtkftgl -lvtkfreetype -lvtkHybr
#CONFIG(debug, debug|release){

#}
LIBS+=-L /usr/local/lib -lITKBiasCorrection-4.12\
 -lITKBioCell-4.12\
 -lITKCommon-4.12\
 -lITKDICOMParser-4.12\
 -lITKEXPAT-4.12\
 -lITKFEM-4.12\
 -lITKgiftiio-4.12\
 -lITKIOBioRad-4.12\
 -lITKIOBMP-4.12\
 -lITKIOCSV-4.12\
 -lITKIOGDCM-4.12\
 -lITKIOGE-4.12\
 -lITKIOGIPL-4.12\
 -lITKIOHDF5-4.12\
 -lITKIOImageBase-4.12\
 -lITKIOIPL-4.12\
 -lITKIOJPEG-4.12\
 -lITKIOLSM-4.12\
 -lITKIOMesh-4.12\
 -lITKIOMeta-4.12\
 -lITKIOMRC-4.12\
 -lITKIONIFTI-4.12\
 -lITKIONRRD-4.12\
 -lITKIOPNG-4.12\
 -lITKIOSiemens-4.12\
 -lITKIOSpatialObjects-4.12\
 -lITKIOStimulate-4.12\
 -lITKIOTIFF-4.12\
 -lITKIOTransformBase-4.12\
 -lITKIOTransformHDF5-4.12\
 -lITKIOTransformInsightLegacy-4.12\
 -lITKIOTransformMatlab-4.12\
 -lITKIOVTK-4.12\
 -lITKIOXML-4.12\
 -lITKKLMRegionGrowing-4.12\
 -lITKLabelMap-4.12\
 -lITKMesh-4.12\
 -lITKMetaIO-4.12\
 -lITKniftiio-4.12\
 -lITKNrrdIO-4.12\
 -lITKOptimizers-4.12\
 -lITKOptimizersv4-4.12\
 -lITKPath-4.12\
 -lITKPolynomials-4.12\
 -lITKQuadEdgeMesh-4.12\
 -lITKSpatialObjects-4.12\
 -lITKStatistics-4.12\
 -lITKVideoCore-4.12\
 -lITKVideoIO-4.12\
 -lITKVNLInstantiation-4.12\
 -lITKVTK-4.12\
 #-lITKVtkGlue-4.12\
 -lITKWatersheds-4.12\
 -lITKznz-4.12\
 -litksys-4.12\
 -litkvnl-4.12 \
 -litkvnl_algo-4.12
#LIBS +=-lGLU
#LIBS += -Xlinker --trace
INCLUDEPATH += /usr/local/include/vtk-6.3
INCLUDEPATH += /usr/local/include/ITK-4.12
