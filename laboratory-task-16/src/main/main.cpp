#include "../TDeque/TDeque.hpp"
#include "../Car/Car.hpp"

int main()
{
    try
    {
        TDeque<CarUnderReraip> a;
        CarUnderReraip first;
        first.manualFill();
        CarUnderReraip second("bmw",1000,"test",100);

        a.InsRear(first);
        a.InsFront(second);

        std::cout << "\n";
        a.exportInStream(std::cout);

        TDeque<CarUnderReraip> b;
        b = a;

        std::cout << "\n" << b[1].Info.getCarBrand();

        return 0;
    }
    catch(std::invalid_argument e)
    {
        std::cout << e.what();
    }
}
