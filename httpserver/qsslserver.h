/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtWebSockets module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSSLSERVER_P_H
#define QSSLSERVER_P_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QSslError>
#include <QtNetwork/QSslConfiguration>
#include <QtCore/QList>

QT_BEGIN_NAMESPACE

class QSslServer : public QTcpServer
{
    Q_OBJECT
    Q_DISABLE_COPY(QSslServer)

public:
    QSslServer(QObject *parent = Q_NULLPTR);
    virtual ~QSslServer();

    void setSslConfiguration(const QSslConfiguration &sslConfiguration);
    QSslConfiguration sslConfiguration() const;

    QSslSocket *nextPendingConnection();

Q_SIGNALS:
    void sslErrors(const QList<QSslError> &errors);
    void peerVerifyError(const QSslError &error);
    void newEncryptedConnection();

protected:
    virtual void incomingConnection(qintptr socket);

private:
    QSslConfiguration m_sslConfiguration;
};

QT_END_NAMESPACE

#endif // QSSLSERVER_P_H
