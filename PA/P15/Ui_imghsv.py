# Form implementation generated from reading ui file 'c:\Progs\python\imghsv.ui'
#
# Created by: PyQt6 UI code generator 6.4.2
#
# WARNING: Any manual changes made to this file will be lost when pyuic6 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt6 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(610, 396)
        self.centralwidget = QtWidgets.QWidget(parent=MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.gridLayout = QtWidgets.QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName("gridLayout")
        self.minSSlider = QtWidgets.QSlider(parent=self.centralwidget)
        self.minSSlider.setMaximum(255)
        self.minSSlider.setOrientation(QtCore.Qt.Orientation.Horizontal)
        self.minSSlider.setTickPosition(QtWidgets.QSlider.TickPosition.TicksBelow)
        self.minSSlider.setTickInterval(10)
        self.minSSlider.setObjectName("minSSlider")
        self.gridLayout.addWidget(self.minSSlider, 2, 1, 1, 1)
        self.label_3 = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_3.setObjectName("label_3")
        self.gridLayout.addWidget(self.label_3, 3, 0, 1, 1)
        self.label = QtWidgets.QLabel(parent=self.centralwidget)
        self.label.setObjectName("label")
        self.gridLayout.addWidget(self.label, 1, 0, 1, 1)
        self.minVSlider = QtWidgets.QSlider(parent=self.centralwidget)
        self.minVSlider.setMaximum(255)
        self.minVSlider.setOrientation(QtCore.Qt.Orientation.Horizontal)
        self.minVSlider.setTickPosition(QtWidgets.QSlider.TickPosition.TicksBelow)
        self.minVSlider.setTickInterval(10)
        self.minVSlider.setObjectName("minVSlider")
        self.gridLayout.addWidget(self.minVSlider, 3, 1, 1, 1)
        self.minHSlider = QtWidgets.QSlider(parent=self.centralwidget)
        self.minHSlider.setMinimum(0)
        self.minHSlider.setMaximum(179)
        self.minHSlider.setOrientation(QtCore.Qt.Orientation.Horizontal)
        self.minHSlider.setTickPosition(QtWidgets.QSlider.TickPosition.TicksBelow)
        self.minHSlider.setTickInterval(10)
        self.minHSlider.setObjectName("minHSlider")
        self.gridLayout.addWidget(self.minHSlider, 1, 1, 1, 1)
        self.label_4 = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_4.setObjectName("label_4")
        self.gridLayout.addWidget(self.label_4, 1, 2, 1, 1)
        self.label_2 = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_2.setObjectName("label_2")
        self.gridLayout.addWidget(self.label_2, 2, 0, 1, 1)
        self.maxHSlider = QtWidgets.QSlider(parent=self.centralwidget)
        self.maxHSlider.setMaximum(179)
        self.maxHSlider.setProperty("value", 179)
        self.maxHSlider.setOrientation(QtCore.Qt.Orientation.Horizontal)
        self.maxHSlider.setTickPosition(QtWidgets.QSlider.TickPosition.TicksBelow)
        self.maxHSlider.setTickInterval(10)
        self.maxHSlider.setObjectName("maxHSlider")
        self.gridLayout.addWidget(self.maxHSlider, 1, 3, 1, 1)
        self.lbl_image = QtWidgets.QLabel(parent=self.centralwidget)
        self.lbl_image.setFrameShape(QtWidgets.QFrame.Shape.Box)
        self.lbl_image.setText("")
        self.lbl_image.setObjectName("lbl_image")
        self.gridLayout.addWidget(self.lbl_image, 0, 0, 1, 4)
        self.label_5 = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_5.setObjectName("label_5")
        self.gridLayout.addWidget(self.label_5, 2, 2, 1, 1)
        self.label_6 = QtWidgets.QLabel(parent=self.centralwidget)
        self.label_6.setObjectName("label_6")
        self.gridLayout.addWidget(self.label_6, 3, 2, 1, 1)
        self.maxSSlider = QtWidgets.QSlider(parent=self.centralwidget)
        self.maxSSlider.setMaximum(255)
        self.maxSSlider.setProperty("value", 255)
        self.maxSSlider.setOrientation(QtCore.Qt.Orientation.Horizontal)
        self.maxSSlider.setTickPosition(QtWidgets.QSlider.TickPosition.TicksBelow)
        self.maxSSlider.setObjectName("maxSSlider")
        self.gridLayout.addWidget(self.maxSSlider, 2, 3, 1, 1)
        self.maxVSlider = QtWidgets.QSlider(parent=self.centralwidget)
        self.maxVSlider.setMaximum(255)
        self.maxVSlider.setProperty("value", 255)
        self.maxVSlider.setOrientation(QtCore.Qt.Orientation.Horizontal)
        self.maxVSlider.setTickPosition(QtWidgets.QSlider.TickPosition.TicksBelow)
        self.maxVSlider.setObjectName("maxVSlider")
        self.gridLayout.addWidget(self.maxVSlider, 3, 3, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Imagen"))
        self.label_3.setText(_translate("MainWindow", "Min Value"))
        self.label.setText(_translate("MainWindow", "Min Hue"))
        self.label_4.setText(_translate("MainWindow", "Max Hue"))
        self.label_2.setText(_translate("MainWindow", "Min Saturation"))
        self.label_5.setText(_translate("MainWindow", "Max Saturation"))
        self.label_6.setText(_translate("MainWindow", "Max Value"))
