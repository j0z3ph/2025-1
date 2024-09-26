from PyQt6.QtGui import QKeyEvent
import PyQt6.QtCore
from Ui_lacalculadora import *
from PyQt6.QtWidgets import QMainWindow
import sys

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, *parent, **flags) -> None:
        super().__init__(*parent, **flags)
        self.setupUi(self)
        self.btn_1.clicked.connect(self.numero)
        self.btn_2.clicked.connect(self.numero)
        self.btn_3.clicked.connect(self.numero)
        self.btn_4.clicked.connect(self.numero)
        self.btn_5.clicked.connect(self.numero)
        self.btn_6.clicked.connect(self.numero)
        self.btn_7.clicked.connect(self.numero)
        self.btn_8.clicked.connect(self.numero)
        self.btn_9.clicked.connect(self.numero)
        self.btn_0.clicked.connect(self.numero)
        self.btn_punto.clicked.connect(self.punto)
        self.btn_AC.clicked.connect(self.borrar)
        
        
    def keyPressEvent(self, key: QKeyEvent) -> None:
        super().keyPressEvent(key)
        print(key.key())
        if(key.key() >= 48 and key.key() <= 57):
            self.numeros(key.key()-48)
        if(key.key() == 46):
            self.punto()
        
        pos = self.pos()
        if(key.key() == QtCore.Qt.Key.Key_Left):
            pos.setX(pos.x() - 10)
        
        if(key.key() == QtCore.Qt.Key.Key_Right):
            pos.setX(pos.x() + 10)
        
        if(key.key() == QtCore.Qt.Key.Key_Up):
            pos.setY(pos.y() - 10)
        
        if(key.key() == QtCore.Qt.Key.Key_Down):
            pos.setY(pos.y() + 10)
        
        self.move(pos)
        
    
    def borrar(self):
        self.lcd.setText("0")
        
    def punto(self):
        if(self.lcd.text().find(".") == -1):
            self.lcd.setText(self.lcd.text() + ".")
        
    def numero(self):
        if(self.lcd.text() == "0"):
            self.lcd.setText(self.sender().text())
        else:
            self.lcd.setText(self.lcd.text() + self.sender().text())
    
    def numeros(self, numero: int):
        if(self.lcd.text() == "0"):
            self.lcd.setText(str(numero))
        else:
            self.lcd.setText(self.lcd.text() + str(numero))
            
    
if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainWindow()
    print(eval("2+3"))
    window.show()
    sys.exit(app.exec())
    