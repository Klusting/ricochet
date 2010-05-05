#ifndef CONTACTREQUESTSERVER_H
#define CONTACTREQUESTSERVER_H

#include <QObject>

class QTcpSocket;

class ContactRequestServer : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ContactRequestServer)

public:
    explicit ContactRequestServer(QTcpSocket *socket);

private slots:
    void socketReadable();
    void socketDisconnected();

private:
    QTcpSocket * const socket;
    QByteArray cookie;

    enum
    {
        WaitRequest,
        WaitResponse
    } state;

    void sendCookie();
    bool sendResponse(uchar response);

    void handleRequest(const QByteArray &data);
};

#endif // CONTACTREQUESTSERVER_H