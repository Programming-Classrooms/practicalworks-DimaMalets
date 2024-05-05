#include "../class/TDeque.hpp"



int main()
{
    TDeque<int> a;
    a.InsFront(5);
    a.InsFront(6);
    a.InsRear(7);
    a.Print();
}