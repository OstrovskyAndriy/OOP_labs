#include "mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   connect(ui->pbOpenModalDialog, &QPushButton::clicked, this, &MainWindow::OpenModalDialog);

   connect(ui->pbOpenNotModalDialog, &QPushButton::clicked, this, &MainWindow::OpenNotModalDialog);
   connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Disconnect);

}

MainWindow::~MainWindow()
{
   delete ui;
}
void MainWindow::OpenModalDialog()
{
   QMessageBox msg;
   msg.setText("Error");
   msg.exec();
}

void MainWindow::OpenNotModalDialog()
{
   QFileDialog QFD;
   QFD.getOpenFileName();
   QFD.exec();
}
void MainWindow::Connect()
{
   ui->pushButton->setText("Відключити");
   connect(ui->pbOpenModalDialog, &QPushButton::clicked, this, &MainWindow::OpenModalDialog);
   connect(ui->pbOpenNotModalDialog, &QPushButton::clicked, this, &MainWindow::OpenNotModalDialog);

   disconnect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Connect);
   connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Disconnect);
}

void MainWindow::Disconnect()
{
   ui->pushButton->setText("Підключити");
   disconnect(ui->pbOpenModalDialog, &QPushButton::clicked, this, &MainWindow::OpenModalDialog);
   disconnect(ui->pbOpenNotModalDialog,&QPushButton::clicked,this,&MainWindow::OpenNotModalDialog);

   disconnect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Disconnect);
   connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Connect);
}
