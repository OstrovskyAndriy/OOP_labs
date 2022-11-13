#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "train.h"

const int SIZE=10;
Train *trains[SIZE];
int countOfTrains=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < countOfTrains; ++i) {
        delete trains[i];
    }
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText(ui->lineEdit->text());
}


void MainWindow::on_equal_clicked()
{
    float first=ui->value1->text().toFloat();
    float second=ui->value2->text().toFloat();
    //float result =ui->value2->text().toFloat();

    ui->result->setText(QString::number(first+second));
}


void MainWindow::on_exitButton_clicked()
{
    QApplication::exit();
}



void MainWindow::on_addTrain_clicked()
{
    if(countOfTrains==SIZE){
        ui->showDataLabel->setText("so many traints");
        QApplication::exit();
    }

    QString destination=ui->destination->text(); //встановлюю куди їде поїзд

    QString dateAndMonth=ui->dateEdit->date().toString("dd.MM.yyyy"); //приведення типів з дати в стрінг

    QString departureTime=ui->timeEdit->time().toString("hh.mm");

    int trainNumber=ui->trainNumber->text().toInt();

    trains[countOfTrains]=new Train( destination,trainNumber, departureTime, dateAndMonth);
    countOfTrains++;

    ui->destination->setText("");

    ui->trainNumber->setText("");

}

void MainWindow::on_showDataButton_clicked()
{
    for (int i = 0; i < countOfTrains; ++i) {
        ui->showDataLabel->setText(trains[i]->getInfo());
    }
}

