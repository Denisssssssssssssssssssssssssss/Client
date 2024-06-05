// loginwidget.cpp
#include "loginwidget.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

LoginWidget::LoginWidget(QTcpSocket *socket, QWidget *parent) : QWidget(parent), socket(socket)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *titleLabel = new QLabel("Вход");
    titleLabel->setAlignment(Qt::AlignCenter);

    QLineEdit *loginInput = new QLineEdit();
    loginInput->setPlaceholderText("Введите логин...");

    QLineEdit *passwordInput = new QLineEdit();
    passwordInput->setPlaceholderText("Введите пароль...");
    passwordInput->setEchoMode(QLineEdit::Password);

    QPushButton *loginButton = new QPushButton("Вход");

    QLabel *registerLabel = new QLabel("<a href=\"#\">Нет аккаунта? Зарегистрироваться</a>");
    registerLabel->setTextFormat(Qt::RichText);
    registerLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    connect(registerLabel, &QLabel::linkActivated, this, [=](const QString &) {
        qDebug() << "Ссылка на регистрацию нажата";
    });

    layout->addWidget(titleLabel);
    layout->addWidget(loginInput);
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);
    layout->addWidget(registerLabel);

    // Подключение к серверу
    if (socket && !socket->isOpen()) {
        // Это псевдокод. Замените "host" и "port" на фактические значения.
        socket->connectToHost("127.0.0.1", 1234);
    }
}
