#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    windowname = "Вход";
    setWindowTitle(windowname);
    resize(windowwidth, windowheight);

    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, []() {
        qDebug() << "Соединение с сервером успешно установлено!";
    });

    // Подключение к сигналу 'readyRead', чтобы узнать, когда приходят данные от сервера
    connect(socket, &QTcpSocket::readyRead, this, [=]() {
        QByteArray data = socket->readAll();
        qDebug() << "Получены данные от сервера:" << data;
        // Здесь вы можете дополнительно обрабатывать полученные данные
    });

    // Подключение к сигналу 'errorOccurred', чтобы обрабатывать ошибки соединения
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::errorOccurred), this, [=](QAbstractSocket::SocketError socketError) {
        qDebug() << "Ошибка соединения:" << socket->errorString();
    });

    // Подключаемся к серверу
    qDebug() << "Попытка соединения с сервером...";
    socket->connectToHost("127.0.0.1", 1234);

    // Пример отправки данных серверу
    // Здесь можно использовать socket->write(...) после установления соединения,
    // например, в слоте, подключенном к сигналу connected
}
