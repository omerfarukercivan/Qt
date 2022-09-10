#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QTimer>
#include <QLabel>

QString elde1elde1 = "";
QString elde2elde1 = "";
QString elde3elde1 = "";
QString elde4elde1 = "";
QString elde5elde1 = "";
QString elde6elde1 = "";
QString elde7elde1 = "";
QString elde8elde1 = "";
QString elde9elde1 = "";
QString elde10elde1 = "";
QString elde11elde1 = "";
QString elde12elde1 = "";
QString elde13elde1 = "";
QString elde14elde1 = "";
QString elde15elde1 = "";
QString elde16elde1 = "";
QString elde17elde1 = "";
QString elde18elde1 = "";
QString elde19elde1 = "";
QString elde20elde1 = "";
QString elde21elde1 = "";
QString elde22elde1 = "";
QString elde23elde1 = "";
QString elde24elde1 = "";
QString elde25elde1 = "";

QString elde1elde2 = "";
QString elde2elde2 = "";
QString elde3elde2 = "";
QString elde4elde2 = "";
QString elde5elde2 = "";
QString elde6elde2 = "";
QString elde7elde2 = "";
QString elde8elde2 = "";
QString elde9elde2 = "";
QString elde10elde2 = "";
QString elde11elde2 = "";
QString elde12elde2 = "";
QString elde13elde2 = "";
QString elde14elde2 = "";
QString elde15elde2 = "";
QString elde16elde2 = "";
QString elde17elde2 = "";
QString elde18elde2 = "";
QString elde19elde2 = "";
QString elde20elde2 = "";
QString elde21elde2 = "";
QString elde22elde2 = "";
QString elde23elde2 = "";
QString elde24elde2 = "";
QString elde25elde2 = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(MySlot()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    timer->start(125);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter myline(this);
    QPen mypen(Qt::green);
    mypen.setWidth(3);
    myline.setPen(mypen);

    if(elde1elde1 != "" && elde2elde1 != "")
        myline.drawLine(200, (elde1elde2.toInt()*4), 250, (elde2elde2.toInt()*4));

    if(elde2elde1 != "" && elde3elde1 != "")
        myline.drawLine(250, (elde2elde2.toInt()*4), 300, (elde3elde2.toInt()*4));

    if(elde3elde1 != "" && elde4elde1 != "")
        myline.drawLine(300, (elde3elde2.toInt()*4), 350, (elde4elde2.toInt()*4));

    if(elde4elde1 != "" && elde5elde1 != "")
        myline.drawLine(350, (elde4elde2.toInt()*4), 400, (elde5elde2.toInt()*4));

    if(elde5elde1 != "" && elde6elde1 != "")
        myline.drawLine(400, (elde5elde2.toInt()*4), 450, (elde6elde2.toInt()*4));

    if(elde6elde1 != "" && elde7elde1 != "")
        myline.drawLine(450, (elde6elde2.toInt()*4), 500, (elde7elde2.toInt()*4));

    if(elde7elde1 != "" && elde8elde1 != "")
        myline.drawLine(500, (elde7elde2.toInt()*4), 550, (elde8elde2.toInt()*4));

    if(elde8elde1 != "" && elde9elde1 != "")
        myline.drawLine(550, (elde8elde2.toInt()*4), 600, (elde9elde2.toInt()*4));

    if(elde9elde1 != "" && elde10elde1 != "")
        myline.drawLine(600, (elde9elde2.toInt()*4), 650, (elde10elde2.toInt()*4));

    if(elde10elde1 != "" && elde11elde1 != "")
        myline.drawLine(650, (elde10elde2.toInt()*4), 700, (elde11elde2.toInt()*4));

    if(elde11elde1 != "" && elde12elde1 != "")
        myline.drawLine(700, (elde11elde2.toInt()*4), 750, (elde12elde2.toInt()*4));

    if(elde12elde1 != "" && elde13elde1 != "")
        myline.drawLine(750, (elde12elde2.toInt()*4), 800, (elde13elde2.toInt()*4));

    if(elde13elde1 != "" && elde14elde1 != "")
        myline.drawLine(800, (elde13elde2.toInt()*4), 850, (elde14elde2.toInt()*4));

    if(elde14elde1 != "" && elde15elde1 != "")
        myline.drawLine(850, (elde14elde2.toInt()*4), 900, (elde15elde2.toInt()*4));

    if(elde15elde1 != "" && elde16elde1 != "")
        myline.drawLine(900, (elde15elde2.toInt()*4), 950, (elde16elde2.toInt()*4));

    if(elde16elde1 != "" && elde17elde1 != "")
        myline.drawLine(950, (elde16elde2.toInt()*4), 1000, (elde17elde2.toInt()*4));

    if(elde17elde1 != "" && elde18elde1 != "")
        myline.drawLine(1000, (elde17elde2.toInt()*4), 1050, (elde18elde2.toInt()*4));

    if(elde18elde1 != "" && elde19elde1 != "")
        myline.drawLine(1050, (elde18elde2.toInt()*4), 1100, (elde19elde2.toInt()*4));

    if(elde19elde1 != "" && elde20elde1 != "")
        myline.drawLine(1100, (elde19elde2.toInt()*4), 1150, (elde20elde2.toInt()*4));

    if(elde20elde1 != "" && elde21elde1 != "")
        myline.drawLine(1150, (elde20elde2.toInt()*4), 1200, (elde21elde2.toInt()*4));

    if(elde21elde1 != "" && elde22elde1 != "")
        myline.drawLine(1200, (elde21elde2.toInt()*4), 1250, (elde22elde2.toInt()*4));

    if(elde22elde1 != "" && elde23elde1 != "")
        myline.drawLine(1250, (elde22elde2.toInt()*4), 1300, (elde23elde2.toInt()*4));

    if(elde23elde1 != "" && elde24elde1 != "")
        myline.drawLine(1300, (elde23elde2.toInt()*4), 1350, (elde24elde2.toInt()*4));

    if(elde24elde1 != "" && elde25elde1 != "")
        myline.drawLine(1350, (elde24elde2.toInt()*4), 1400, (elde25elde2.toInt()*4));
}

