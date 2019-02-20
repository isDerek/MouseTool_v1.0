/********************************************************************************
** Form generated from reading UI file 'macrokey.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MACROKEY_H
#define UI_MACROKEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MacroKey
{
public:
    QLabel *macroKey01Text;
    QLabel *macroKey02Text;
    QLabel *MacroKey0Text;
    QLabel *MacroKey1Text;
    QLabel *setMacroKey01Btn;
    QLabel *setMacroKey02Btn;
    QLabel *setMacroKey11Btn;
    QLabel *setMacroKey12Btn;
    QLabel *macroKey11Text;
    QLabel *macroKey12Text;
    QLabel *okLabel;
    QLabel *cancelLabel;

    void setupUi(QDialog *MacroKey)
    {
        if (MacroKey->objectName().isEmpty())
            MacroKey->setObjectName(QString::fromUtf8("MacroKey"));
        MacroKey->resize(508, 300);
        macroKey01Text = new QLabel(MacroKey);
        macroKey01Text->setObjectName(QString::fromUtf8("macroKey01Text"));
        macroKey01Text->setGeometry(QRect(140, 30, 141, 31));
        macroKey01Text->setLayoutDirection(Qt::LeftToRight);
        macroKey01Text->setAlignment(Qt::AlignCenter);
        macroKey02Text = new QLabel(MacroKey);
        macroKey02Text->setObjectName(QString::fromUtf8("macroKey02Text"));
        macroKey02Text->setGeometry(QRect(320, 30, 141, 31));
        macroKey02Text->setAlignment(Qt::AlignCenter);
        MacroKey0Text = new QLabel(MacroKey);
        MacroKey0Text->setObjectName(QString::fromUtf8("MacroKey0Text"));
        MacroKey0Text->setGeometry(QRect(20, 70, 101, 41));
        MacroKey0Text->setAlignment(Qt::AlignCenter);
        MacroKey1Text = new QLabel(MacroKey);
        MacroKey1Text->setObjectName(QString::fromUtf8("MacroKey1Text"));
        MacroKey1Text->setGeometry(QRect(20, 160, 101, 41));
        MacroKey1Text->setAlignment(Qt::AlignCenter);
        setMacroKey01Btn = new QLabel(MacroKey);
        setMacroKey01Btn->setObjectName(QString::fromUtf8("setMacroKey01Btn"));
        setMacroKey01Btn->setGeometry(QRect(140, 70, 141, 41));
        setMacroKey01Btn->setAlignment(Qt::AlignCenter);
        setMacroKey02Btn = new QLabel(MacroKey);
        setMacroKey02Btn->setObjectName(QString::fromUtf8("setMacroKey02Btn"));
        setMacroKey02Btn->setGeometry(QRect(320, 70, 141, 41));
        setMacroKey02Btn->setAlignment(Qt::AlignCenter);
        setMacroKey11Btn = new QLabel(MacroKey);
        setMacroKey11Btn->setObjectName(QString::fromUtf8("setMacroKey11Btn"));
        setMacroKey11Btn->setGeometry(QRect(140, 160, 141, 41));
        setMacroKey11Btn->setAlignment(Qt::AlignCenter);
        setMacroKey12Btn = new QLabel(MacroKey);
        setMacroKey12Btn->setObjectName(QString::fromUtf8("setMacroKey12Btn"));
        setMacroKey12Btn->setGeometry(QRect(320, 160, 141, 41));
        setMacroKey12Btn->setAlignment(Qt::AlignCenter);
        macroKey11Text = new QLabel(MacroKey);
        macroKey11Text->setObjectName(QString::fromUtf8("macroKey11Text"));
        macroKey11Text->setGeometry(QRect(140, 120, 141, 31));
        macroKey11Text->setAlignment(Qt::AlignCenter);
        macroKey12Text = new QLabel(MacroKey);
        macroKey12Text->setObjectName(QString::fromUtf8("macroKey12Text"));
        macroKey12Text->setGeometry(QRect(320, 120, 141, 31));
        macroKey12Text->setAlignment(Qt::AlignCenter);
        okLabel = new QLabel(MacroKey);
        okLabel->setObjectName(QString::fromUtf8("okLabel"));
        okLabel->setGeometry(QRect(280, 234, 72, 31));
        okLabel->setAlignment(Qt::AlignCenter);
        cancelLabel = new QLabel(MacroKey);
        cancelLabel->setObjectName(QString::fromUtf8("cancelLabel"));
        cancelLabel->setGeometry(QRect(410, 234, 72, 31));
        cancelLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(MacroKey);

        QMetaObject::connectSlotsByName(MacroKey);
    } // setupUi

    void retranslateUi(QDialog *MacroKey)
    {
        MacroKey->setWindowTitle(QApplication::translate("MacroKey", "Dialog", nullptr));
        macroKey01Text->setText(QApplication::translate("MacroKey", "\347\273\204\345\220\210\351\224\256 1 \347\254\254\344\270\200\351\241\272\344\275\215", nullptr));
        macroKey02Text->setText(QApplication::translate("MacroKey", "\347\273\204\345\220\210\351\224\256 1 \347\254\254\344\272\214\351\241\272\344\275\215", nullptr));
        MacroKey0Text->setText(QApplication::translate("MacroKey", "\344\276\247\351\224\256 1", nullptr));
        MacroKey1Text->setText(QApplication::translate("MacroKey", "\344\276\247\351\224\256 2", nullptr));
        setMacroKey01Btn->setText(QApplication::translate("MacroKey", "\347\273\204\345\220\210\351\224\256 1 \347\254\254\344\270\200\351\241\272\344\275\215", nullptr));
        setMacroKey02Btn->setText(QApplication::translate("MacroKey", "\347\273\204\345\220\210\351\224\256 1 \347\254\254\344\272\214\351\241\272\344\275\215", nullptr));
        setMacroKey11Btn->setText(QApplication::translate("MacroKey", "\347\273\204\345\220\210\351\224\256 2 \347\254\254\344\272\214\351\241\272\344\275\215", nullptr));
        setMacroKey12Btn->setText(QApplication::translate("MacroKey", "\347\273\204\345\220\210\351\224\256 2 \347\254\254\344\272\214\351\241\272\344\275\215", nullptr));
        macroKey11Text->setText(QApplication::translate("MacroKey", "\347\273\204\345\220\210\351\224\256 2 \347\254\254\344\270\200\351\241\272\344\275\215", nullptr));
        macroKey12Text->setText(QApplication::translate("MacroKey", "\347\273\204\345\220\210\351\224\256 2 \347\254\254\344\272\214\351\241\272\344\275\215", nullptr));
        okLabel->setText(QApplication::translate("MacroKey", "OK", nullptr));
        cancelLabel->setText(QApplication::translate("MacroKey", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MacroKey: public Ui_MacroKey {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MACROKEY_H
