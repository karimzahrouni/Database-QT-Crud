#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void InsertData(QString name ,QString pass);
    void DeleteUser(QString name);
    ~MainWindow();

private slots:    
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_insertButton_clicked();

    void on_UpdateButton_clicked();

    void on_DeleteAllButton_clicked();

    void on_DeleteButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
