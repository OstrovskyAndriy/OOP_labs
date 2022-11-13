#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_exitButton_clicked();

    void on_equal_clicked();

    void on_addTrain_clicked();

    void on_showDataButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
