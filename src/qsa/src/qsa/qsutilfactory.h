/****************************************************************************
** $Id: qsutilfactory.h  1.1.5   edited 2006-02-23T15:39:57$
**
** Copyright (C) 2001-2006 Trolltech AS.  All rights reserved.
**
** This file is part of the Qt Script for Applications framework (QSA).
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding a valid Qt Script for Applications license may use
** this file in accordance with the Qt Script for Applications License
** Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about QSA Commercial License Agreements.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
*****************************************************************************/

#ifndef QSUTILFACTORY_H
#define QSUTILFACTORY_H

#include "qsobjectfactory.h"

class QSA_EXPORT QSUtilFactory : public QSObjectFactory
{
public:
  enum Utilities {
    None       = 0x0000,
    File       = 0x0001,
    Directory  = 0x0002,
    Process    = 0x0004,
    All        = 0xffff
  };
  QSUtilFactory(uint enableFlags = All);

  virtual QObject *create(const QString &className,
                          const QSArgumentList &arguments,
                          QObject *context);

  QSInterpreter *interpreter() const {
    return QSObjectFactory::interpreter();
  }

};

#endif
