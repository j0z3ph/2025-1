# Form implementation generated from reading ui file '/Users/j0z3ph/Repos/2025-1/PA/P6/lacalculadora.ui'
#
# Created by: PyQt6 UI code generator 6.4.2
#
# WARNING: Any manual changes made to this file will be lost when pyuic6 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt6 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(356, 235)
        self.centralwidget = QtWidgets.QWidget(parent=MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.gridLayout = QtWidgets.QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName("gridLayout")
        self.btn_2 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.btn_2.setObjectName("btn_2")
        self.gridLayout.addWidget(self.btn_2, 4, 1, 1, 1)
        self.btn_0 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.btn_0.setObjectName("btn_0")
        self.gridLayout.addWidget(self.btn_0, 5, 0, 1, 2)
        self.btn_AC = QtWidgets.QPushButton(parent=self.centralwidget)
        self.btn_AC.setMinimumSize(QtCore.QSize(0, 0))
        self.btn_AC.setObjectName("btn_AC")
        self.gridLayout.addWidget(self.btn_AC, 1, 0, 1, 1)
        self.pushButton_7 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.pushButton_7.setObjectName("pushButton_7")
        self.gridLayout.addWidget(self.pushButton_7, 2, 3, 1, 1)
        self.btn_3 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.btn_3.setObjectName("btn_3")
        self.gridLayout.addWidget(self.btn_3, 4, 2, 1, 1)
        self.btn_punto = QtWidgets.QPushButton(parent=self.centralwidget)
        self.btn_punto.setObjectName("btn_punto")
        self.gridLayout.addWidget(self.btn_punto, 5, 2, 1, 1)
        self.btn_5 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.btn_5.setObjectName("btn_5")
        self.gridLayout.addWidget(self.btn_5, 3, 1, 1, 1)
        self.btn_6 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.btn_6.setObjectName("btn_6")
        self.gridLayout.addWidget(self.btn_6, 3, 2, 1, 1)
        self.btn_9 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.btn_9.setObjectName("btn_9")
        self.gridLayout.addWidget(self.btn_9, 2, 2, 1, 1)
        self.pushButton_4 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.pushButton_4.setObjectName("pushButton_4")
        self.gridLayout.addWidget(self.pushButton_4, 1, 3, 1, 1)
        self.btn_7 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.btn_7.setObjectName("btn_7")
        self.gridLayout.addWidget(self.btn_7, 2, 0, 1, 1)
        self.btn_1 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.btn_1.setObjectName("btn_1")
        self.gridLayout.addWidget(self.btn_1, 4, 0, 1, 1)
        self.lcd = QtWidgets.QLabel(parent=self.centralwidget)
        font = QtGui.QFont()
        font.setFamily("Comic Sans MS")
        font.setPointSize(36)
        self.lcd.setFont(font)
        self.lcd.setAlignment(QtCore.Qt.AlignmentFlag.AlignRight|QtCore.Qt.AlignmentFlag.AlignTrailing|QtCore.Qt.AlignmentFlag.AlignVCenter)
        self.lcd.setObjectName("lcd")
        self.gridLayout.addWidget(self.lcd, 0, 0, 1, 4)
        self.pushButton_11 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.pushButton_11.setObjectName("pushButton_11")
        self.gridLayout.addWidget(self.pushButton_11, 3, 3, 1, 1)
        self.btn_8 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.btn_8.setObjectName("btn_8")
        self.gridLayout.addWidget(self.btn_8, 2, 1, 1, 1)
        self.pushButton_2 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.pushButton_2.setObjectName("pushButton_2")
        self.gridLayout.addWidget(self.pushButton_2, 1, 1, 1, 1)
        self.pushButton_3 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.pushButton_3.setObjectName("pushButton_3")
        self.gridLayout.addWidget(self.pushButton_3, 1, 2, 1, 1)
        self.pushButton_15 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.pushButton_15.setObjectName("pushButton_15")
        self.gridLayout.addWidget(self.pushButton_15, 4, 3, 1, 1)
        self.pushButton_19 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.pushButton_19.setObjectName("pushButton_19")
        self.gridLayout.addWidget(self.pushButton_19, 5, 3, 1, 1)
        self.btn_4 = QtWidgets.QPushButton(parent=self.centralwidget)
        self.btn_4.setObjectName("btn_4")
        self.gridLayout.addWidget(self.btn_4, 3, 0, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "La Calculadora"))
        self.btn_2.setText(_translate("MainWindow", "2"))
        self.btn_0.setText(_translate("MainWindow", "0"))
        self.btn_AC.setText(_translate("MainWindow", "AC"))
        self.pushButton_7.setText(_translate("MainWindow", "x"))
        self.btn_3.setText(_translate("MainWindow", "3"))
        self.btn_punto.setText(_translate("MainWindow", "."))
        self.btn_5.setText(_translate("MainWindow", "5"))
        self.btn_6.setText(_translate("MainWindow", "6"))
        self.btn_9.setText(_translate("MainWindow", "9"))
        self.pushButton_4.setText(_translate("MainWindow", "/"))
        self.btn_7.setText(_translate("MainWindow", "7"))
        self.btn_1.setText(_translate("MainWindow", "1"))
        self.lcd.setText(_translate("MainWindow", "0"))
        self.pushButton_11.setText(_translate("MainWindow", "-"))
        self.btn_8.setText(_translate("MainWindow", "8"))
        self.pushButton_2.setText(_translate("MainWindow", "+/-"))
        self.pushButton_3.setText(_translate("MainWindow", "%"))
        self.pushButton_15.setText(_translate("MainWindow", "+"))
        self.pushButton_19.setText(_translate("MainWindow", "="))
        self.btn_4.setText(_translate("MainWindow", "4"))
