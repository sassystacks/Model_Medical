#ifndef SENSORSCONTROLLER_H
#define SENSORSCONTROLLER_H

#include "sensors.h"
#include <QObject>

class SensorsController : public QObject
{
    Q_OBJECT
public:
    explicit SensorsController(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SENSORSCONTROLLER_H
