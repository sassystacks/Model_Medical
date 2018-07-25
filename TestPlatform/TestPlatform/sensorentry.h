#ifndef SENSORENTRY_H
#define SENSORENTRY_H

#include <QObject>
#include <QString>

class SensorEntry: private QObject
{
    Q_OBJECT
    Q_PROPERTY(QString inputType READ inputType WRITE setInputType NOTIFY inputTypeChanged)

public:

    explicit SensorEntry(QObject *parent = nullptr);

    QString inputType() const;
    void setinputType(const QString &sensorType);

    SensorEntry();

signals:

    void inputTypeChanged();

public slots:

private:

    QString m_sensorType;

};

#endif // SENSORENTRY_H
