#ifndef tableview_H
#define tableview_H

#include <QDialog>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>

namespace Ui {
class tableview;
}

class tableview : public QDialog
{
    Q_OBJECT

public:
    explicit tableview(QWidget *parent = 0);
    ~tableview();

private:
    Ui::tableview *ui;

    // QStandardItemModel provides a classic
    // item-based approach to working with the model.
    QStandardItemModel *model;
};

#endif // DELEGATETABLEVIEWDIALOG_H
