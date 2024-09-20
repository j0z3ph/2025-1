from Ui_ventana import *
from PyQt6.QtWidgets import QMainWindow, QMessageBox
import sys

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *parent, **flags) -> None:
        super().__init__(*parent, **flags)
        self.setupUi(self)
        self.boton.clicked.connect(self.puchado)
    
    def puchado(self):
        #print("No tan fuerte >:(") 
        QMessageBox.warning(self, "Puchado?", "No tan fuerte >:(") 
        self.label.setText("Otro Texto")
        
          
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
    