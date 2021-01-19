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
#include <QtWidgets/QTableView>
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
    QLabel *label_3;
    QLineEdit *find_personages;
    QLabel *label_4;
    QLineEdit *lineEdit_date;
    QTableView *tableView;

    void setupUi(QWidget *findForm)
    {
        if (findForm->objectName().isEmpty())
            findForm->setObjectName(QStringLiteral("findForm"));
        findForm->resize(548, 427);
        label = new QLabel(findForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 20, 441, 20));
        label_2 = new QLabel(findForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 40, 58, 16));
        find_text = new QLineEdit(findForm);
        find_text->setObjectName(QStringLiteral("find_text"));
        find_text->setGeometry(QRect(140, 60, 261, 24));
        find_text->setContextMenuPolicy(Qt::PreventContextMenu);
        find_find = new QPushButton(findForm);
        find_find->setObjectName(QStringLiteral("find_find"));
        find_find->setGeometry(QRect(140, 210, 80, 24));
        find_close = new QPushButton(findForm);
        find_close->setObjectName(QStringLiteral("find_close"));
        find_close->setGeometry(QRect(320, 210, 80, 24));
        status_find = new QLabel(findForm);
        status_find->setObjectName(QStringLiteral("status_find"));
        status_find->setGeometry(QRect(50, 240, 461, 151));
        status_find->setTextFormat(Qt::PlainText);
        status_find->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3 = new QLabel(findForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 90, 58, 16));
        find_personages = new QLineEdit(findForm);
        find_personages->setObjectName(QStringLiteral("find_personages"));
        find_personages->setGeometry(QRect(140, 150, 261, 24));
        label_4 = new QLabel(findForm);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(230, 130, 81, 20));
        lineEdit_date = new QLineEdit(findForm);
        lineEdit_date->setObjectName(QStringLiteral("lineEdit_date"));
        lineEdit_date->setGeometry(QRect(140, 110, 261, 24));
        tableView = new QTableView(findForm);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(25, 241, 511, 181));

        retranslateUi(findForm);

        QMetaObject::connectSlotsByName(findForm);
    } // setupUi

    void retranslateUi(QWidget *findForm)
    {
        findForm->setWindowTitle(QApplication::translate("findForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("findForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\205\320\276\321\202\321\217 \320\261\321\213 \320\276\320\264\320\270\320\275 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200, \320\277\320\276 \320\272\320\276\321\202\320\276\321\200\320\276\320\274\321\203 \320\276\321\201\321\203\321\211\320\265\321\201\321\202\320\262\320\273\321\217\321\202\321\214 \320\277\320\276\320\270\321\201\320\272", Q_NULLPTR));
        label_2->setText(QApplication::translate("findForm", "\320\220\320\262\321\202\320\276\321\200", Q_NULLPTR));
        find_find->setText(QApplication::translate("findForm", "\320\235\320\260\320\271\321\202\320\270", Q_NULLPTR));
        find_close->setText(QApplication::translate("findForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", Q_NULLPTR));
        status_find->setText(QApplication::translate("findForm", "Status ....", Q_NULLPTR));
        label_3->setText(QApplication::translate("findForm", "\320\224\320\260\321\202\320\260", Q_NULLPTR));
        label_4->setText(QApplication::translate("findForm", "\320\237\320\265\321\200\321\201\320\276\320\275\320\260\320\266\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class findForm: public Ui_findForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFORM_H
