/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *usbUpdateGroup;
    QGridLayout *gridLayout_4;
    QLineEdit *updateHexName;
    QLabel *filePathText;
    QPushButton *updateButton;
    QPushButton *selectHexFileBtn;
    QPushButton *confirmBtn;
    QPushButton *cancelBtn;

    void setupUi(QWidget *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QString::fromUtf8("Config"));
        Config->resize(450, 400);
        Config->setMinimumSize(QSize(450, 400));
        Config->setMaximumSize(QSize(450, 400));
        tabWidget = new QTabWidget(Config);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 521, 351));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        usbUpdateGroup = new QGroupBox(tab);
        usbUpdateGroup->setObjectName(QString::fromUtf8("usbUpdateGroup"));
        usbUpdateGroup->setGeometry(QRect(10, 30, 420, 102));
        usbUpdateGroup->setMinimumSize(QSize(420, 0));
        usbUpdateGroup->setMaximumSize(QSize(420, 16777215));
        usbUpdateGroup->setFlat(false);
        gridLayout_4 = new QGridLayout(usbUpdateGroup);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        updateHexName = new QLineEdit(usbUpdateGroup);
        updateHexName->setObjectName(QString::fromUtf8("updateHexName"));

        gridLayout_4->addWidget(updateHexName, 0, 1, 1, 1);

        filePathText = new QLabel(usbUpdateGroup);
        filePathText->setObjectName(QString::fromUtf8("filePathText"));

        gridLayout_4->addWidget(filePathText, 0, 0, 1, 1);

        updateButton = new QPushButton(usbUpdateGroup);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));

        gridLayout_4->addWidget(updateButton, 1, 2, 1, 1);

        selectHexFileBtn = new QPushButton(usbUpdateGroup);
        selectHexFileBtn->setObjectName(QString::fromUtf8("selectHexFileBtn"));

        gridLayout_4->addWidget(selectHexFileBtn, 0, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        confirmBtn = new QPushButton(Config);
        confirmBtn->setObjectName(QString::fromUtf8("confirmBtn"));
        confirmBtn->setGeometry(QRect(220, 360, 93, 28));
        cancelBtn = new QPushButton(Config);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(340, 360, 93, 28));

        retranslateUi(Config);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QWidget *Config)
    {
        Config->setWindowTitle(QApplication::translate("Config", "Form", nullptr));
        usbUpdateGroup->setTitle(QApplication::translate("Config", "USB \345\215\207\347\272\247", nullptr));
        filePathText->setText(QApplication::translate("Config", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        updateButton->setText(QApplication::translate("Config", "\345\215\207\347\272\247", nullptr));
        selectHexFileBtn->setText(QApplication::translate("Config", "\351\200\211\346\213\251Hex\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Config", "\345\274\200\345\217\221\344\272\272\345\221\230", nullptr));
        confirmBtn->setText(QApplication::translate("Config", "\347\241\256\350\256\244", nullptr));
        cancelBtn->setText(QApplication::translate("Config", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
