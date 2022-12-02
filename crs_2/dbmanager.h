#ifndef DBMANAGER_H
#define DBMANAGER_H


#include <QSqlDatabase> // бібліотека бази даних
#include <QDebug> //бібліотека для відладки програми
#include <QSqlQuery> // бібліотека для запиту до баз даних
#include <QSqlTableModel> // для відображення таблиць
#include <QTableView>
#include <QtSql>


class DBManager
{
    QSqlDatabase db;
    QSqlQuery *query;
//    QSqlTableModel *model;

public:
    DBManager();

    void createDB();

    QString getDBName();

    QSqlDatabase returnDB();

    bool insert(QString &songUrl,QString &song_name) const;
};

#endif // DBMANAGER_H
