from PyQt6 import QtGui, QtWidgets
from PyQt6.QtCore import QThread, pyqtSignal
from PyQt6.QtWidgets import QMainWindow
from Ui_imghsv import *
import numpy as np
import cv2
import sys

class VideoThread(QThread):
    change_pixmap_signal = pyqtSignal(np.ndarray)

    def __init__(self):
        super().__init__()
        self._run_flag = True

    def run(self):
        cap = cv2.VideoCapture(0)
        if not cap.isOpened():
            print("Cannot open camera")
        else:
            while self._run_flag:
                ret, cv_img = cap.read()
                if ret:
                    self.change_pixmap_signal.emit(cv_img)
        cap.release()

    def stop(self):
        self._run_flag = False
        self.wait()


class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        # Sliders
        self.minHSlider.valueChanged.connect(self.setHSV)
        self.minSSlider.valueChanged.connect(self.setHSV)
        self.minVSlider.valueChanged.connect(self.setHSV)
        self.maxHSlider.valueChanged.connect(self.setHSV)
        self.maxSSlider.valueChanged.connect(self.setHSV)
        self.maxVSlider.valueChanged.connect(self.setHSV)
        
        # Thread
        self.vthread = VideoThread()
        self.vthread.change_pixmap_signal.connect(self.update_image)
        # start the thread
        self.vthread.start()

    def closeEvent(self, event):
        self.vthread.stop()
        event.accept()
    
    def update_image(self, cv_img):
        self.cv_img = cv_img
        self.cv_img = cv2.resize(self.cv_img, np.array([self.cv_img.shape[1]//2, self.cv_img.shape[0]//2]))
        self.setHSV()
      
    def setHSV(self):
        result = self.cv_img.copy()
        image = cv2.cvtColor(self.cv_img, cv2.COLOR_BGR2HSV) 
        minH = self.minHSlider.value()
        minS = self.minSSlider.value()
        minV = self.minVSlider.value()
        maxH = self.maxHSlider.value()
        maxS = self.maxSSlider.value()
        maxV = self.maxVSlider.value()
        
        lower = np.array([minH, minS, minV])
        upper = np.array([maxH, maxS, maxV])
        
        mask = cv2.inRange(image, lower, upper)
        #kernel = cv2.getStructuringElement(cv2.MORPH_CROSS, (7,7))
        #mask = cv2.erode(mask, kernel)
        #mask = cv2.dilate(mask, kernel)
        
        result = cv2.bitwise_and(result, result, mask=mask)
        qt_img = self.convert_cv_qt(result)
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
