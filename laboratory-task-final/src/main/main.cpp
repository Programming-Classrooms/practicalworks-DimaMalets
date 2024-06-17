#include "../ListBus/ListBus.hpp"

#include <map>
#include <set>


// Проверка файла
void checkFile(std::ifstream& file) 
{
    if(!file.is_open())
    {
        throw std::runtime_error ("Указанный файл не открылся");

    }

    if(!file.good())
    {
        throw std::runtime_error ("Файл поврежден");
        
    }

    if(!file.peek() == EOF)
    {
        throw std::invalid_argument ("Файл пустой");
        
    }
}

int main()
{
    try
    {
        std::ifstream in ("src/files/Info.txt");
        checkFile(in);
        //Работа со списком
        ListBus myListBus;
        myListBus.fillFromFile(in);
        in.close();
        myListBus.sortByNumberBusAndBusRoute();

        //Перенос в map
        std::map<int32_t,Bus> myMapBus;
        for(const auto& elem:  myListBus.getMyListBus())
        {
            int32_t number = elem.getBusNumber();
            myMapBus.emplace(number,elem);
        }

        // Формирование списка различных маршрутов
        std::set<int32_t> listRoute;
        for(const auto& elem:  myMapBus)
        {
            int32_t route;
            route = elem.second.getBusRoute();
            listRoute.emplace(route);
        }

        // Вывод списка различных маршрутов
        std::cout << "Список различных маршрутов:\n ";
        for(const auto& elem:  listRoute)
        {
            std::cout << elem << " ";
        }

         myListBus.renameBus(190,"Плакич", 100, "Нормалдакич");

/*   Не знаю, что с выводом в переменных всё хранится корректно   */

        // for(const auto& elem: myListBus.getMyListBus())
        // {
        //     std::cout << elem <<"\n";
        // }

        return 0;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
}
