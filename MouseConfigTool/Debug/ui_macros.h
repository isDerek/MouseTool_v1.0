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
#include <QtWidgets/QPushButton>
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
    QWidget *tab_2;
    QTextEdit *keyText;
    QCheckBox *recordHandlerTmr;
    QPushButton *startRecordBtn;

    void setupUi(QWidget *Macros)
    {
        if (Macros->objectName().isEmpty())
            Macros->setObjectName(QString::fromUtf8("Macros"));
        Macros->resize(421, 402);
        confirmBtn = new QPushButton(Macros);
        confirmBtn->setObjectName(QString::fromUtf8("confirmBtn"));
        confirmBtn->setGeometry(QRect(200, 360, 93, 28));
        cancelBtn = new QPushButton(Macros);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(310, 360, 93, 28));
        keyFuc = new QTabWidget(Macros);
        keyFuc->setObjectName(QString::fromUtf8("keyFuc"));
        keyFuc->setGeometry(QRect(0, 10, 411, 341));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        keyFuc->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        keyFuc->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        keyText = new QTextEdit(tab_2);
        keyText->setObjectName(QString::fromUtf8("keyText"));
        keyText->setGeometry(QRect(0, 0, 221, 311));
        recordHandlerTmr = new QCheckBox(tab_2);
        recordHandlerTmr->setObjectName(QString::fromUtf8("recordHandlerTmr"));
        recordHandlerTmr->setGeometry(QRect(230, 10, 171, 19));
        startRecordBtn = new QPushButton(tab_2);
        startRecordBtn->setObjectName(QString::fromUtf8("startRecordBtn"));
        startRecordBtn->setGeometry(QRect(230, 40, 93, 28));
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
