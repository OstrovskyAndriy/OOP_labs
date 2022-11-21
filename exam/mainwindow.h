#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QtSql>
#include <QMessageBox>

#include"student2.h"

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
    void on_add_clicked();

    void on_delete_2_clicked();

    void on_tableStudents_clicked(const QModelIndex &index);

    void setColumnsSize();

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    QTableView *viev;
    QMessageBox * error;

    Student2* student;


    int row;
};
#endif // MAINWINDOW_H
