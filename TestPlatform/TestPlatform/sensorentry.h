#ifndef SENSORENTRY_H
#define SENSORENTRY_H

#include <QObject>
#include <QString>

class SensorEntry: private QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sensorType READ sensorType WRITE setSensorType NOTIFY sensorTypeChanged);

public:
    explicit SensorEntry(QObject *parent = nullptr);

    QString sensorType() const;
    void setSensorType(const QString &sensorType);

    SensorEntry();
signals:

    void sensorChanged();

public slots:

private:

    QString m_sensorType;

};

#endif // SENSORENTRY_H
