/********************************************************************************
** Form generated from reading UI file 'findform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDFORM_H
#define UI_FINDFORM_H

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

class Ui_findForm
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *find_text;
    QPushButton *find_find;
    QPushButton *find_close;
    QLabel *status_find;
    QPushButton *see_photo;

    void setupUi(QWidget *findForm)
    {
        if (findForm->objectName().isEmpty())
            findForm->setObjectName(QStringLiteral("findForm"));
        findForm->resize(548, 427);
        label = new QLabel(findForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(147, 110, 271, 20));
        label_2 = new QLabel(findForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 140, 58, 16));
        find_text = new QLineEdit(findForm);
        find_text->setObjectName(QStringLiteral("find_text"));
        find_text->setGeometry(QRect(150, 160, 191, 24));
        find_text->setContextMenuPolicy(Qt::PreventContextMenu);
        find_find = new QPushButton(findForm);
        find_find->setObjectName(QStringLiteral("find_find"));
        find_find->setGeometry(QRect(150, 200, 80, 24));
        find_close = new QPushButton(findForm);
        find_close->setObjectName(QStringLiteral("find_close"));
        find_close->setGeometry(QRect(260, 200, 80, 24));
        status_find = new QLabel(findForm);
        status_find->setObjectName(QStringLiteral("status_find"));
        status_find->setGeometry(QRect(70, 250, 461, 151));
        status_find->setTextFormat(Qt::PlainText);
        status_find->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        see_photo = new QPushButton(findForm);
        see_photo->setObjectName(QStringLiteral("see_photo"));
        see_photo->setGeometry(QRect(220, 280, 121, 24));

        retranslateUi(findForm);

        QMetaObject::connectSlotsByName(findForm);
    } // setupUi

    void retranslateUi(QWidget *findForm)
    {
        findForm->setWindowTitle(QApplication::translate("findForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("findForm", "\320\244\320\276\321\202\320\276 \320\272\320\260\320\272\320\276\320\263\320\276 \320\260\320\262\321\202\320\276\321\200\320\260 \320\222\321\213 \320\261\321\213 \321\205\320\276\321\202\320\265\320\273\320\270 \320\275\320\260\320\271\321\202\320\270?", Q_NULLPTR));
        label_2->setText(QApplication::translate("findForm", "\320\244\320\230\320\236", Q_NULLPTR));
        find_find->setText(QApplication::translate("findForm", "\320\235\320\260\320\271\321\202\320\270", Q_NULLPTR));
        find_close->setText(QApplication::translate("findForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", Q_NULLPTR));
        status_find->setText(QString());
        see_photo->setText(QApplication::translate("findForm", "\320\241\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\204\320\276\321\202\320\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class findForm: public Ui_findForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFORM_H
