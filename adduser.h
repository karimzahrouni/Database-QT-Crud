#ifndef ADDUSER_H
#define ADDUSER_H

#include <QWidget>

namespace Ui {
class addUser;
}

class addUser : public QWidget
{
    Q_OBJECT

public:
    explicit addUser(QWidget *parent = nullptr);
    ~addUser();

private slots:
    void on_AddUserBtn_clicked();

private:
    Ui::addUser *ui;
};

#endif // ADDUSER_H
