/********************************************************************************
** Form generated from reading UI file 'mouseconfigtool.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOUSECONFIGTOOL_H
#define UI_MOUSECONFIGTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MouseConfigTool
{
public:
    QWidget *centralWidget;
    QGroupBox *getCurrentPowerGroup;
    QPushButton *getCurrentPowerBtn;
    QLabel *currentPowerText;
    QGroupBox *usbConfigGroup;
    QLabel *label;
    QPushButton *on_offBtn;
    QComboBox *comboHIDBox;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *VIDLineEdit;
    QLineEdit *PIDLineEdit;
    QGroupBox *usbUpdateGroup;
    QGridLayout *gridLayout_4;
    QPushButton *selectHexFileBtn;
    QPushButton *updateButton;
    QLineEdit *updateHexName;
    QLabel *filePathText;
    QGroupBox *getCurrentDPIGroup;
    QVBoxLayout *verticalLayout_3;
    QPushButton *getCurrentDPIModeBtn;
    QLabel *currentDPIText;
    QGroupBox *getCurrentLEDGroup;
    QVBoxLayout *verticalLayout_6;
    QPushButton *getCurrentRGBModeBtn;
    QLabel *currentLEDText;
    QGroupBox *getDriverModeGroup;
    QVBoxLayout *verticalLayout_7;
    QPushButton *getCurrentDeviceModeBtn;
    QLabel *currentModeText;
    QGroupBox *getMacroKeyGroup;
    QGridLayout *gridLayout_5;
    QPushButton *getMultiKeyBtn;
    QLabel *marcoKey1Text;
    QLabel *marcoKey2Text;
    QGroupBox *marcroKeyGroup;
    QVBoxLayout *verticalLayout_5;
    QPushButton *setMultiKeyBtn;
    QGroupBox *setDriverModeGroup;
    QVBoxLayout *verticalLayout_8;
    QPushButton *setConfigModeBtn;
    QPushButton *setNormalModeBtn;
    QGroupBox *currentDPIGroup;
    QVBoxLayout *verticalLayout_2;
    QPushButton *DPIMode1Btn;
    QPushButton *DPIMode2Btn;
    QPushButton *DPIMode3Btn;
    QPushButton *DPIMode4Btn;
    QGroupBox *currentLEDGroup;
    QVBoxLayout *verticalLayout;
    QPushButton *RGBMode4Btn;
    QPushButton *RGBMode3Btn;
    QPushButton *RGBMode2Btn;
    QPushButton *RGBMode1Btn;
    QLabel *wpiLogo;
    QPushButton *closeBtn;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MouseConfigTool)
    {
        if (MouseConfigTool->objectName().isEmpty())
            MouseConfigTool->setObjectName(QString::fromUtf8("MouseConfigTool"));
        MouseConfigTool->resize(1000, 750);
        MouseConfigTool->setAnimated(true);
        MouseConfigTool->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MouseConfigTool);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        getCurrentPowerGroup = new QGroupBox(centralWidget);
        getCurrentPowerGroup->setObjectName(QString::fromUtf8("getCurrentPowerGroup"));
        getCurrentPowerGroup->setGeometry(QRect(410, 520, 150, 111));
        getCurrentPowerGroup->setMinimumSize(QSize(150, 0));
        getCurrentPowerGroup->setMaximumSize(QSize(150, 16777215));
        getCurrentPowerBtn = new QPushButton(getCurrentPowerGroup);
        getCurrentPowerBtn->setObjectName(QString::fromUtf8("getCurrentPowerBtn"));
        getCurrentPowerBtn->setGeometry(QRect(30, 30, 93, 28));
        currentPowerText = new QLabel(getCurrentPowerGroup);
        currentPowerText->setObjectName(QString::fromUtf8("currentPowerText"));
        currentPowerText->setGeometry(QRect(30, 70, 111, 16));
        usbConfigGroup = new QGroupBox(centralWidget);
        usbConfigGroup->setObjectName(QString::fromUtf8("usbConfigGroup"));
        usbConfigGroup->setGeometry(QRect(20, 160, 350, 200));
        usbConfigGroup->setMinimumSize(QSize(350, 200));
        usbConfigGroup->setMaximumSize(QSize(350, 200));
        label = new QLabel(usbConfigGroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 72, 21));
        on_offBtn = new QPushButton(usbConfigGroup);
        on_offBtn->setObjectName(QString::fromUtf8("on_offBtn"));
        on_offBtn->setGeometry(QRect(10, 130, 93, 28));
        comboHIDBox = new QComboBox(usbConfigGroup);
        comboHIDBox->setObjectName(QString::fromUtf8("comboHIDBox"));
        comboHIDBox->setGeometry(QRect(100, 30, 171, 22));
        label_12 = new QLabel(usbConfigGroup);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 60, 72, 21));
        label_13 = new QLabel(usbConfigGroup);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 90, 72, 21));
        VIDLineEdit = new QLineEdit(usbConfigGroup);
        VIDLineEdit->setObjectName(QString::fromUtf8("VIDLineEdit"));
        VIDLineEdit->setGeometry(QRect(100, 60, 113, 21));
        PIDLineEdit = new QLineEdit(usbConfigGroup);
        PIDLineEdit->setObjectName(QString::fromUtf8("PIDLineEdit"));
        PIDLineEdit->setGeometry(QRect(100, 90, 113, 21));
        usbUpdateGroup = new QGroupBox(centralWidget);
        usbUpdateGroup->setObjectName(QString::fromUtf8("usbUpdateGroup"));
        usbUpdateGroup->setGeometry(QRect(570, 160, 420, 102));
        usbUpdateGroup->setMinimumSize(QSize(420, 0));
        usbUpdateGroup->setMaximumSize(QSize(420, 16777215));
        usbUpdateGroup->setFlat(false);
        gridLayout_4 = new QGridLayout(usbUpdateGroup);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        selectHexFileBtn = new QPushButton(usbUpdateGroup);
        selectHexFileBtn->setObjectName(QString::fromUtf8("selectHexFileBtn"));

        gridLayout_4->addWidget(selectHexFileBtn, 0, 2, 1, 1);

        updateButton = new QPushButton(usbUpdateGroup);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));

        gridLayout_4->addWidget(updateButton, 1, 2, 1, 1);

        updateHexName = new QLineEdit(usbUpdateGroup);
        updateHexName->setObjectName(QString::fromUtf8("updateHexName"));

        gridLayout_4->addWidget(updateHexName, 0, 1, 1, 1);

        filePathText = new QLabel(usbUpdateGroup);
        filePathText->setObjectName(QString::fromUtf8("filePathText"));

        gridLayout_4->addWidget(filePathText, 0, 0, 1, 1);

        getCurrentDPIGroup = new QGroupBox(centralWidget);
        getCurrentDPIGroup->setObjectName(QString::fromUtf8("getCurrentDPIGroup"));
        getCurrentDPIGroup->setGeometry(QRect(340, 380, 150, 121));
        getCurrentDPIGroup->setMinimumSize(QSize(150, 0));
        getCurrentDPIGroup->setMaximumSize(QSize(150, 16777215));
        verticalLayout_3 = new QVBoxLayout(getCurrentDPIGroup);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        getCurrentDPIModeBtn = new QPushButton(getCurrentDPIGroup);
        getCurrentDPIModeBtn->setObjectName(QString::fromUtf8("getCurrentDPIModeBtn"));

        verticalLayout_3->addWidget(getCurrentDPIModeBtn);

        currentDPIText = new QLabel(getCurrentDPIGroup);
        currentDPIText->setObjectName(QString::fromUtf8("currentDPIText"));

        verticalLayout_3->addWidget(currentDPIText);

        getCurrentLEDGroup = new QGroupBox(centralWidget);
        getCurrentLEDGroup->setObjectName(QString::fromUtf8("getCurrentLEDGroup"));
        getCurrentLEDGroup->setGeometry(QRect(230, 510, 150, 121));
        getCurrentLEDGroup->setMinimumSize(QSize(150, 0));
        getCurrentLEDGroup->setMaximumSize(QSize(150, 16777215));
        verticalLayout_6 = new QVBoxLayout(getCurrentLEDGroup);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        getCurrentRGBModeBtn = new QPushButton(getCurrentLEDGroup);
        getCurrentRGBModeBtn->setObjectName(QString::fromUtf8("getCurrentRGBModeBtn"));

        verticalLayout_6->addWidget(getCurrentRGBModeBtn);

        currentLEDText = new QLabel(getCurrentLEDGroup);
        currentLEDText->setObjectName(QString::fromUtf8("currentLEDText"));
        currentLEDText->setMinimumSize(QSize(100, 0));

        verticalLayout_6->addWidget(currentLEDText);

        getDriverModeGroup = new QGroupBox(centralWidget);
        getDriverModeGroup->setObjectName(QString::fromUtf8("getDriverModeGroup"));
        getDriverModeGroup->setGeometry(QRect(150, 350, 176, 120));
        getDriverModeGroup->setMaximumSize(QSize(16777215, 120));
        verticalLayout_7 = new QVBoxLayout(getDriverModeGroup);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        getCurrentDeviceModeBtn = new QPushButton(getDriverModeGroup);
        getCurrentDeviceModeBtn->setObjectName(QString::fromUtf8("getCurrentDeviceModeBtn"));

        verticalLayout_7->addWidget(getCurrentDeviceModeBtn);

        currentModeText = new QLabel(getDriverModeGroup);
        currentModeText->setObjectName(QString::fromUtf8("currentModeText"));

        verticalLayout_7->addWidget(currentModeText);

        getMacroKeyGroup = new QGroupBox(centralWidget);
        getMacroKeyGroup->setObjectName(QString::fromUtf8("getMacroKeyGroup"));
        getMacroKeyGroup->setGeometry(QRect(380, 250, 150, 120));
        getMacroKeyGroup->setMinimumSize(QSize(150, 0));
        getMacroKeyGroup->setMaximumSize(QSize(150, 120));
        gridLayout_5 = new QGridLayout(getMacroKeyGroup);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        getMultiKeyBtn = new QPushButton(getMacroKeyGroup);
        getMultiKeyBtn->setObjectName(QString::fromUtf8("getMultiKeyBtn"));

        gridLayout_5->addWidget(getMultiKeyBtn, 0, 0, 1, 1);

        marcoKey1Text = new QLabel(getMacroKeyGroup);
        marcoKey1Text->setObjectName(QString::fromUtf8("marcoKey1Text"));

        gridLayout_5->addWidget(marcoKey1Text, 1, 0, 1, 1);

        marcoKey2Text = new QLabel(getMacroKeyGroup);
        marcoKey2Text->setObjectName(QString::fromUtf8("marcoKey2Text"));

        gridLayout_5->addWidget(marcoKey2Text, 2, 0, 1, 1);

        marcroKeyGroup = new QGroupBox(centralWidget);
        marcroKeyGroup->setObjectName(QString::fromUtf8("marcroKeyGroup"));
        marcroKeyGroup->setGeometry(QRect(790, 600, 200, 100));
        marcroKeyGroup->setMinimumSize(QSize(200, 100));
        marcroKeyGroup->setMaximumSize(QSize(200, 100));
        verticalLayout_5 = new QVBoxLayout(marcroKeyGroup);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        setMultiKeyBtn = new QPushButton(marcroKeyGroup);
        setMultiKeyBtn->setObjectName(QString::fromUtf8("setMultiKeyBtn"));

        verticalLayout_5->addWidget(setMultiKeyBtn);

        setDriverModeGroup = new QGroupBox(centralWidget);
        setDriverModeGroup->setObjectName(QString::fromUtf8("setDriverModeGroup"));
        setDriverModeGroup->setGeometry(QRect(380, 140, 150, 100));
        setDriverModeGroup->setMinimumSize(QSize(150, 100));
        setDriverModeGroup->setMaximumSize(QSize(150, 100));
        verticalLayout_8 = new QVBoxLayout(setDriverModeGroup);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        setConfigModeBtn = new QPushButton(setDriverModeGroup);
        setConfigModeBtn->setObjectName(QString::fromUtf8("setConfigModeBtn"));

        verticalLayout_8->addWidget(setConfigModeBtn);

        setNormalModeBtn = new QPushButton(setDriverModeGroup);
        setNormalModeBtn->setObjectName(QString::fromUtf8("setNormalModeBtn"));

        verticalLayout_8->addWidget(setNormalModeBtn);

        currentDPIGroup = new QGroupBox(centralWidget);
        currentDPIGroup->setObjectName(QString::fromUtf8("currentDPIGroup"));
        currentDPIGroup->setGeometry(QRect(660, 280, 150, 300));
        currentDPIGroup->setMinimumSize(QSize(150, 300));
        currentDPIGroup->setMaximumSize(QSize(150, 300));
        verticalLayout_2 = new QVBoxLayout(currentDPIGroup);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        DPIMode1Btn = new QPushButton(currentDPIGroup);
        DPIMode1Btn->setObjectName(QString::fromUtf8("DPIMode1Btn"));

        verticalLayout_2->addWidget(DPIMode1Btn);

        DPIMode2Btn = new QPushButton(currentDPIGroup);
        DPIMode2Btn->setObjectName(QString::fromUtf8("DPIMode2Btn"));

        verticalLayout_2->addWidget(DPIMode2Btn);

        DPIMode3Btn = new QPushButton(currentDPIGroup);
        DPIMode3Btn->setObjectName(QString::fromUtf8("DPIMode3Btn"));

        verticalLayout_2->addWidget(DPIMode3Btn);

        DPIMode4Btn = new QPushButton(currentDPIGroup);
        DPIMode4Btn->setObjectName(QString::fromUtf8("DPIMode4Btn"));

        verticalLayout_2->addWidget(DPIMode4Btn);

        currentLEDGroup = new QGroupBox(centralWidget);
        currentLEDGroup->setObjectName(QString::fromUtf8("currentLEDGroup"));
        currentLEDGroup->setGeometry(QRect(840, 280, 150, 300));
        currentLEDGroup->setMinimumSize(QSize(150, 300));
        currentLEDGroup->setMaximumSize(QSize(150, 300));
        verticalLayout = new QVBoxLayout(currentLEDGroup);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        RGBMode4Btn = new QPushButton(currentLEDGroup);
        RGBMode4Btn->setObjectName(QString::fromUtf8("RGBMode4Btn"));

        verticalLayout->addWidget(RGBMode4Btn);

        RGBMode3Btn = new QPushButton(currentLEDGroup);
        RGBMode3Btn->setObjectName(QString::fromUtf8("RGBMode3Btn"));

        verticalLayout->addWidget(RGBMode3Btn);

        RGBMode2Btn = new QPushButton(currentLEDGroup);
        RGBMode2Btn->setObjectName(QString::fromUtf8("RGBMode2Btn"));

        verticalLayout->addWidget(RGBMode2Btn);

        RGBMode1Btn = new QPushButton(currentLEDGroup);
        RGBMode1Btn->setObjectName(QString::fromUtf8("RGBMode1Btn"));

        verticalLayout->addWidget(RGBMode1Btn);

        wpiLogo = new QLabel(centralWidget);
        wpiLogo->setObjectName(QString::fromUtf8("wpiLogo"));
        wpiLogo->setGeometry(QRect(50, 10, 161, 121));
        wpiLogo->setStyleSheet(QString::fromUtf8(""));
        closeBtn = new QPushButton(centralWidget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(970, 10, 20, 20));
        MouseConfigTool->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MouseConfigTool);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 26));
        MouseConfigTool->setMenuBar(menuBar);

        retranslateUi(MouseConfigTool);

        QMetaObject::connectSlotsByName(MouseConfigTool);
    } // setupUi

    void retranslateUi(QMainWindow *MouseConfigTool)
    {
        MouseConfigTool->setWindowTitle(QApplication::translate("MouseConfigTool", "MouseConfigTool", nullptr));
        getCurrentPowerGroup->setTitle(QApplication::translate("MouseConfigTool", "\350\216\267\345\217\226\345\275\223\345\211\215\347\224\265\351\207\217", nullptr));
        getCurrentPowerBtn->setText(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215\347\224\265\351\207\217", nullptr));
        currentPowerText->setText(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215\347\224\265\351\207\217 Text", nullptr));
        usbConfigGroup->setTitle(QApplication::translate("MouseConfigTool", "USB \351\205\215\347\275\256", nullptr));
        label->setText(QApplication::translate("MouseConfigTool", "HID \350\256\276\345\244\207", nullptr));
        on_offBtn->setText(QApplication::translate("MouseConfigTool", "\346\211\223\345\274\200", nullptr));
        label_12->setText(QApplication::translate("MouseConfigTool", "VID\357\274\232", nullptr));
        label_13->setText(QApplication::translate("MouseConfigTool", "PID:", nullptr));
        usbUpdateGroup->setTitle(QApplication::translate("MouseConfigTool", "USB \345\215\207\347\272\247", nullptr));
        selectHexFileBtn->setText(QApplication::translate("MouseConfigTool", "\351\200\211\346\213\251\345\215\207\347\272\247\346\226\207\344\273\266", nullptr));
        updateButton->setText(QApplication::translate("MouseConfigTool", "\345\215\207\347\272\247", nullptr));
        filePathText->setText(QApplication::translate("MouseConfigTool", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        getCurrentDPIGroup->setTitle(QApplication::translate("MouseConfigTool", "\350\216\267\345\217\226\345\275\223\345\211\215 DPI", nullptr));
        getCurrentDPIModeBtn->setText(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215 DPI", nullptr));
        currentDPIText->setText(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215 DPI Text", nullptr));
        getCurrentLEDGroup->setTitle(QApplication::translate("MouseConfigTool", "\350\216\267\345\217\226\345\275\223\345\211\215\347\201\257\346\225\210", nullptr));
        getCurrentRGBModeBtn->setText(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215\347\201\257\346\225\210", nullptr));
        currentLEDText->setText(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215\347\201\257\346\225\210 Text", nullptr));
        getDriverModeGroup->setTitle(QApplication::translate("MouseConfigTool", "\350\216\267\345\217\226\345\275\223\345\211\215 Driver \346\250\241\345\274\217", nullptr));
        getCurrentDeviceModeBtn->setText(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215\346\250\241\345\274\217", nullptr));
        currentModeText->setText(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215\346\250\241\345\274\217 Text", nullptr));
        getMacroKeyGroup->setTitle(QApplication::translate("MouseConfigTool", "\350\216\267\345\217\226\346\214\211\351\224\256\345\256\217", nullptr));
        getMultiKeyBtn->setText(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215\344\276\247\351\224\256", nullptr));
        marcoKey1Text->setText(QApplication::translate("MouseConfigTool", "\344\276\247\351\224\256\344\270\200\357\274\232", nullptr));
        marcoKey2Text->setText(QApplication::translate("MouseConfigTool", "\344\276\247\351\224\256\344\272\214\357\274\232", nullptr));
        marcroKeyGroup->setTitle(QApplication::translate("MouseConfigTool", "\350\256\276\347\275\256\346\214\211\351\224\256\345\256\217", nullptr));
        setMultiKeyBtn->setText(QApplication::translate("MouseConfigTool", "\346\214\211\351\224\256\345\256\217", nullptr));
        setDriverModeGroup->setTitle(QApplication::translate("MouseConfigTool", "\350\256\276\347\275\256 Driver \346\250\241\345\274\217", nullptr));
        setConfigModeBtn->setText(QApplication::translate("MouseConfigTool", "\351\205\215\347\275\256\346\250\241\345\274\217", nullptr));
        setNormalModeBtn->setText(QApplication::translate("MouseConfigTool", "\346\255\243\345\270\270\346\250\241\345\274\217", nullptr));
        currentDPIGroup->setTitle(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215 DPI", nullptr));
        DPIMode1Btn->setText(QApplication::translate("MouseConfigTool", "400", nullptr));
        DPIMode2Btn->setText(QApplication::translate("MouseConfigTool", "800", nullptr));
        DPIMode3Btn->setText(QApplication::translate("MouseConfigTool", "1600", nullptr));
        DPIMode4Btn->setText(QApplication::translate("MouseConfigTool", "4000", nullptr));
        currentLEDGroup->setTitle(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215\347\201\257\346\225\210", nullptr));
        RGBMode4Btn->setText(QApplication::translate("MouseConfigTool", "\350\267\221\351\251\254\347\201\257", nullptr));
        RGBMode3Btn->setText(QApplication::translate("MouseConfigTool", "\345\221\274\345\220\270\347\201\257", nullptr));
        RGBMode2Btn->setText(QApplication::translate("MouseConfigTool", "\345\276\252\347\216\257\347\201\257", nullptr));
        RGBMode1Btn->setText(QApplication::translate("MouseConfigTool", "\346\227\240\347\201\257\346\225\210", nullptr));
        wpiLogo->setText(QString());
        closeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MouseConfigTool: public Ui_MouseConfigTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUSECONFIGTOOL_H
