/***************************************************************************
 *   Copyright (C) 2015 by Eike Hein <hein@kde.org>                        *
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
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#ifndef SYSTEMENTRY_H
#define SYSTEMENTRY_H

#include "abstractentry.h"

class KDisplayManager;

class SystemEntry : public AbstractEntry
{
    public:
        enum Action
        {
            NoAction = 0,
            LockSession,
            LogoutSession,
            SaveSession,
            SwitchUser,
            SuspendToRam,
            SuspendToDisk,
            Reboot,
            Shutdown
        };

        explicit SystemEntry(AbstractModel *owner, Action action);
        explicit SystemEntry(AbstractModel *owner, const QString &id);

        EntryType type() const Q_DECL_OVERRIDE { return RunnableType; }

        bool isValid() const Q_DECL_OVERRIDE;

        QIcon icon() const Q_DECL_OVERRIDE;
        QString iconName() const;
        QString name() const Q_DECL_OVERRIDE;
        QString group() const Q_DECL_OVERRIDE;
        QString description() const Q_DECL_OVERRIDE;

        QString id() const Q_DECL_OVERRIDE;

        bool run(const QString& actionId = QString(), const QVariant &argument = QVariant()) Q_DECL_OVERRIDE;

    private:
        void init();

        Action m_action;
        bool m_valid;

        static KDisplayManager *m_displayManager;
};

#endif
