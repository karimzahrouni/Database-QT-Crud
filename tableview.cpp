#include "tableview.h"
#include "tableview.h"
#include "ui_tableview.h"

tableview::tableview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tableview)
{
    ui->setupUi(this);

    // Create a new model
    // QStandardItemModel(int rows, int columns, QObject * parent = 0)
    model = new QStandardItemModel(4,2,this);

    // Attach the model to the view
    ui->tableView->setModel(model);

    // Generate data
    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 2; col++)
        {
            QModelIndex index
                    = model->index(row,col,QModelIndex());
            // 0 for all data
            model->setData(index,0);
        }
    }
}

tableview::~DelegateTableViewDialog()
{
    delete ui;
}
