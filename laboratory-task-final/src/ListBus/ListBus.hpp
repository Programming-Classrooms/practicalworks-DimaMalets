#ifndef LISTBUS_HPP
#define LISTBUS_HPP

#include "../Bus/Bus.hpp"
#include <algorithm>
#include <list>

class ListBus
{

private:

std::list<Bus> MyListBus;

public:

// Конструкторы
ListBus() = default;

// Деструктор
~ListBus() = default;

// Добавление автобуса
void fillFromFile(std::ifstream& in);

// Геттер
std::list<Bus> getMyListBus();

// Смена автобуса
void renameBus(int32_t iRoute,
    std::string iDriver,
    int32_t iBusNumber,
    std::string iBusBrand);

// Сортировка по номеру автобуса и номеру маршрута
void sortByNumberBusAndBusRoute(); 

};

#endif // ListBus.hpp
