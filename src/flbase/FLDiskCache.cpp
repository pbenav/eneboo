/***************************************************************************
                           FLDiskCache.cpp
                         -------------------
begin                : lun ago 02 2004
copyright            : (C) 2004-2005 by InfoSiAL, S.L.
email                : mail@infosial.com
***************************************************************************/
/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 ***************************************************************************/
/***************************************************************************
   Este  programa es software libre. Puede redistribuirlo y/o modificarlo
   bajo  los  t�rminos  de  la  Licencia  P�blica General de GNU   en  su
   versi�n 2, publicada  por  la  Free  Software Foundation.
 ***************************************************************************/

#include "FLDiskCache.h"
#include "FLApplication.h"
#include "FLSqlDatabase.h"
#include "AQConfig.h"

QString FLDiskCache::absoluteDirPath;

bool FLDiskCache::find(const QString &key, QString &str)
{
  QString fileCache(AQ_DISKCACHE_DIRPATH + '/' + key);
  QFile fi(fileCache);
  if (!fi.open(IO_ReadOnly))
    return false;
  QTextStream t(&fi);
  str = t.read();
  fi.close();
  return true;
}

bool FLDiskCache::insert(const QString &key, const QString &str)
{
  QString fileCache(AQ_DISKCACHE_DIRPATH + '/' + key);
  QFile fi(fileCache);
  QDir d(AQ_DISKCACHE_DIRPATH);
  if (!d.exists())
    d.mkdir(AQ_DISKCACHE_DIRPATH);
  else if (fi.exists())
    return true;
  if (!str.isEmpty()) {
    if (fi.open(IO_WriteOnly)) {
      QTextStream t(&fi);
      t << str;
      fi.close();
      return true;
    }
    return false;
  }
  return false;
}

void FLDiskCache::clear()
{
  QDir d(AQ_DISKCACHE_DIRPATH);
  if (d.exists()) {
    QStringList lst = d.entryList("*; *.*");
    for (QStringList::Iterator it = lst.begin(); it != lst.end(); ++it)
      d.remove(AQ_DISKCACHE_DIRPATH + '/' + (*it));
  }
#ifndef QSDEBUGGER
  QTextCodec *codec = QTextCodec::codecForLocale();
  QString localEncode(codec ? codec->mimeName() : "");
  QString path(AQ_USRHOME + "/.eneboocache/" + localEncode);
  QDir d2(path);
  if (d2.exists()) {
    QStringList lst = d2.entryList("sys*");
    for (QStringList::Iterator it = lst.begin(); it != lst.end(); ++it)
      d2.remove(path + '/' + (*it));
  }
#endif
}

QString FLDiskCache::absoluteFilePath(const QString &key)
{
  QString fileCache(AQ_DISKCACHE_DIRPATH + '/' + key);
  if (!QFile::exists(fileCache))
    return QString::null;
  return fileCache;
}

static inline void aqSetAndCreateDirPath(const QString &path)
{
  AQ_DISKCACHE_DIRPATH = path;
  QDir d(AQ_DISKCACHE_DIRPATH);
  if (!d.exists())
    d.mkdir(AQ_DISKCACHE_DIRPATH);
}

void FLDiskCache::init(FLApplication *app)
{
  QTextCodec *codec = QTextCodec::codecForLocale();
  QString localEncode(codec ? codec->mimeName() : "");
  if (!app) {
    aqSetAndCreateDirPath(AQ_USRHOME + "/.eneboocache");
    if (!localEncode.isEmpty())
      aqSetAndCreateDirPath(AQ_DISKCACHE_DIRPATH + '/' + localEncode);
  } else {
    aqSetAndCreateDirPath(
      AQ_USRHOME + "/.eneboocache/" +
      app->db()->database()
    );
    if (!localEncode.isEmpty())
      aqSetAndCreateDirPath(AQ_DISKCACHE_DIRPATH + '/' + localEncode);
  }
}
