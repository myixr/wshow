#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void onOpenSerial();
private:
    bool openSerial( QString port, int baudrate );

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
