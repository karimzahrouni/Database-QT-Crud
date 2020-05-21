#ifndef INSERDATA_H
#define INSERDATA_H

#include <QWidget>

namespace Ui {
class inserData;
}

class inserData : public QWidget
{
    Q_OBJECT

public:
    explicit inserData(QWidget *parent = nullptr);
    ~inserData();

private slots:
    void on_pushButton_clicked();

private:
    Ui::inserData *ui;
};

#endif // INSERDATA_H
