#include "ListBus.hpp"

// Заполнение из файла
void ListBus::fillFromFile(std::ifstream &in)
{
    Bus temp;
    while(in)
    {
        temp.readFile(in);
        MyListBus.push_back(temp);
    }
    
}

// Геттер
std::list<Bus> ListBus::getMyListBus()
{
    return this->MyListBus;
}

// Смена автобуса
void ListBus::renameBus
    (
    int32_t iRoute,
    std::string iDriver,
    int32_t iBusNumber,
    std::string iBusBrand
    )
{
    std::cout << "\nКакой по номеру автобус вы хотите изменить: ";
    int16_t number;
    std::cin >> number;
    Bus temp(iRoute,iDriver,iBusNumber,iBusBrand);
    bool flag = true;
    for(const auto& elem: this->MyListBus)
    {
        if(elem.getBusNumber() == number)
        {
            MyListBus.remove(elem);
            MyListBus.push_back(temp);
            flag = false;
        }
    }
    if(flag)
    {
        std::cout  << "Автобусов с таким номером нет";
    }
}

// Компаратор
bool cmp(const Bus& a,  const Bus&b)
{
    if(a.getBusNumber() < b.getBusNumber())
    {
        if(a.getBusRoute() < b.getBusRoute())
        {
            return true;
        }
    }
    return false;
}

//Сортировка по номеру автобуса и номеру маршрута
void ListBus::sortByNumberBusAndBusRoute()
{
    MyListBus.sort(cmp);
}
