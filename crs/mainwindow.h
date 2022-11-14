#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase> // бібліотека бази даних
#include <QDebug> //бібліотека для відладки програми
#include <QSqlQuery> // бібліотека для запиту до баз даних
#include <QSqlTableModel> // для відображення таблиць
#include <QtSql>


#include <QStringList>
#include <QFileDialog>
#include <QFileInfo>

//#include <QMediaPlayer>
//#include <QMediaPlayList>



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
    void on_Add_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;



};
#endif // MAINWINDOW_H
