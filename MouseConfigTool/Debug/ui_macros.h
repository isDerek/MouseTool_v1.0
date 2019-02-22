/********************************************************************************
** Form generated from reading UI file 'macros.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MACROS_H
#define UI_MACROS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Macros
{
public:
    QPushButton *confirmBtn;
    QPushButton *cancelBtn;
    QTabWidget *keyFuc;
    QWidget *tab;
    QWidget *tab_3;
    QRadioButton *closeWindowsBtn;
    QRadioButton *showWindowsBtn;
    QRadioButton *nextWebBtn;
    QRadioButton *beforeWebBtn;
    QRadioButton *resetScaleBtn;
    QRadioButton *cutBtn;
    QRadioButton *copyBtn;
    QRadioButton *pasteBtn;
    QRadioButton *resetBtn;
    QLineEdit *showKeyText;
    QLabel *label;
    QWidget *tab_2;
    QTextEdit *keyText;
    QCheckBox *recordHandlerTmr;
    QPushButton *startRecordBtn;

    void setupUi(QWidget *Macros)
    {
        if (Macros->objectName().isEmpty())
            Macros->setObjectName(QString::fromUtf8("Macros"));
        Macros->resize(450, 400);
        confirmBtn = new QPushButton(Macros);
        confirmBtn->setObjectName(QString::fromUtf8("confirmBtn"));
        confirmBtn->setGeometry(QRect(200, 360, 93, 28));
        cancelBtn = new QPushButton(Macros);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(310, 360, 93, 28));
        keyFuc = new QTabWidget(Macros);
        keyFuc->setObjectName(QString::fromUtf8("keyFuc"));
        keyFuc->setGeometry(QRect(-10, 0, 465, 351));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        keyFuc->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        closeWindowsBtn = new QRadioButton(tab_3);
        closeWindowsBtn->setObjectName(QString::fromUtf8("closeWindowsBtn"));
        closeWindowsBtn->setGeometry(QRect(40, 49, 261, 20));
        showWindowsBtn = new QRadioButton(tab_3);
        showWindowsBtn->setObjectName(QString::fromUtf8("showWindowsBtn"));
        showWindowsBtn->setGeometry(QRect(40, 80, 301, 19));
        nextWebBtn = new QRadioButton(tab_3);
        nextWebBtn->setObjectName(QString::fromUtf8("nextWebBtn"));
        nextWebBtn->setGeometry(QRect(40, 110, 301, 19));
        beforeWebBtn = new QRadioButton(tab_3);
        beforeWebBtn->setObjectName(QString::fromUtf8("beforeWebBtn"));
        beforeWebBtn->setGeometry(QRect(40, 140, 341, 19));
        resetScaleBtn = new QRadioButton(tab_3);
        resetScaleBtn->setObjectName(QString::fromUtf8("resetScaleBtn"));
        resetScaleBtn->setGeometry(QRect(40, 170, 291, 19));
        cutBtn = new QRadioButton(tab_3);
        cutBtn->setObjectName(QString::fromUtf8("cutBtn"));
        cutBtn->setGeometry(QRect(40, 200, 291, 19));
        copyBtn = new QRadioButton(tab_3);
        copyBtn->setObjectName(QString::fromUtf8("copyBtn"));
        copyBtn->setGeometry(QRect(40, 230, 291, 19));
        pasteBtn = new QRadioButton(tab_3);
        pasteBtn->setObjectName(QString::fromUtf8("pasteBtn"));
        pasteBtn->setGeometry(QRect(40, 260, 291, 19));
        resetBtn = new QRadioButton(tab_3);
        resetBtn->setObjectName(QString::fromUtf8("resetBtn"));
        resetBtn->setGeometry(QRect(40, 290, 291, 19));
        showKeyText = new QLineEdit(tab_3);
        showKeyText->setObjectName(QString::fromUtf8("showKeyText"));
        showKeyText->setGeometry(QRect(140, 10, 191, 31));
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 91, 31));
        keyFuc->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        keyText = new QTextEdit(tab_2);
        keyText->setObjectName(QString::fromUtf8("keyText"));
        keyText->setGeometry(QRect(20, 10, 221, 311));
        recordHandlerTmr = new QCheckBox(tab_2);
        recordHandlerTmr->setObjectName(QString::fromUtf8("recordHandlerTmr"));
        recordHandlerTmr->setGeometry(QRect(260, 10, 171, 19));
        startRecordBtn = new QPushButton(tab_2);
        startRecordBtn->setObjectName(QString::fromUtf8("startRecordBtn"));
        startRecordBtn->setGeometry(QRect(260, 40, 93, 28));
        keyFuc->addTab(tab_2, QString());

        retranslateUi(Macros);

        keyFuc->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Macros);
    } // setupUi

    void retranslateUi(QWidget *Macros)
    {
        Macros->setWindowTitle(QApplication::translate("Macros", "Form", nullptr));
        confirmBtn->setText(QApplication::translate("Macros", "\347\241\256\345\256\232", nullptr));
        cancelBtn->setText(QApplication::translate("Macros", "\345\217\226\346\266\210", nullptr));
        keyFuc->setTabText(keyFuc->indexOf(tab), QApplication::translate("Macros", "\351\274\240\346\240\207\345\212\237\350\203\275", nullptr));
        closeWindowsBtn->setText(QApplication::translate("Macros", "\345\205\263\351\227\255\347\252\227\345\217\243 (Alt + F4)", nullptr));
        showWindowsBtn->setText(QApplication::translate("Macros", "\346\230\276\347\244\272\346\241\214\351\235\242 (Windows \351\224\256 + D)", nullptr));
        nextWebBtn->setText(QApplication::translate("Macros", "\346\265\217\350\247\210\345\231\250\344\270\255\347\232\204\344\270\213\344\270\200\344\270\252\346\240\207\347\255\276 (Ctrl + Tab)", nullptr));
        beforeWebBtn->setText(QApplication::translate("Macros", "\346\265\217\350\247\210\345\231\250\344\270\255\347\232\204\344\270\212\344\270\200\344\270\252\346\240\207\347\255\276 (Ctrl + Shift + Tab)", nullptr));
        resetScaleBtn->setText(QApplication::translate("Macros", "\346\201\242\345\244\215\351\273\230\350\256\244\347\274\251\346\224\276\346\257\224\344\276\213 (Ctrl + 0)", nullptr));
        cutBtn->setText(QApplication::translate("Macros", "\345\211\252\345\210\207 (Ctrl + X)", nullptr));
        copyBtn->setText(QApplication::translate("Macros", "\345\244\215\345\210\266 (Ctrl + C)", nullptr));
        pasteBtn->setText(QApplication::translate("Macros", "\347\262\230\350\264\264 (Ctrl + V)", nullptr));
        resetBtn->setText(QApplication::translate("Macros", "\351\207\215\345\201\232 (Ctrl + Y)", nullptr));
        label->setText(QApplication::translate("Macros", "\350\256\276\345\256\232\347\232\204\346\214\211\351\224\256\357\274\232", nullptr));
        keyFuc->setTabText(keyFuc->indexOf(tab_3), QApplication::translate("Macros", "\346\214\211\351\224\256", nullptr));
        recordHandlerTmr->setText(QApplication::translate("Macros", "\350\256\260\345\275\225\344\272\213\344\273\266\344\271\213\351\227\264\347\232\204\345\273\266\350\277\237", nullptr));
        startRecordBtn->setText(QApplication::translate("Macros", "\345\274\200\345\247\213\345\275\225\345\210\266", nullptr));
        keyFuc->setTabText(keyFuc->indexOf(tab_2), QApplication::translate("Macros", "\345\244\232\346\214\211\351\224\256\345\256\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Macros: public Ui_Macros {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MACROS_H
