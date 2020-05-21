#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include "inserdata.h"
#include "deleteuser.h"

static const QString path="/home/zahrouni/appDb/exemple.db";
DbManager dbM(path);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    dbM.createTable();
    ui->setupUi(this);
    qDebug()<<"UpdateButton";
     QSqlTableModel *model = new QSqlTableModel(this);
     model->setTable("login");
     model->select();
     ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::InsertData(QString name , QString pass){

    dbM.addUser(name,pass);
}

void MainWindow::DeleteUser(QString name){
    dbM.removeUsername(name);
}

void MainWindow::on_insertButton_clicked()
{
   qDebug()<<"insertButton";

    //MainWindow::close();
    inserData *newT = 0 ;
    newT = new inserData();
    newT->show();

}



void MainWindow::on_UpdateButton_clicked()
{
    qDebug()<<"UpdateButton";
     QSqlTableModel *model = new QSqlTableModel(this);
     model->setTable("login");
     model->select();
     ui->tableView->setModel(model);
     ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_DeleteAllButton_clicked()
{
     qDebug()<<"DeleteAllButton";
     QMessageBox msgBox;
     msgBox.setText("Do you want to remove All Users?");
     msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
     int ret = msgBox.exec();
     switch (ret) {
       case QMessageBox::Ok:
           dbM.removeAllUsers();
           break;
       case QMessageBox::Cancel:
           // Cancel was clicked
           break;
       default:
           // should never be reached
           break;
     }
}

void MainWindow::on_DeleteButton_clicked()
{
    qDebug()<<"DeleteButton";

    deleteuser *newT = 0 ;
    newT = new deleteuser();
    newT->show();

}
