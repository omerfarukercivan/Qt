#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum Packet
    {
        Ecg = 0x01,
        Parameters = 0x04,
        Rainbow = 0x0C
    };
    Q_ENUM(Packet)

    enum EcgLead {
        I = 0x01,
        II = 0x02
    };
    Q_ENUM(EcgLead)

    static int packetSize(const Packet packet);

private:
    Ui::MainWindow *ui;

    QByteArray m_buffer;
    QByteArray m_packet;
    QSerialPort *serial;
    quint16 sayi1;
    int sayi2;
    QString z;
    QByteArray a;
    QByteArray c;
    QByteArray hex;
    QByteArray command;


    void splitRawData(const MainWindow::Packet type, const int id, const QByteArray& packet);
    inline static const quint8 FIRST_DATA_INDEX = 4;
    inline static const quint8 WORD_SIZE = 8;
    unsigned long sayi222;

public slots:
    void MySlot();

};
#endif // MAINWINDOW_H
