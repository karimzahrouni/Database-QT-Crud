#include "adduser.h"
#include "ui_adduser.h"

addUser::addUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addUser)
{
    ui->setupUi(this);
}

addUser::~addUser()
{
    delete ui;
}

void addUser::on_AddUserBtn_clicked()
{

}
