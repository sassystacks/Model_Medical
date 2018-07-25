#include "Inputs.h"

Sensors::Sensors()
{

}


Sensors::Sensor Sensors::sensor() const
{
    return m_sensor;
}

SensorEntry *Sensors::createSensor()
{
    auto result = new SensorEntry(this);
    if (result != nullptr)
    {
        m_sensor.append(result);
        emit entryAdded(result);
    }
    return result;
}

bool Sensors::deleteSensor(SensorEntry *sensor)
{
    if (m_sensor.contains(sensor))
    {
        emit sensorRemoved(sensor);
        m_sensor.removeOne(sensor);
        delete sensor;
        return true;
    }
    return false;
}
