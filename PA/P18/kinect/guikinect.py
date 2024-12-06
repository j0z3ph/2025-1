from PyQt6 import QtGui, QtWidgets
from PyQt6.QtCore import QThread, pyqtSignal
from PyQt6.QtWidgets import QMainWindow
from Ui_WinKinect import *
from pykinect import nui
import numpy 
import cv2
import sys

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
    
    def getColorImage(self, frame):
        height, width = frame.image.height, frame.image.width  #get width and height of the images
        rgb = numpy.empty((height, width, 4), numpy.uint8)
        frame.image.copy_bits(rgb.ctypes.data)                 #copy the bit of the image to the array
        img = self.convert_cv_qt(rgb)
        self.rgbLabel.setPixmap(img)

    def getDepthImage(self, frame):
        height, width = frame.image.height, frame.image.width  #get frame height and width
        depth = numpy.empty((height, width, 1), numpy.uint8)
        arr2d = (depth >> 3) & 4095
        arr2d >>= 4
        frame.image.copy_bits(arr2d.ctypes.data)
        depth = numpy.clip(arr2d, 0, 255).astype('uint8')
        
        rgb = cv2.cvtColor(depth, cv2.COLOR_GRAY2BGR)
        img = self.convert_cv_qt(rgb)
        self.depthLabel.setPixmap(img)
                    
    def frame_ready(self, frame):
        cont = 1
        for skeleton in frame.SkeletonData:
            if skeleton.eTrackingState == nui.SkeletonTrackingState.TRACKED:
                self.skeletonLabel.setPlainText(self.skeletonLabel.toPlainText() + 
                                                f"\n{cont} - {skeleton.Position.x}, {skeleton.Position.y}, {skeleton.Position.z}")
                cont += 1
    
    def convert_cv_qt(self, cv_img):
        """Convert from an opencv image to QPixmap"""
        rgb_image = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB)
        h, w, ch = rgb_image.shape
        bytes_per_line = ch * w
        converted_image = QtGui.QImage(rgb_image.data, w, h, bytes_per_line, QtGui.QImage.Format.Format_RGB888)
        return QtGui.QPixmap.fromImage(converted_image)
            
    def closeEvent(self, event):
        kinect.close()
        event.accept()
        
        

if __name__ == "__main__":
    kinect = nui.Runtime()
    kinect.skeleton_engine.enabled = True
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    kinect.video_frame_ready += window.getColorImage
    kinect.video_stream.open(nui.ImageStreamType.Video, 2, nui.ImageResolution.Resolution640x480, nui.ImageType.Color)

    kinect.depth_frame_ready += window.getDepthImage
    kinect.depth_stream.open(nui.ImageStreamType.Depth, 2, nui.ImageResolution.Resolution640x480, nui.ImageType.Depth)

    kinect.skeleton_frame_ready += window.frame_ready

    window.show()
    sys.exit(app.exec())
