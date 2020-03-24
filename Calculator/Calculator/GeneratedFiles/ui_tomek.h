/********************************************************************************
** Form generated from reading UI file 'tomek.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOMEK_H
#define UI_TOMEK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tomek
{
public:
    QComboBox *walutaz;
    QComboBox *walutana;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_przeliczone;
    QPushButton *Przelicz;
    QPushButton *przecinek;

    void setupUi(QWidget *Tomek)
    {
        if (Tomek->objectName().isEmpty())
            Tomek->setObjectName(QStringLiteral("Tomek"));
        Tomek->resize(270, 113);
        Tomek->setMinimumSize(QSize(270, 113));
        Tomek->setMaximumSize(QSize(270, 113));
        walutaz = new QComboBox(Tomek);
        walutaz->addItem(QString());
        walutaz->addItem(QString());
        walutaz->addItem(QString());
        walutaz->addItem(QString());
        walutaz->addItem(QString());
        walutaz->setObjectName(QStringLiteral("walutaz"));
        walutaz->setGeometry(QRect(170, 50, 81, 22));
        walutana = new QComboBox(Tomek);
        walutana->addItem(QString());
        walutana->addItem(QString());
        walutana->addItem(QString());
        walutana->addItem(QString());
        walutana->addItem(QString());
        walutana->setObjectName(QStringLiteral("walutana"));
        walutana->setGeometry(QRect(170, 80, 81, 22));
        lineEdit = new QLineEdit(Tomek);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 20, 121, 20));
        lineEdit->setReadOnly(true);
        lineEdit_przeliczone = new QLineEdit(Tomek);
        lineEdit_przeliczone->setObjectName(QStringLiteral("lineEdit_przeliczone"));
        lineEdit_przeliczone->setGeometry(QRect(40, 50, 121, 20));
        lineEdit_przeliczone->setCursor(QCursor(Qt::ArrowCursor));
        lineEdit_przeliczone->setLayoutDirection(Qt::RightToLeft);
        lineEdit_przeliczone->setCursorPosition(0);
        lineEdit_przeliczone->setReadOnly(true);
        Przelicz = new QPushButton(Tomek);
        Przelicz->setObjectName(QStringLiteral("Przelicz"));
        Przelicz->setGeometry(QRect(100, 80, 61, 23));
        przecinek = new QPushButton(Tomek);
        przecinek->setObjectName(QStringLiteral("przecinek"));
        przecinek->setGeometry(QRect(170, 20, 41, 23));

        retranslateUi(Tomek);

        QMetaObject::connectSlotsByName(Tomek);
    } // setupUi

    void retranslateUi(QWidget *Tomek)
    {
        Tomek->setWindowTitle(QApplication::translate("Tomek", "Tomek", nullptr));
        walutaz->setItemText(0, QApplication::translate("Tomek", "mm", nullptr));
        walutaz->setItemText(1, QApplication::translate("Tomek", "cm", nullptr));
        walutaz->setItemText(2, QApplication::translate("Tomek", "dm", nullptr));
        walutaz->setItemText(3, QApplication::translate("Tomek", "m", nullptr));
        walutaz->setItemText(4, QApplication::translate("Tomek", "km", nullptr));

        walutana->setItemText(0, QApplication::translate("Tomek", "mm", nullptr));
        walutana->setItemText(1, QApplication::translate("Tomek", "cm", nullptr));
        walutana->setItemText(2, QApplication::translate("Tomek", "dm", nullptr));
        walutana->setItemText(3, QApplication::translate("Tomek", "m", nullptr));
        walutana->setItemText(4, QApplication::translate("Tomek", "km", nullptr));

        Przelicz->setText(QApplication::translate("Tomek", "Przelicz", nullptr));
        przecinek->setText(QApplication::translate("Tomek", "<-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tomek: public Ui_Tomek {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOMEK_H
