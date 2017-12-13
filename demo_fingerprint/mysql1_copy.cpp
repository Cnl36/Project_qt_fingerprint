#include "mysql.h"
#include <QBuffer>
#include <QFile>
#include <QDataStream>
#include <QDebug>

mysql::mysql(QObject *parent) :
    QObject(parent)
{
    p_byteArray = QByteArray();
}


void mysql::setFileName(const QString &filename)
{
    if ( filename.isEmpty() )
        return;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
        return;

    p_byteArray = file.readAll();
}

void mysql::setPixmap(const QPixmap &pixmap)
{
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "PNG");
    p_byteArray = buffer.data();

}


bool mysql::saveData(const QString &filename)
{
    if (p_byteArray.isEmpty()){
        qDebug() << "empty byteArray";
        return false;
    }

    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QDataStream stream( &file );
    stream.writeRawData( p_byteArray.constData(), p_byteArray.size() );
    return true;

}
