#ifndef BUS_HPP
#define BUS_HPP

#include <string>
#include <fstream>
#include <iostream>

class Bus
{

private:

int32_t busRoute; // номер маршрута
std::string driver; // водитель
int32_t busNumber; // номер автобуса
std::string busBrand; // марка автобуса

public:

// Конструкторы
Bus() = default;
Bus(int32_t iBusRoute, std::string iDriver, int32_t iBusNumber, std::string iBusBrand);
Bus(const Bus & rhs);

// Деструктор
~Bus() = default;

// Геттеры
int32_t getBusRoute() const;
std::string getDriver() const;
int32_t getBusNumber() const;
std::string getBusBrand() const;


// Сеттеры

void setBusRoute(int32_t iBusRoute);
void setDriver(std::string iDriver);
void setBusNumber(int32_t iBusNumber);
void setBusBrand(std::string iBusBrand);

// Чтение из файла
void readFile(std::ifstream& in);

// Перегрузка операторов сравнения
bool operator <(const Bus& rhs) const;
bool operator ==(const Bus& rhs) const;

// Перегрузка вывода
friend  std::ostream & operator << (std::ostream& out, const Bus& rhs);

};


#endif // Bus.hpp
