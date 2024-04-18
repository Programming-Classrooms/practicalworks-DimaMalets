#include "../func/Function.hpp"

int main(){

try{
    std::vector<std::string> container;

    /* Заполнение вектора */
    fillVector(container);

    /* Сортировка и печать вектора*/
    sortVector(container);

    /* Печать элементов списка, начинающихся на заданную букву */
    printByLetter(container);

    /* 
       Удаление элементов списка на заданную букву.
       Печать списка после удаления элементов. 
    */
    deleteByLetter(container);

    return 0;
}
catch(std::runtime_error e)
{
    std::cout << e.what();
}
}