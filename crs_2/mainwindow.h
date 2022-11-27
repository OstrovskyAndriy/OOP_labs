#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include <QSqlDatabase> // бібліотека бази даних
#include <QDebug> //бібліотека для відладки програми
#include <QSqlQuery> // бібліотека для запиту до баз даних
#include <QSqlTableModel> // для відображення таблиць
#include <QTableView>
#include <QtSql>


#include <QStringList>
#include <QFileDialog>
#include <QFileInfo>

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QSlider>

#include <QFile>
#include <QDir>

#include <QTime>


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

    void on_tableViewAudio_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void playMusic();
    void stopMusic();


    void on_volumeSlider_sliderMoved();

    void on_volumeSlider_valueChanged();

    void on_nextSong_clicked();

    void on_prevSong_clicked();

    void on_offMusic_clicked();

    void on_closeWindow_clicked();

    void on_tableViewAudio_clicked(const QModelIndex &index);

    void on_deleteButton_clicked();

    void vievOfTable();
    void changeStateOfPauseButton();

    void on_slderOfMusicTime_sliderMoved(int position);

    void on_sliderOfMusicTime_sliderMoved(int position);

    //void on_musicSlider_sliderMoved(qint64 position);


     void durationChanged(qint64 duration);
     void positionChanged(qint64 progress);
     void seek(int mseconds);




private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    //QTableView *viev;

    QMediaPlayer *player;
    QAudioOutput *audioOutput;


    QString url;
    QString songName;
    QMessageBox errorMsg;
    int songIndex;
    int rowToDelete;

    void updateDurationInfo(qint64 currentInfo);
    qint64 m_duration;

};
#endif // MAINWINDOW_H
