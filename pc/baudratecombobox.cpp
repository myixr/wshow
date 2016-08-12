#include "baudratecombobox.h"

#define CUSTOM_EDITABLE_DEFAULT_TEXT "custom..."

BaudrateComboBox::BaudrateComboBox(QWidget *parent)
    :QComboBox(parent)
{
    updateItems();
    connect( this, SIGNAL(currentIndexChanged(int)),
             this, SLOT(onItemSelected(int)) );
}

int BaudrateComboBox::getBaudrate()
{
    bool ok = false;
    int baudrate = currentText().toInt(&ok);
    if( !ok ){
        baudrate = -1;
    }
    return baudrate;
}

void BaudrateComboBox::onItemSelected( int idx )
{
    if( idx == count()-1 ){
        /*
        if( currentText() == CUSTOM_EDITABLE_DEFAULT_TEXT ){
            setItemText( idx, "" );
        }
        */
        setEditable( true );
    }
    else{
        setEditable( false );
    }

}

void BaudrateComboBox::updateItems()
{
    addItem( "9600" );
    addItem( "115200" );
    addItem( CUSTOM_EDITABLE_DEFAULT_TEXT );

    setEditable( false );
}


