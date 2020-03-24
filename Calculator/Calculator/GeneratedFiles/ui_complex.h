/********************************************************************************
** Form generated from reading UI file 'complex.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPLEX_H
#define UI_COMPLEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Complex
{
public:
    QLineEdit *lineEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *Re1;
    QLabel *label_5;
    QLineEdit *Im1;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *Re2;
    QLabel *label_6;
    QLineEdit *Im2;
    QLabel *label_3;
    QPushButton *razy;
    QPushButton *podzielic;
    QPushButton *minus;
    QPushButton *modul;
    QPushButton *plus;
    QPushButton *argument;

    void setupUi(QWidget *Complex)
    {
        if (Complex->objectName().isEmpty())
            Complex->setObjectName(QStringLiteral("Complex"));
        Complex->resize(319, 212);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Complex->sizePolicy().hasHeightForWidth());
        Complex->setSizePolicy(sizePolicy);
        Complex->setMinimumSize(QSize(319, 212));
        Complex->setMaximumSize(QSize(319, 212));
        lineEdit = new QLineEdit(Complex);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 281, 20));
        lineEdit->setReadOnly(true);
        layoutWidget = new QWidget(Complex);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 298, 52));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Re1 = new QLineEdit(layoutWidget);
        Re1->setObjectName(QStringLiteral("Re1"));

        horizontalLayout->addWidget(Re1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        Im1 = new QLineEdit(layoutWidget);
        Im1->setObjectName(QStringLiteral("Im1"));

        horizontalLayout->addWidget(Im1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Re2 = new QLineEdit(layoutWidget);
        Re2->setObjectName(QStringLiteral("Re2"));

        horizontalLayout_2->addWidget(Re2);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        Im2 = new QLineEdit(layoutWidget);
        Im2->setObjectName(QStringLiteral("Im2"));

        horizontalLayout_2->addWidget(Im2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_2);

        razy = new QPushButton(Complex);
        razy->setObjectName(QStringLiteral("razy"));
        razy->setGeometry(QRect(60, 100, 51, 51));
        podzielic = new QPushButton(Complex);
        podzielic->setObjectName(QStringLiteral("podzielic"));
        podzielic->setGeometry(QRect(110, 100, 51, 51));
        minus = new QPushButton(Complex);
        minus->setObjectName(QStringLiteral("minus"));
        minus->setGeometry(QRect(110, 150, 51, 51));
        modul = new QPushButton(Complex);
        modul->setObjectName(QStringLiteral("modul"));
        modul->setGeometry(QRect(10, 100, 51, 51));
        plus = new QPushButton(Complex);
        plus->setObjectName(QStringLiteral("plus"));
        plus->setGeometry(QRect(60, 150, 51, 51));
        argument = new QPushButton(Complex);
        argument->setObjectName(QStringLiteral("argument"));
        argument->setGeometry(QRect(10, 150, 51, 51));

        retranslateUi(Complex);

        QMetaObject::connectSlotsByName(Complex);
    } // setupUi

    void retranslateUi(QWidget *Complex)
    {
        Complex->setWindowTitle(QApplication::translate("Complex", "Complex", nullptr));
        label_5->setText(QApplication::translate("Complex", "+", nullptr));
        label_2->setText(QApplication::translate("Complex", "i", nullptr));
        label_6->setText(QApplication::translate("Complex", "+", nullptr));
        label_3->setText(QApplication::translate("Complex", "i", nullptr));
        razy->setText(QApplication::translate("Complex", "*", nullptr));
        podzielic->setText(QApplication::translate("Complex", "/", nullptr));
        minus->setText(QApplication::translate("Complex", "-", nullptr));
        modul->setText(QApplication::translate("Complex", "| |", nullptr));
        plus->setText(QApplication::translate("Complex", "+", nullptr));
        argument->setText(QApplication::translate("Complex", "\317\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Complex: public Ui_Complex {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPLEX_H
