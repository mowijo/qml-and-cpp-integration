#include "myobject.h"
#include <QTimer>

NameCounter::NameCounter(const QString &name) :
    QObject(0)
{
    setName(name);
}

NameCounter::NameCounter() :
    QObject(0)
{
}


QString NameCounter::getName() const
{
    return tr("%1 %2").arg(m_name).arg(m_counter);
}

void NameCounter::setName(const QString &newname)
{
    m_counter = 1;
    m_name = newname;
    startTimer(1000, Qt::CoarseTimer);
}



void NameCounter::timerEvent(QTimerEvent * )
{
    m_counter++;
    emit nameChanged();
}
