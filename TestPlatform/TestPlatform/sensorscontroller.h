#ifndef SENSORSCONTROLLER_H
#define SENSORSCONTROLLER_H

#include "Inputs.h"
#include <QObject>

class SensorsController : public QObject
{
    Q_OBJECT
public:
    explicit SensorsController(Sensors *sensor, QObject *parent = nullptr);
    Sensors *createSensor();
    bool deleteSensor(Sensors *sensor);

signals:

public slots:

private:

    Sensors *m_sensor;

};

#endif // SENSORSCONTROLLER_H
