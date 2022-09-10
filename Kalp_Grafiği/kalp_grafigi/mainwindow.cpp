#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);

    serial = new QSerialPort(this);
    serial->setPortName("ttyUSB0");
    serial->setBaudRate(375000);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);

    hex.append((char) (0xBF));
    hex.append((char) (0x5F));
    hex.append((char) (0xFF));

    serial->write(hex);

    //qDebug()<<hex.toHex();

    command.append((char) 0xAA);
    command.append((char) 0x55);
    command.append((char) 0x0C);
    command.append((char) 0x01);
    command.append((char) 0x01);
    command.append((char) 0x00 + (char) 0x03);
    command.append((char) 0x04);
    command.append((char) 0x01);
    command.append((char) 0x01);
    command.append((char) 0x00);
    command.append((char) 0x00);
    command.append((char) 0x01);
    command.append((char) 0x05);
    command.append((char) 0x04);
    command.append((char) 0x01);

    //qDebug()<<"Smm Command : "<<command.toHex();

    serial->write(command);

    connect(serial, SIGNAL(readyRead()), this, SLOT(MySlot()));
    connect(timer, SIGNAL(timeout()), this, SLOT(MySlot()));

    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(Qt::green));
    ui->widget->graph(0)->setAntialiasedFill(true);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%s");
    ui->widget->xAxis->setTicker(timeTicker);
    ui->widget->axisRect()->setupFullAxesBox();

    ui->widget->xAxis->setTickLabelFont(QFont(QFont().family(),8));
    ui->widget->yAxis->setTickLabelFont(QFont(QFont().family(),8));

    ui->widget->xAxis2->setVisible(true);
    ui->widget->yAxis->setVisible(true);
    ui->widget->xAxis2->setTicks(false);
    ui->widget->yAxis2->setTicks(false);
    ui->widget->xAxis2->setTickLabels(false);
    ui->widget->yAxis2->setTickLabels(false);
}

MainWindow::~MainWindow()
{
    delete ui;

    serial->close();
}

void MainWindow::MySlot(){
    m_buffer.append(serial->readAll());

    int lastCompletePacketIndex= 0;

    for(int i = 0; i < m_buffer.size(); ++i){
        if(m_buffer[i] == (char)0xAA && i + 1 < m_buffer.size() && m_buffer[i + 1] == (char)0x55){
            const int indexOfLength = i + 2;
            int length = 0;

            if(indexOfLength < m_buffer.size()){
                length = *(reinterpret_cast<const unsigned char*>(&(m_buffer.constData()[i + 2])));

                if((length + i + 2) < m_buffer.size() && m_buffer[i + 4 + length] == (char)0xAA && m_buffer[i + 5 + length] == (char)0x55){
                    m_packet.clear();
                    m_packet.append(m_buffer.mid(i, 4 + length));

                    i += 3 + length;
                    lastCompletePacketIndex = i + 1;

                    if(!m_packet.isEmpty()){
                        const auto& packetEnum = QMetaEnum::fromType<MainWindow::Packet>();
                        const int packetCount = packetEnum.keyCount();
                        Packet packetType = Packet(0);

                        for(int i = 0; i < packetCount; ++i){
                            const auto packetValue = static_cast<MainWindow::Packet>(packetEnum.value(i));

                            if(m_packet.at(3) == packetValue && (packetValue == MainWindow::Rainbow ? true : m_packet.size() == packetSize(packetValue))){
                                packetType = packetValue;
                                break;
                            }
                        }

                        //HR
                        if(packetType == Parameters){
                            c = m_packet;
                            //qDebug()<<c.toHex();

                            sayi1 = *(reinterpret_cast<const unsigned char*>(&(c.constData()[5])));
                            //qDebug()<<"HR: "<<sayi1;
                        }
                        else if(packetType == Ecg){
                            a = m_packet;
                            //qDebug()<<a.toHex();

                            const int leadCount = QMetaEnum::fromType<MainWindow::EcgLead>().keyCount();
                            for (int lead = 0; lead < leadCount; ++lead)
                                splitRawData(MainWindow::Ecg, lead, m_packet.mid(FIRST_DATA_INDEX + (WORD_SIZE * lead), WORD_SIZE));
                        }
                    }
                }
            }
        }
    }
    m_buffer.remove(0, lastCompletePacketIndex);

    sayi222 = sayi2;

    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0;
    static double lastPointKey = 0;
    if(key - lastPointKey > 0.002)
    {
        ui->widget->graph(0)->addData(key, (double)sayi222);
        lastPointKey = key;
    }

    ui->widget->graph(0)->rescaleValueAxis();
    ui->widget->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->widget->replot();

    QString sayi1String = QString::number(sayi1);
    ui->lbl1->setText(sayi1String);
}

int MainWindow::packetSize(const Packet packet) {
    switch (packet) {
    case Ecg: return 62; break;
    case Parameters: return 15; break;
    case Rainbow: return 19; break;
    }

    return 0;
}

void MainWindow::splitRawData(const MainWindow::Packet type, const int id, const QByteArray& packet)
{
    const int bytesLength = packet.size() / WORD_SIZE ;

    for (int i = 0; i < packet.size(); i += bytesLength){

        if(bytesLength > 1)
            sayi2 = qFromBigEndian<quint16>(a.mid(12, 19));

        else
            sayi2 = qFromBigEndian<quint8>(a[i]);

        //qDebug()<<"sa:"<<sayi2;
    }
}
