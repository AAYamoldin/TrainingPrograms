/********************************************************************************
** Form generated from reading UI file 'adding_form.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDING_FORM_H
#define UI_ADDING_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adding_form
{
public:
    QLabel *label;
    QPushButton *finish_add;
    QLineEdit *txtFIO;
    QLineEdit *txtLink;
    QPushButton *finish_cancel;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *status_label;

    void setupUi(QWidget *adding_form)
    {
        if (adding_form->objectName().isEmpty())
            adding_form->setObjectName(QStringLiteral("adding_form"));
        adding_form->resize(514, 411);
        adding_form->setAutoFillBackground(false);
        label = new QLabel(adding_form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 70, 181, 21));
        finish_add = new QPushButton(adding_form);
        finish_add->setObjectName(QStringLiteral("finish_add"));
        finish_add->setGeometry(QRect(90, 240, 171, 24));
        finish_add->setCursor(QCursor(Qt::PointingHandCursor));
        finish_add->setStyleSheet(QStringLiteral(""));
        txtFIO = new QLineEdit(adding_form);
        txtFIO->setObjectName(QStringLiteral("txtFIO"));
        txtFIO->setEnabled(true);
        txtFIO->setGeometry(QRect(90, 130, 331, 24));
        txtLink = new QLineEdit(adding_form);
        txtLink->setObjectName(QStringLiteral("txtLink"));
        txtLink->setGeometry(QRect(92, 180, 331, 24));
        finish_cancel = new QPushButton(adding_form);
        finish_cancel->setObjectName(QStringLiteral("finish_cancel"));
        finish_cancel->setEnabled(true);
        finish_cancel->setGeometry(QRect(290, 240, 131, 24));
        finish_cancel->setCursor(QCursor(Qt::PointingHandCursor));
        finish_cancel->setAutoFillBackground(true);
        label_2 = new QLabel(adding_form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 110, 58, 16));
        label_3 = new QLabel(adding_form);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 160, 121, 20));
        status_label = new QLabel(adding_form);
        status_label->setObjectName(QStringLiteral("status_label"));
        status_label->setGeometry(QRect(100, 300, 381, 41));

        retranslateUi(adding_form);

        QMetaObject::connectSlotsByName(adding_form);
    } // setupUi

    void retranslateUi(QWidget *adding_form)
    {
        adding_form->setWindowTitle(QApplication::translate("adding_form", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("adding_form", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \320\260\320\262\321\202\320\276\321\200\320\260", Q_NULLPTR));
        finish_add->setText(QApplication::translate("adding_form", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        txtFIO->setText(QString());
        txtLink->setText(QString());
        finish_cancel->setText(QApplication::translate("adding_form", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("adding_form", "\320\244\320\230\320\236", Q_NULLPTR));
        label_3->setText(QApplication::translate("adding_form", "\320\241\321\201\321\213\320\273\320\272\320\270 \320\275\320\260 \321\204\320\276\321\202\320\276", Q_NULLPTR));
        status_label->setText(QApplication::translate("adding_form", "status: \320\222 \320\276\320\266\320\270\320\264\320\260\320\275\320\270\320\270 \320\262\320\262\320\276\320\264\320\260...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class adding_form: public Ui_adding_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDING_FORM_H
