#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db=QSqlDatabase::addDatabase("QSQLITE"); // драйвер sqlite
    db.setDatabaseName("./audioDB.sqlite"); // добавити базу даних в папку проекту

    if(db.open()){          // перевірка чи відкриється база даних
        qDebug("open");     // якщо відкривається в консоль виводим open, якщо ні відповідно no open
    }

    else{
        qDebug("no open");
        qDebug() << QSqlDatabase::drivers();

    }


    QString queryToCreateTable = "CREATE TABLE audioList ("
                                 "music_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                                 "path VARCHAR(100) NOT NULL,"
                                 "song_name VARCHAR(100) NOT NULL); ";

    query = new QSqlQuery;

    if(!query->exec(queryToCreateTable)){
        qDebug()<<"error creatig table";
    }



    model =new QSqlTableModel(this,db);
    model->setTable("audioList");
    model->select();

    ui->tableViewAudio->setModel(model);

    qDebug("create table");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete query;
}


void MainWindow::on_Add_clicked()
{

    QString file = QFileDialog::getOpenFileName(this,tr("Open files"),QString(),tr("Audio Files (*.mp3)")); //шлях до файлу


    QFileInfo info(file);
    QString fileName = info.fileName(); //отримати назву файлу

    ui->song_name->setText(fileName);

    query->prepare("INSERT INTO audioList("
                   "path, "
                   "song_name)"
                   "VALUES(?,?);");

    query->addBindValue(file);
    query->addBindValue(fileName);

    if(!query->exec()){
        qDebug("error entering data");
    }

    model->select();

    ui->tableViewAudio->setModel(model);


}

