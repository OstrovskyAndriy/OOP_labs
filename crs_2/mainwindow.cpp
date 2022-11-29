#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableViewAudio->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableViewAudio->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->playAndStopSong, &QPushButton::clicked,this, &MainWindow::playMusic);
    connect(ui->musicSlider, &QSlider::sliderMoved, this, &MainWindow::seek);


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

    vievOfTable();

    qDebug("create table");


    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput;

    connect(player,&QMediaPlayer::positionChanged,this,&MainWindow::onPositionChanged);

    //регулювання гучності
    ui->volumeSlider->setSliderPosition(50);
    ui->volumeSlider->setRange(0,100);
    ui->songTime->setText("");

}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete query;
    delete player;
    //delete viev;

}


void MainWindow::on_Add_clicked()
{

    QString file = QFileDialog::getOpenFileName(this,tr("Open files"),QString(),tr("Audio Files (*.mp3)")); //шлях до файлу


    QFileInfo info(file);
    QString fileName = info.fileName(); //отримати назву файлу
    QString newFilePath;

    ui->song_name->setText(fileName);



    if(QDir("music").exists()){     //перевіряю чи є папка musiс, якщо є то копіюю файл
        QFile::copy(file,"./music/"+fileName);

        newFilePath=QFileInfo("./music/"+fileName).absoluteFilePath();

    }
    else{
        QDir().mkdir("music"); //інше створюю папку і копіюю файл
        QFile::copy(file,"./music/"+fileName);

    }

    query->prepare("INSERT INTO audioList("
                   "path, "
                   "song_name)"
                   "VALUES(?,?);");

    query->addBindValue(newFilePath);
    query->addBindValue(fileName);

    if(!query->exec()){
        //qDebug("error entering data");
        errorMsg.setText("Error entering data");
        errorMsg.exec();

    }

    else{
        player->setAudioOutput(audioOutput);
        player->setSource(QUrl::fromLocalFile(newFilePath));

        //нууу час я отримав але не так як треба спершу повертає 0 і на наступний раз вже довжину
        /*QTime time=QTime::fromMSecsSinceStartOfDay(player->duration());
            qDebug()<<time.toString("mm:ss");*/

        player->play();
    }
    vievOfTable();

    songIndex=ui->tableViewAudio->model()->columnCount();



    ui->playAndStopSong->setText("Pause");
    // дві наступні стрічки коду для того щоб не був баг, коли музика на паузі і додаєм музику

    connect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::stopMusic);
    disconnect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::playMusic);

    //ui->musicSlider->setRange(0,player->duration());


}


void MainWindow::playMusic()
{
    //перемотування музики
    ui->musicSlider->setRange(0,player->duration());

    ui->playAndStopSong->setText("Pause");
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



void MainWindow::on_volumeSlider_sliderMoved()  // виконуєтсья лише коли регулятор пересувати
{
    qreal linearVolume =  QAudio::convertVolume(ui->volumeSlider->value() / qreal(100),
                                                QAudio::LogarithmicVolumeScale,
                                                QAudio::LinearVolumeScale);
    audioOutput->setVolume(linearVolume);


}


void MainWindow::on_volumeSlider_valueChanged() // виконуєтсья лише коли клацнути по регулятору гучності
{

    qreal linearVolume =  QAudio::convertVolume(ui->volumeSlider->value() / qreal(100),
                                                QAudio::LogarithmicVolumeScale,
                                                QAudio::LinearVolumeScale);
    audioOutput->setVolume(linearVolume);

}



void MainWindow::on_tableViewAudio_doubleClicked(const QModelIndex &index)
{
    url=ui->tableViewAudio->model()->data(ui->tableViewAudio->model()->index(index.row(),1)).toString();
    songName =ui->tableViewAudio->model()->data(ui->tableViewAudio->model()->index(index.row(),2)).toString();
    songIndex = index.row();

    //перевірка чи файл дійсний
    //якщо не дійсний то видалити з бази даних
    if(!QFile(url).exists()){
        ui->tableViewAudio->model()->removeRow(songIndex);
        vievOfTable();

        //Вивести про це помилку
        //QMessageBox errorMsg;
        errorMsg.setText(songName+" not found");
        errorMsg.exec();
    }

    else{
        //в іншому випадку включити музику
        ui->song_name->setText(songName);
        player->setAudioOutput(audioOutput);
        player->setSource(QUrl::fromLocalFile(url));

        this->playMusic();
//        player->play();

        //    // дві наступні стрічки коду для того щоб не був баг, коли музика на паузі і даблклікаєм іншу музику
        //    connect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::stopMusic);
        //    ui->playAndStopSong->setText("Pause");
        //    disconnect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::playMusic);



        //    ui->musicSlider->setRange(0,player->duration());
    }

}




void MainWindow::on_nextSong_clicked()
{
    songIndex++;

    if(songIndex==ui->tableViewAudio->model()->rowCount()){
        songIndex=0;
    }

    url=ui->tableViewAudio->model()->data(ui->tableViewAudio->model()->index(songIndex,1)).toString();
    songName =ui->tableViewAudio->model()->data(ui->tableViewAudio->model()->index(songIndex,2)).toString();
    ui->song_name->setText(songName);

    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile(url));
    player->play();

    ui->playAndStopSong->setText("Pause");
    connect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::stopMusic);
    disconnect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::playMusic);

}


