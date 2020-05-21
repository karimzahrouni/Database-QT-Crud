#include "inserdata.h"
#include "ui_inserdata.h"
#include "mainwindow.h"

inserData::inserData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inserData)
{
    ui->setupUi(this);
}

inserData::~inserData()
{
    delete ui;
}

void inserData::on_pushButton_clicked()
{
    QString name = ui->textEdit->toPlainText();
    QString pass = ui->textEdit_2->text();

    MainWindow m ;
    m.InsertData(name,pass);

}
