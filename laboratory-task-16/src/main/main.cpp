#include "../class/TDeque.hpp"


int main()
{
    try
    {
        TDeque<int> a;
        a.InsFront(5);
        a.InsFront(6);
        a.InsRear(7);
        a.InsRear(8);
        a.DelRear();
        a.Print();
        a.SetByIndex(30,2);
        TDeque<int> b;
        b = a;
        std::cout <<std::endl << b.GetByIndex(2);
        return 0;
    }
    catch(std::invalid_argument e)
    {
        std::cout << e.what();
    }
}
