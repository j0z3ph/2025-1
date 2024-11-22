from PyQt6 import QtGui, QtWidgets
from PyQt6.QtCore import QThread, pyqtSignal
from PyQt6.QtWidgets import QMainWindow
from Ui_imagenes import *
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
        self.horizontalSlider.valueChanged.connect(self.change_brightness)
        self.vthread = VideoThread()
        self.vthread.change_pixmap_signal.connect(self.update_image)
        # start the thread
        self.vthread.start()

    def closeEvent(self, event):
        self.vthread.stop()
        event.accept()
    
    def update_image(self, cv_img):
        cv_img = cv2.resize(cv_img, (cv_img.shape[1]//2,cv_img.shape[0]//2))
        self.cv_img = cv_img
        self.change_brightness()
        
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
