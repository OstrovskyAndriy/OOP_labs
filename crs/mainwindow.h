#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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



//#include <QMediaPlaylist>



#include<QModelIndex>


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


    void on_volumeSlider_sliderMoved(int position);

    void on_volumeSlider_valueChanged(int value);

    void on_nextSong_clicked();

    void on_prevSong_clicked();

    void on_offMusic_clicked();

    void on_closeWindow_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    QTableView *viev;

    QMediaPlayer *player;
    QAudioOutput *audioOutput;


    QString url;
    QString songName;
    int songIndex;

};
#endif // MAINWINDOW_H
