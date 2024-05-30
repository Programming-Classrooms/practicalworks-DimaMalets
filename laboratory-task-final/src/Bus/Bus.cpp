#include "Bus.hpp"

// Конструктор с параметрами
Bus::Bus(
int32_t iBusRoute,
std::string iDriver,
int32_t iBusNumber,
std::string iBusBrand):

busRoute(iBusRoute),
driver(iDriver),
busNumber(iBusNumber),
busBrand(iBusBrand)
{}

// Конструктор копирования
Bus::Bus(const Bus &rhs):

busRoute(rhs.busRoute),
driver(rhs.driver),
busNumber(rhs.busNumber),
busBrand(rhs.busBrand)
{}


// ********* Геттеры *************
int32_t Bus::getBusRoute() const
{
    return this->busRoute;
}

std::string Bus::getDriver() const
{
    return this->driver;
}

int32_t Bus::getBusNumber() const
{
    return this->busNumber;
}

std::string Bus::getBusBrand() const
{
    return this->busBrand;
}

// ********* Сеттеры *************

void Bus::setBusRoute(int32_t iBusRoute)
{
    if(iBusRoute < 0)
    {
        throw std::invalid_argument ("Номе маршрута не может быть отрицательным числом!!");
    }
    else
    {
        this->busRoute = iBusRoute;
    }
}

void Bus::setDriver(std::string iDriver)
{
    this->driver = iDriver;
}

void Bus::setBusNumber(int32_t iBusNumber)
{
    if(iBusNumber < 0)
    {
        throw std::invalid_argument ("Номе автобуса не может быть отрицательным числом!!");
    }
    else
    {
        this->busNumber = iBusNumber;
    }
}

void Bus::setBusBrand(std::string iBusBrand)
{
    this->busBrand = iBusBrand;
}


// Чтение из файла
void Bus::readFile(std::ifstream &in)
{
   // checkFile(in);
    in >> this->busRoute;
    in >> this->driver;
    in >> this->busNumber;
    in >> this->busBrand; 

}

bool Bus::operator<(const Bus &rhs) const
{
    return this->getBusNumber() < rhs.getBusNumber();
}

bool Bus::operator==(const Bus &rhs) const
{
    return (this->busBrand == rhs.busBrand && this->busNumber == rhs.busNumber && this->busRoute == rhs.busRoute && this->driver == rhs.driver);
}

std::ostream &operator<<(std::ostream &out, const Bus &rhs)
{
    out << "\nНомер маршрута: " << rhs.getBusRoute();
    out << "\nВодитель: " << rhs.getDriver();
    out << "\nНомер автобуса : " << rhs.getBusNumber();
    out << "\nМарка автобуса: " << rhs.getBusBrand();

}
