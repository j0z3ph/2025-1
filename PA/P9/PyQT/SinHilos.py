from PyQt6.QtWidgets import QMainWindow
from Ui_Hilos import *
import sys
import time

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)
        self.setWindowTitle("Sin Hilos")
        self.pushButton.clicked.connect(self.cuentaHasta100)
        
    def cuentaHasta100(self):
        cont = 0
        for _ in range(100):
            cont += 1
            time.sleep(0.1)
            self.lcdNumber.display(cont)
            self.progressBar.setValue(cont)
            

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
