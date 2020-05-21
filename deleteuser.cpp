#include "deleteuser.h"
#include "ui_deleteuser.h"
#include "QMessageBox"
#include "QDebug"
#include "mainwindow.h"

deleteuser::deleteuser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deleteuser)
{
    ui->setupUi(this);
}

deleteuser::~deleteuser()
{
    delete ui;
}

void deleteuser::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();

    MainWindow m ;
    qDebug()<<"Delete Button";
    QMessageBox msgBox;
    msgBox.setText("Do you want to remove "+name+" user ?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int ret = msgBox.exec();
    switch (ret) {
      case QMessageBox::Ok:
          m.DeleteUser(name);
          break;
      case QMessageBox::Cancel:
          // Cancel was clicked
          break;
      default:
          // should never be reached
          break;
    }
}
