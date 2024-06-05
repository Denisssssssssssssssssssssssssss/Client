// loginwidget.h
#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QTcpSocket>

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QTcpSocket *socket, QWidget *parent = nullptr);

private:
    QTcpSocket *socket;
};

#endif // LOGINWIDGET_H
