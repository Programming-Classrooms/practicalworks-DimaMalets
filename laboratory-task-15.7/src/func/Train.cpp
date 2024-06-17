#include "Train.hpp"

/* Конструктор с параметрами */
Train::Train(
    int16_t num,
    std::string newDestinationName,
    typeTrain newType, 
    std::string depTime, 
    std::string timeIn):
    numTrain(num),
    destinationName(newDestinationName),
    type(newType),
    departureTime(depTime),
    timeInRoad(timeIn)
{}

typeTrain Train::getType()const
{
    return this->type;
}

std::string Train::getTimeInRoad() const
{
    return this->timeInRoad;
}

std::string Train::getDepTime() const
{
    return this->departureTime;
}

std::string Train::geDestantionName() const
{
    return this->destinationName;
}

Train& Train::operator=(const Train &rhs)
{
    this->numTrain = rhs.numTrain;
    this->departureTime = rhs.departureTime;
    this->destinationName = rhs.destinationName;
    this->type = rhs.type;
    this->timeInRoad = rhs.timeInRoad;
    return *this;
}

bool Train::operator<(const Train &rhs)
{
    return (this->getDepTime() < rhs.getDepTime());
}

std::ostream &operator<<(std::ostream & out, const Train & rhs)
{
    out << "\nНомер поезда: " << rhs.numTrain;
    out << "\nНазвание пункта назначения: " << rhs.destinationName;
    out << "\nТип поезда: " << (rhs.type == typeTrain::Fast? "Fast" : "Passenger");
    out << "\nВремя отправления: " << rhs.departureTime;
    out << "\nВремя в пути: " << rhs.timeInRoad;
    return out;
}
