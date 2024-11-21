from PyQt6 import QtGui, QtCore, QtWidgets
from PyQt6.QtWidgets import QMainWindow
from Ui_imagenes import *
import numpy as np
import cv2
import sys


class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        self.cv_img = cv2.imread('amlove.jpg')
        qt_img = self.convert_cv_qt(self.cv_img)
        self.lbl_image.setPixmap(qt_img)
        
        self.horizontalSlider.valueChanged.connect(self.change_brightness)
        
    def change_brightness(self):
        newval = np.array([self.horizontalSlider.value()])
        newimg = np.clip(self.cv_img + newval, 0, 255).astype("uint8")
        qt_img = self.convert_cv_qt(newimg)
        self.lbl_image.setPixmap(qt_img)
        
        
    def convert_cv_qt(self, cv_img):
        """Convert from an opencv image to QPixmap"""
        rgb_image = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB)
        h, w, ch = rgb_image.shape
        bytes_per_line = ch * w
        converted_image = QtGui.QImage(rgb_image.data, w, h, bytes_per_line, QtGui.QImage.Format.Format_RGB888)
        return QtGui.QPixmap.fromImage(converted_image)

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