void MainWindow::on_prevSong_clicked()
{
    if(songIndex==0){
        songIndex=ui->tableViewAudio->model()->rowCount();
    }
    songIndex--;


    url=ui->tableViewAudio->model()->data(ui->tableViewAudio->model()->index(songIndex,1)).toString();
    songName =ui->tableViewAudio->model()->data(ui->tableViewAudio->model()->index(songIndex,2)).toString();
    ui->song_name->setText(songName);


    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile(url));
    player->play();

    ui->playAndStopSong->setText("Pause");
    connect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::stopMusic);
    disconnect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::playMusic);
}


void MainWindow::on_offMusic_clicked()
{
    player->stop();
}





void MainWindow::on_closeWindow_clicked()
{
    QApplication::exit();
}


void MainWindow::on_tableViewAudio_clicked(const QModelIndex &index)
{
    rowToDelete=index.row();
}


void MainWindow::on_deleteButton_clicked()
{
    ui->tableViewAudio->model()->removeRow(rowToDelete);
    vievOfTable();

    //qDebug()<<songIndex;
    //qDebug()<<rowToDelete;

    if(songIndex==rowToDelete){
        player->stop();
    }
}

void MainWindow::vievOfTable()
{
    model->select();

    ui->tableViewAudio->setModel(model);
    ui->tableViewAudio->hideColumn(0);
    ui->tableViewAudio->hideColumn(1);
    ui->tableViewAudio->setColumnWidth(2,ui->tableViewAudio->width());
}

// не дороблено
void MainWindow::changeStateOfPauseButton()
{
    ui->playAndStopSong->setText("Pause");
    // дві наступні стрічки коду для того щоб не був баг, коли музика на паузі і додаєм музику
    connect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::stopMusic);
    disconnect(ui->playAndStopSong, &QPushButton::clicked, this, &MainWindow::playMusic);
}





void MainWindow::seek(int mseconds)
{
    player->setPosition(mseconds);
}



void MainWindow::setSliderPosition(qint64 position)
{
    qDebug()<< position;
    //ui->musicSlider->setSliderPosition(position);
}



void MainWindow::onDurationChanged(qint64 duration)
{
    m_duration = duration / 1000;
    ui->musicSlider->setMaximum(duration);
}

void MainWindow::onPositionChanged(qint64 progress)
{
    if (!ui->musicSlider->isSliderDown())
        ui->musicSlider->setValue(progress);

    updateDurationInfo(progress / 1000);
}





void MainWindow::updateDurationInfo(qint64 currentInfo)
{
//    QString tStr;
//    if (currentInfo || m_duration) {
//        QTime currentTime((currentInfo / 3600) % 60, (currentInfo / 60) % 60,
//                          currentInfo % 60, (currentInfo * 1000) % 1000);
//        QTime totalTime((m_duration / 3600) % 60, (m_duration / 60) % 60,
//                        m_duration % 60, (m_duration * 1000) % 1000);
//        QString format = "mm:ss";
////        if (m_duration > 3600)
////            format = "mm:ss";

//        QTime time=QTime::fromMSecsSinceStartOfDay(player->duration());
//        //qDebug()<<time.toString("mm:ss");

//        tStr = currentTime.toString(format) + " / " + totalTime.toString(time.toString("mm:ss"));
//    }
//    ui->songTime->setText(tStr);

    QString tStr;
    if (currentInfo || m_duration) {
        QTime currentTime((currentInfo / 3600) % 60, (currentInfo / 60) % 60,
            currentInfo % 60, (currentInfo * 1000) % 1000);
        QTime totalTime((m_duration / 3600) % 60, (m_duration / 60) % 60,
            m_duration % 60, (m_duration * 1000) % 1000);
        QString format = "mm:ss";
        //if (m_duration > 3600)
          //  format = "hh:mm:ss";

        QTime time=QTime::fromMSecsSinceStartOfDay(player->duration());
        //        //qDebug()<<time.toString("mm:ss");

        tStr = currentTime.toString(format) + " / " + totalTime.toString(time.toString("mm:ss"));
    }
    ui->songTime->setText(tStr);

}

