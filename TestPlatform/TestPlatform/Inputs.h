#ifndef SENSORS_H
#define SENSORS_H

#include "sensorentry.h"

#include <QObject>
#include <QList>

class Sensors: public QObject

{
    Q_OBJECT

public:

    typedef QList<SensorEntry*> SensorList;
    explicit Sensors(QObject *parent = nullptr);
    Sensor sensor() const;

    SensorEntry* createSensor();
    bool deleteSensor(SensorEntry *sensor);

signals:

    void sensorAdded(SensorEntry *sensor);
    void sensorRemoved(SensorEntry *sensor);

public slots:


private:

    SensorList m_sensor;

};

#endif // SENSORS_H
