#ifndef FINDFORM_H
#define FINDFORM_H
#include <QFile>
#include <QWidget>
#include <QDataStream>
namespace Ui {
class findForm;
}

class findForm : public QWidget
{
    Q_OBJECT

public:
    explicit findForm(QWidget *parent = nullptr);
    ~findForm();

private slots:
    void on_find_find_clicked();

    void on_find_close_clicked();

    void on_see_photo_clicked();

private:
    Ui::findForm *ui;
};

#endif // FINDFORM_H
