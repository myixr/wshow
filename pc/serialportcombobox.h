#ifndef SERIALPORTCOMBOBOX_H
#define SERIALPORTCOMBOBOX_H

#include <QComboBox>
#include <QSerialPortInfo>

class SerialPortComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit SerialPortComboBox(QWidget *parent = 0);

    QSerialPortInfo getSerial();

protected:
    void showPopup();



signals:

public slots:
};

#endif // SERIALPORTCOMBOBOX_H
