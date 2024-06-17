#include "../TDeque/TDeque.hpp"
#include "../Car/Car.hpp"

int main()
{
    try
    {
        TDeque<CarUnderReraip> carDeque;
        
        CarUnderReraip car1("Toyota", 1500.0, "Engine failure", 5);
        CarUnderReraip car2("Honda", 1200.0, "Transmission issues", 3);
        CarUnderReraip car3("BMW", 2500.0, "Suspension repair", 7);
        CarUnderReraip car4("Audi", 1800.0, "Brake issues", 4);

        carDeque.InsFront(car1);
        carDeque.InsRear(car2);
        carDeque.InsFront(car3);
        carDeque.InsRear(car4);

        carDeque.DelFront();
        carDeque.DelRear();

        std::cout << "Элемент с индексом 0:\n" << carDeque.GetByIndex(0) << "\n\n";
        std::cout << "Элемент с индексом 1:\n" << carDeque.GetByIndex(1) << "\n\n";

        carDeque.SetByIndex(CarUnderReraip("Tesla", 3000.0, "НОРМАЛДАКИЧ", 8), 0);

        carDeque.BrowseWithModification([](CarUnderReraip& car) {
        car.setRepairPrice(car.getrepairPrice() * 0.9);});

        carDeque.BrowseWithoutModification([](const CarUnderReraip& car) {
        std::cout << car << "\n";});

        
        return 0;
    }
    catch(std::invalid_argument e)
    {
        std::cout << e.what();
    }
}
