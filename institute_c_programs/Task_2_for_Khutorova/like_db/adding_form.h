#ifndef ADDING_FORM_H
#define ADDING_FORM_H

#include <QWidget>

namespace Ui {
class adding_form;
}

class adding_form : public QWidget
{
    Q_OBJECT

public:
    explicit adding_form(QWidget *parent = nullptr);
    ~adding_form();

private slots:
    void on_finish_cancel_clicked();

    void on_finish_add_clicked();

    void on_pushButton_clicked();

    void on_photo_path_clicked();

    void on_photo_path_buton_clicked();

private:
    Ui::adding_form *ui;
};

#endif // ADDING_FORM_H
