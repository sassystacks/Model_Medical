#include "sensorentry.h"

SensorEntry::SensorEntry(QObject *parent) :QObject(parent)
{

}

QString SensorEntry::sensorType() const
{
    return m_sensorType;
}

