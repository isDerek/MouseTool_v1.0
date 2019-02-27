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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
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
    QGroupBox *getDriverModeGroup;
    QVBoxLayout *verticalLayout_7;
    QPushButton *getCurrentDeviceModeBtn;
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
    QPushButton *mouseBtn;
    QPushButton *configBtn;
    QGroupBox *mouseStatus;
    QLabel *currentPowerText;
    QLabel *currentLEDText;
    QLabel *currentDPIText;
    QLabel *macroKey1Text;
    QLabel *macroKey2Text;
    QLabel *missDeviceLabel;
    QGroupBox *marcroKeyGroup;
    QPushButton *setMacroKey1Btn;
    QPushButton *setMacroKey2Btn;
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
        getDriverModeGroup = new QGroupBox(centralWidget);
        getDriverModeGroup->setObjectName(QString::fromUtf8("getDriverModeGroup"));
        getDriverModeGroup->setGeometry(QRect(170, 450, 176, 120));
        getDriverModeGroup->setMaximumSize(QSize(16777215, 120));
        verticalLayout_7 = new QVBoxLayout(getDriverModeGroup);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        getCurrentDeviceModeBtn = new QPushButton(getDriverModeGroup);
        getCurrentDeviceModeBtn->setObjectName(QString::fromUtf8("getCurrentDeviceModeBtn"));

        verticalLayout_7->addWidget(getCurrentDeviceModeBtn);

        setDriverModeGroup = new QGroupBox(centralWidget);
        setDriverModeGroup->setObjectName(QString::fromUtf8("setDriverModeGroup"));
        setDriverModeGroup->setGeometry(QRect(10, 450, 150, 100));
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
        currentDPIGroup->setGeometry(QRect(660, 150, 150, 300));
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
        currentLEDGroup->setGeometry(QRect(840, 150, 150, 300));
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
        mouseBtn = new QPushButton(centralWidget);
        mouseBtn->setObjectName(QString::fromUtf8("mouseBtn"));
        mouseBtn->setGeometry(QRect(350, 320, 241, 331));
        configBtn = new QPushButton(centralWidget);
        configBtn->setObjectName(QString::fromUtf8("configBtn"));
        configBtn->setGeometry(QRect(850, 50, 51, 41));
        mouseStatus = new QGroupBox(centralWidget);
        mouseStatus->setObjectName(QString::fromUtf8("mouseStatus"));
        mouseStatus->setGeometry(QRect(30, 150, 241, 281));
        currentPowerText = new QLabel(mouseStatus);
        currentPowerText->setObjectName(QString::fromUtf8("currentPowerText"));
        currentPowerText->setGeometry(QRect(20, 40, 72, 15));
        currentLEDText = new QLabel(mouseStatus);
        currentLEDText->setObjectName(QString::fromUtf8("currentLEDText"));
        currentLEDText->setGeometry(QRect(20, 80, 72, 15));
        currentDPIText = new QLabel(mouseStatus);
        currentDPIText->setObjectName(QString::fromUtf8("currentDPIText"));
        currentDPIText->setGeometry(QRect(20, 120, 81, 16));
        macroKey1Text = new QLabel(mouseStatus);
        macroKey1Text->setObjectName(QString::fromUtf8("macroKey1Text"));
        macroKey1Text->setGeometry(QRect(20, 159, 71, 21));
        macroKey2Text = new QLabel(mouseStatus);
        macroKey2Text->setObjectName(QString::fromUtf8("macroKey2Text"));
        macroKey2Text->setGeometry(QRect(20, 195, 72, 20));
        missDeviceLabel = new QLabel(centralWidget);
        missDeviceLabel->setObjectName(QString::fromUtf8("missDeviceLabel"));
        missDeviceLabel->setGeometry(QRect(330, 330, 351, 111));
        missDeviceLabel->setAlignment(Qt::AlignCenter);
        marcroKeyGroup = new QGroupBox(centralWidget);
        marcroKeyGroup->setObjectName(QString::fromUtf8("marcroKeyGroup"));
        marcroKeyGroup->setGeometry(QRect(840, 470, 150, 110));
        marcroKeyGroup->setMinimumSize(QSize(150, 110));
        marcroKeyGroup->setMaximumSize(QSize(150, 110));
        setMacroKey1Btn = new QPushButton(marcroKeyGroup);
        setMacroKey1Btn->setObjectName(QString::fromUtf8("setMacroKey1Btn"));
        setMacroKey1Btn->setGeometry(QRect(20, 30, 99, 28));
        setMacroKey2Btn = new QPushButton(marcroKeyGroup);
        setMacroKey2Btn->setObjectName(QString::fromUtf8("setMacroKey2Btn"));
        setMacroKey2Btn->setGeometry(QRect(20, 70, 99, 28));
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
        getDriverModeGroup->setTitle(QApplication::translate("MouseConfigTool", "\350\216\267\345\217\226\345\275\223\345\211\215 Driver \346\250\241\345\274\217", nullptr));
        getCurrentDeviceModeBtn->setText(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215\346\250\241\345\274\217", nullptr));
        setDriverModeGroup->setTitle(QApplication::translate("MouseConfigTool", "\350\256\276\347\275\256 Driver \346\250\241\345\274\217", nullptr));
        setConfigModeBtn->setText(QApplication::translate("MouseConfigTool", "\351\205\215\347\275\256\346\250\241\345\274\217", nullptr));
        setNormalModeBtn->setText(QApplication::translate("MouseConfigTool", "\346\255\243\345\270\270\346\250\241\345\274\217", nullptr));
        currentDPIGroup->setTitle(QApplication::translate("MouseConfigTool", "\350\256\276\347\275\256 DPI", nullptr));
        DPIMode1Btn->setText(QApplication::translate("MouseConfigTool", "400", nullptr));
        DPIMode2Btn->setText(QApplication::translate("MouseConfigTool", "800", nullptr));
        DPIMode3Btn->setText(QApplication::translate("MouseConfigTool", "1600", nullptr));
        DPIMode4Btn->setText(QApplication::translate("MouseConfigTool", "4000", nullptr));
        currentLEDGroup->setTitle(QApplication::translate("MouseConfigTool", "\350\256\276\347\275\256\347\201\257\346\225\210", nullptr));
        RGBMode4Btn->setText(QApplication::translate("MouseConfigTool", "\350\267\221\351\251\254\347\201\257", nullptr));
        RGBMode3Btn->setText(QApplication::translate("MouseConfigTool", "\345\221\274\345\220\270\347\201\257", nullptr));
        RGBMode2Btn->setText(QApplication::translate("MouseConfigTool", "\345\276\252\347\216\257\347\201\257", nullptr));
        RGBMode1Btn->setText(QApplication::translate("MouseConfigTool", "\346\227\240\347\201\257\346\225\210", nullptr));
        wpiLogo->setText(QString());
        closeBtn->setText(QString());
        mouseBtn->setText(QString());
        configBtn->setText(QString());
        mouseStatus->setTitle(QApplication::translate("MouseConfigTool", "\351\274\240\346\240\207\347\212\266\346\200\201", nullptr));
        currentPowerText->setText(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215\347\224\265\351\207\217\357\274\232", nullptr));
        currentLEDText->setText(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215\347\201\257\346\225\210\357\274\232", nullptr));
        currentDPIText->setText(QApplication::translate("MouseConfigTool", "\345\275\223\345\211\215 DPI\357\274\232", nullptr));
        macroKey1Text->setText(QApplication::translate("MouseConfigTool", "\344\276\247\351\224\256\344\270\200\357\274\232", nullptr));
        macroKey2Text->setText(QApplication::translate("MouseConfigTool", "\344\276\247\351\224\256\344\272\214\357\274\232", nullptr));
        missDeviceLabel->setText(QApplication::translate("MouseConfigTool", "\346\234\252\346\211\276\345\210\260\346\214\207\345\256\232\350\256\276\345\244\207", nullptr));
        marcroKeyGroup->setTitle(QApplication::translate("MouseConfigTool", "\350\256\276\347\275\256\346\214\211\351\224\256\345\256\217", nullptr));
        setMacroKey1Btn->setText(QApplication::translate("MouseConfigTool", "\344\276\247\351\224\256\344\270\200\346\214\211\351\224\256\345\256\217", nullptr));
        setMacroKey2Btn->setText(QApplication::translate("MouseConfigTool", "\344\276\247\351\224\256\344\272\214\346\214\211\351\224\256\345\256\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MouseConfigTool: public Ui_MouseConfigTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUSECONFIGTOOL_H
