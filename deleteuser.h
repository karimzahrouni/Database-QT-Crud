#ifndef DELETEUSER_H
#define DELETEUSER_H

#include <QWidget>

namespace Ui {
class deleteuser;
}

class deleteuser : public QWidget
{
    Q_OBJECT

public:
    explicit deleteuser(QWidget *parent = nullptr);
    ~deleteuser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::deleteuser *ui;
};

#endif // DELETEUSER_H
