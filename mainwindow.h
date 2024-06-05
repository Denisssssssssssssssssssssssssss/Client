#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QTcpSocket>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    int windowwidth = 500;
    int windowheight = 500;
    QString windowname;
    QTcpSocket *socket;

public:
    MainWindow(QWidget *parent = nullptr);
};

#endif // MAINWINDOW_H
