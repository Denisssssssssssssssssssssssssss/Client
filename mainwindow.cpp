// mainwindow.cpp
#include "mainwindow.h"
#include "loginwidget.h"
#include <QTcpSocket>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Устанавливаем размер и заголовок окна
    setWindowTitle("Вход");
    resize(500, 500);

    // Создаем сокет
    QTcpSocket *socket = new QTcpSocket(this);
    // Отключение от сервера перед созданием `LoginWidget`
    socket->disconnectFromHost();

    // Создаем `LoginWidget` и передаем сокет
    LoginWidget *loginWidget = new LoginWidget(socket, this);
    setCentralWidget(loginWidget);
}
