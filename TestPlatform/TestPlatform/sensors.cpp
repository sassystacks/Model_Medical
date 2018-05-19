#include "sensors.h"

Sensors::Sensors()
{

}


Sensors::Sensor Sensors::sensor() const
{
    return m_sensor;
}

SensorEntry *Sensors::createSensor()
{
    auto result = new Sensor
}
