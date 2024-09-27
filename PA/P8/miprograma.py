from Ui_untitled import *
from PyQt6.QtWidgets import QMainWindow
import sys
import time

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *parent, **flags) -> None:
        super().__init__(*parent, **flags)
        self.setupUi(self)
        self.pushButton.clicked.connect(self.LaFuncion)
        
    def LaFuncion(self):
        time.sleep(10)
        
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
    