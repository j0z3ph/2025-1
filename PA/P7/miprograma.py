from PyQt6.QtCore import Qt
from Ui_princess import *
from Ui_dialogo import *
from PyQt6.QtWidgets import QMainWindow, QDialog, QWidget, QTableWidgetItem
import sys

class MiDialogo(QDialog, Ui_Dialog):
    def __init__(self, parent: None) -> None:
        super().__init__(parent)
        self.setupUi(self)

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *parent, **flags) -> None:
        super().__init__(*parent, **flags)
        self.setupUi(self)
        self.actionSalir.triggered.connect(self.salir)
        self.actionAbrir.triggered.connect(self.dialoga)
        self.comboBox.addItem("Uno")
        self.comboBox.addItem("Dos")
        self.comboBox.addItem("Tres")
        self.comboBox.addItem("Cuatro")
        self.comboBox.currentIndexChanged.connect(self.selector)
    
    def selector(self, idx):
        self.tableWidget.setRowCount(1)
        self.tableWidget.setItem(0,0, QTableWidgetItem(str(idx)))
        self.tableWidget.setItem(0,1, QTableWidgetItem(self.comboBox.itemText(idx)))
        
    
    def dialoga(self):
        instancia = MiDialogo(self)
        resp = instancia.exec()
        if(resp == 1):
            print(instancia.lineEdit.text())
    
    def salir(self):
        self.close()
        
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())
    