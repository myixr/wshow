#include <QSerialPort>
#include <QSerialPortInfo>
#include <QBrush>
#include <QDebug>
#include "serialportcombobox.h"

SerialPortComboBox::SerialPortComboBox(QWidget *parent)
    : QComboBox(parent)
{

}

QSerialPortInfo SerialPortComboBox::getSerial()
{
    QSerialPortInfo port_info;
    int idx = currentIndex();
    if( idx >= 0 ){
        port_info =  QSerialPortInfo( itemData(idx).toString() );
        if( !port_info.isValid() ){
            qWarning() << "invalid serial port info";
        }
    }
    return port_info;
}

void SerialPortComboBox::showPopup()
{
    this->clear();

    auto ports = QSerialPortInfo::availablePorts();
    for( auto ite=ports.begin(); ite!=ports.end(); ++ite ){
        // XXX What info to use when open a serial port ?
        QString info = QString("%1(%2)")
                .arg( ite->systemLocation() )
                .arg( ite->description() );
        addItem( info, ite->portName() );

        /* If serial port is busy, set text color to gray */
        if( ite->isBusy() ){
            setItemData( count()-1, QBrush(Qt::gray), Qt::ForegroundRole );
        }

        setItemData( count()-1, info, Qt::ToolTipRole );
    }

    QComboBox::showPopup();
}
