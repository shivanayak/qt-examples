/***************************************************************************
 *   Copyright (C) 2009, 2010 by Richard J. Moore <rich@kde.org>           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#include "networkaccessmanagerproxy.h"
#include "networkaccessviewer.h"

NetworkAccessManagerProxy::NetworkAccessManagerProxy(QObject *parent) :
    QNetworkAccessManager(parent),
    viewer(0)
{
}

void NetworkAccessManagerProxy::setNetworkAccessViewer( NetworkAccessViewer *viewer )
{
    this->viewer = viewer;
}


QNetworkReply *NetworkAccessManagerProxy::createRequest( Operation op,
                                                         const QNetworkRequest &req,
                                                         QIODevice * outgoingData )
{
    QNetworkReply *reply = QNetworkAccessManager::createRequest( op, req, outgoingData );
    viewer->addRequest( op, req, outgoingData, reply );
    return reply;
}