int kontrol = 0;

void MainWindow::MySlot(){

    srand(time(NULL));
    int abcd = (rand()%9) + 1;
    //int abcd = 0;
    int sayi1 = 100;
    int sayi2 = 120;

    if(kontrol == abcd)
        abcd = abcd + 2;

    if(abcd > 0 && abcd < 10){
        if(abcd % 4 == 3)
            sayi1 = sayi1 - abcd * 2;
            //sayi1 = 0;

        else if(abcd % 4 == 2)
            sayi1 = sayi1 + abcd * 3;
            //sayi1 = 0;

        else if(abcd % 4 == 1)
            sayi1 = sayi1 - abcd * 2;
            //sayi1 = 0;

        else
            sayi1 = sayi1 + abcd * 3;
            //sayi1 = 0;

        kontrol = abcd;
    }

    if(abcd > 0 && abcd < 10){
        if(abcd % 4 == 3)
            sayi2 = sayi2 + abcd * 5;
            //sayi2 = 0;

        else if(abcd % 4 == 2)
            sayi2 = sayi2 - abcd * 2;
            //sayi2 = 0;

        else if(abcd % 4 == 1)
            sayi2 = sayi2 + abcd * 4;
            //sayi2 = 0;

        else
            sayi2 = sayi2 - abcd * 4;
            //sayi2 = 0;
    }

    QString sayi1String = QString::number(sayi1);
    QString sayi2String = QString::number(sayi2);

    ui->lbl1->setText(sayi1String);

    if(elde1elde1 == ""){
        elde1elde1 = sayi1String;
        elde1elde2 = sayi2String;
    }

    else if(elde2elde1 == ""){
        elde2elde1 = sayi1String;
        elde2elde2 = sayi2String;
    }

    else if(elde3elde1 == ""){
        elde3elde1 = sayi1String;
        elde3elde2 = sayi2String;
    }

    else if(elde4elde1 == ""){
        elde4elde1 = sayi1String;
        elde4elde2 = sayi2String;
    }

    else if(elde5elde1 == ""){
        elde5elde1 = sayi1String;
        elde5elde2 = sayi2String;
    }

    else if(elde6elde1 == ""){
        elde6elde1 = sayi1String;
        elde6elde2 = sayi2String;
    }

    else if(elde7elde1 == ""){
        elde7elde1 = sayi1String;
        elde7elde2 = sayi2String;
    }

    else if(elde8elde1 == ""){
        elde8elde1 = sayi1String;
        elde8elde2 = sayi2String;
    }

    else if(elde9elde1 == ""){
        elde9elde1 = sayi1String;
        elde9elde2 = sayi2String;
    }

    else if(elde10elde1 == ""){
        elde10elde1 = sayi1String;
        elde10elde2 = sayi2String;
    }

    else if(elde11elde1 == ""){
        elde11elde1 = sayi1String;
        elde11elde2 = sayi2String;
    }

    else if(elde12elde1 == ""){
        elde12elde1 = sayi1String;
        elde12elde2 = sayi2String;
    }

    else if(elde13elde1 == ""){
        elde13elde1 = sayi1String;
        elde13elde2 = sayi2String;
    }

    else if(elde14elde1 == ""){
        elde14elde1 = sayi1String;
        elde14elde2 = sayi2String;
    }

    else if(elde15elde1 == ""){
        elde15elde1 = sayi1String;
        elde15elde2 = sayi2String;
    }

    else if(elde16elde1 == ""){
        elde16elde1 = sayi1String;
        elde16elde2 = sayi2String;
    }

    else if(elde17elde1 == ""){
        elde17elde1 = sayi1String;
        elde17elde2 = sayi2String;
    }

    else if(elde18elde1 == ""){
        elde18elde1 = sayi1String;
        elde18elde2 = sayi2String;
    }

    else if(elde19elde1 == ""){
        elde19elde1 = sayi1String;
        elde19elde2 = sayi2String;
    }

    else if(elde20elde1 == ""){
        elde20elde1 = sayi1String;
        elde20elde2 = sayi2String;
    }

    else if(elde21elde1 == ""){
        elde21elde1 = sayi1String;
        elde21elde2 = sayi2String;
    }

    else if(elde22elde1 == ""){
        elde22elde1 = sayi1String;
        elde22elde2 = sayi2String;
    }

    else if(elde23elde1 == ""){
        elde23elde1 = sayi1String;
        elde23elde2 = sayi2String;
    }

    else if(elde24elde1 == ""){
        elde24elde1 = sayi1String;
        elde24elde2 = sayi2String;
    }

    else if(elde25elde1 == ""){
        elde25elde1 = sayi1String;
        elde25elde2 = sayi2String;
    }
    else{
        elde1elde1 = elde2elde1;
        elde2elde1 = elde3elde1;
        elde3elde1 = elde4elde1;
        elde4elde1 = elde5elde1;
        elde5elde1 = elde6elde1;
        elde6elde1 = elde7elde1;
        elde7elde1 = elde8elde1;
        elde8elde1 = elde9elde1;
        elde9elde1 = elde10elde1;
        elde10elde1 = elde11elde1;
        elde11elde1 = elde12elde1;
        elde12elde1 = elde13elde1;
        elde13elde1 = elde14elde1;
        elde14elde1 = elde15elde1;
        elde15elde1 = elde16elde1;
        elde16elde1 = elde17elde1;
        elde17elde1 = elde18elde1;
        elde18elde1 = elde19elde1;
        elde19elde1 = elde20elde1;
        elde20elde1 = elde21elde1;
        elde21elde1 = elde22elde1;
        elde22elde1 = elde23elde1;
        elde23elde1 = elde24elde1;
        elde24elde1 = elde25elde1;
        elde25elde1 = sayi1String;

        elde1elde2 = elde2elde2;
        elde2elde2 = elde3elde2;
        elde3elde2 = elde4elde2;
        elde4elde2 = elde5elde2;
        elde5elde2 = elde6elde2;
        elde6elde2 = elde7elde2;
        elde7elde2 = elde8elde2;
        elde8elde2 = elde9elde2;
        elde9elde2 = elde10elde2;
        elde10elde2 = elde11elde2;
        elde11elde2 = elde12elde2;
        elde12elde2 = elde13elde2;
        elde13elde2 = elde14elde2;
        elde14elde2 = elde15elde2;
        elde15elde2 = elde16elde2;
        elde16elde2 = elde17elde2;
        elde17elde2 = elde18elde2;
        elde18elde2 = elde19elde2;
        elde19elde2 = elde20elde2;
        elde20elde2 = elde21elde2;
        elde21elde2 = elde22elde2;
        elde22elde2 = elde23elde2;
        elde23elde2 = elde24elde2;
        elde24elde2 = elde25elde2;
        elde25elde2 = sayi2String;
    }
}
