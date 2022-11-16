#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->playAndStopSong, &QPushButton::clicked,this, &MainWindow::playMusic);
    connect(ui->playAndStopSong, &QPushButton::clicked,this, &MainWindow::stopMusic);




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
    ui->tableViewAudio->hideColumn(0);
    ui->tableViewAudio->hideColumn(1);
    ui->tableViewAudio->setColumnWidth(2,ui->tableViewAudio->width());

    qDebug("create table");


    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput;
    //ui->volumeSlider->setOrientation(Qt::Horizontal);
    ui->volumeSlider->setSliderPosition(50);
    ui->volumeSlider->setRange(0,100);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete query;
    delete player;
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
    ui->tableViewAudio->hideColumn(0);
    ui->tableViewAudio->hideColumn(1);
    ui->tableViewAudio->setColumnWidth(2,ui->tableViewAudio->width());

    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile(file));
    //audioOutput->setVolume(50); // воно лишнє шо з ним шо без нього працює
    player->play();
}



void MainWindow::playMusic()
{
    ui->playAndStopSong->setText("Stop");
    player->play();

    connect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::stopMusic);
    disconnect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::playMusic);
}


void MainWindow::stopMusic()
{
    ui->playAndStopSong->setText("Play");
    player->pause();

    disconnect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::stopMusic);
    connect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::playMusic);
}






void MainWindow::on_volumeSlider_sliderMoved(int position)
{
    int pos=ui->volumeSlider->sliderPosition();
    qDebug()<<pos;
    audioOutput->setVolume(ui->volumeSlider->value());

}





void MainWindow::on_volumeSlider_valueChanged(int value)
{
    int pos=ui->volumeSlider->sliderPosition();
    qDebug()<<pos;

    audioOutput->setVolume(ui->volumeSlider->value());


}




void MainWindow::on_tableViewAudio_doubleClicked(const QModelIndex &index)
{
    QString url;
    QString songName;

    url=ui->tableViewAudio->model()->data(ui->tableViewAudio->model()->index(index.row(),1)).toString();
    songName =ui->tableViewAudio->model()->data(ui->tableViewAudio->model()->index(index.row(),2)).toString();
    ui->song_name->setText(songName);


    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile(url));
    //audioOutput->setVolume(100);
    player->play();
}

