#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./oblikStudentiv.sqlite");

    if(db.open()){
        qDebug("open");
    }
    else{
        qDebug("no open");
    }


    QString queryToCreateTable = "CREATE TABLE students ("
                                 "student_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                                 "age INTEGER NOT NULL,"
                                 "name VARCHAR(50) NOT NULL,"
                                 "groupp VARCHAR(10) NOT NULL," //якась проблема
                                 "gradebook INTEGER NOT NULL,"
                                 "oop INTEGER NOT NULL,"
                                 "english INTEGER NOT NULL,"
                                 "db INTEGER NOT NULL); ";

    query = new QSqlQuery;

    if(!query->exec(queryToCreateTable)){
        qDebug()<<"error creatig table";
    }

    model =new QSqlTableModel(this,db);
    model->setTable("students");

    model->select();
    ui->tableStudents->setModel(model);
    setColumnsSize();

    student = new Student2;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete query;
    delete viev;
    delete student;
}

void MainWindow::on_add_clicked()
{
    QString name=ui->name->text();
    QString group=ui->group->text();

    int age=ui->age->text().toInt();
    int oop=ui->oop->text().toInt();
    int english=ui->engl->text().toInt();
    int db=ui->db->text().toInt();
    int gradebook = ui->gradebook->text().toInt();

    if(group==""||name==""||age==0||gradebook==0){
            //qDebug("error enering data");
            error=new QMessageBox;
            error->setText("error enering data");
            error->exec();
        }
    else{
        student->setData(name,group,oop,english,db,gradebook,age);//для завдання

        QString insert="INSERT INTO students("
                       "age,"
                       "name,"
                       "groupp,"
                       "gradebook,"
                       "oop,"
                       "english,"
                       "db)"
                       "VALUES(?,?,?,?,?,?,?);";

        query->prepare(insert);

        query->addBindValue(age);
        query->addBindValue(name);
        query->addBindValue(group);
        query->addBindValue(gradebook);
        query->addBindValue(oop);
        query->addBindValue(english);
        query->addBindValue(db);

        if(!query->exec()){
            //qDebug("error enering data");

        }

        model->select();

        ui->tableStudents->setModel(model);
        setColumnsSize();
    }
}


void MainWindow::on_delete_2_clicked()
{
    model->removeRow(row);
    model->select();

    ui->tableStudents->setModel(model);
    setColumnsSize();
}


void MainWindow::on_tableStudents_clicked(const QModelIndex &index)
{
    row = index.row();
}

void MainWindow::setColumnsSize()
{
    ui->tableStudents->hideColumn(0);
   ui->tableStudents->setColumnWidth(5,50);
   ui->tableStudents->setColumnWidth(6,70);
   ui->tableStudents->setColumnWidth(7,50);
   ui->tableStudents->setColumnWidth(2,300);
   ui->tableStudents->setColumnWidth(1,50);

   ui->age->setText("");
   ui->name->setText("");
   ui->gradebook->setText("");
   ui->oop->setText("");
   ui->engl->setText("");
   ui->db->setText("");
   ui->group->setText("");

}

