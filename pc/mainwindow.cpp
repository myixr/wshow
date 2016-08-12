#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect( ui->btn_open_serial_port, SIGNAL(clicked()),
             this, SLOT(onOpenSerial()) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOpenSerial()
{
    auto port_info = ui->combobox_serial_port->getSerial();
    if( !port_info.isValid() ){
        qDebug() << "open serial, serial is invalid";
        return;
    }
    int baudrate = ui->combobox_baudrate->getBaudrate();
    if( baudrate < 0  ){
        qDebug() << "open serial, baudrate is invalud";
        return;
    }

    openSerial( port_info.systemLocation(), baudrate );
}

bool MainWindow::openSerial(QString port, int baudrate)
{
    qDebug() << "Open serial: " << port << ":" << baudrate;
    return false;
}
