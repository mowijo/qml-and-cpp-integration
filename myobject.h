#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QString>

class NameCounter : public QObject
{
    Q_OBJECT
public:

    Q_PROPERTY(QString name READ getName NOTIFY nameChanged WRITE setName)
    explicit NameCounter(const QString &name);
    explicit NameCounter();


    QString getName() const;
    void setName(const QString &newname);

signals:
    void nameChanged();


protected:
    void timerEvent(QTimerEvent * event);

private:
    int m_counter;
    QString m_name;
};

#endif // MYOBJECT_H
