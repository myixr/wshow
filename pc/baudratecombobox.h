#ifndef BAUDRATECOMBOBOX_H
#define BAUDRATECOMBOBOX_H

#include <QComboBox>

class BaudrateComboBox : public QComboBox
{
    Q_OBJECT
public:
    BaudrateComboBox( QWidget *parent=NULL );

    /* return -1 if baudrate is invalid */
    int getBaudrate( void );
private slots:
    void onItemSelected(int);
private:
    void updateItems( void );
};

#endif // BAUDRATECOMBOBOX_H
