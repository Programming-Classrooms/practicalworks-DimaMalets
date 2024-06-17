#include "../func/Function.hpp"


int main()
{
    try{
    srand(time(0));
    int16_t rows; 
    int16_t columns;
    /* 
        Заполнение размерности матрицы
    */
    fillSize(rows,columns);

    std::vector<std::vector<int>> mtrx(rows,std::vector<int>(columns));

    /* 
        Заполнение матрицы случайными числами в заданном диапазоне 
    */
    fillMatrixRandom(mtrx,rows,columns);

    /* 
        Удалить строку и столбец, на пересечении которых стоит максимальный
        элемент матрицы (первый из найденных)
    */
    deleteMax(mtrx,rows,columns);

    /* 
        Упорядочить строки матрицы по возрастанию сумм элементов строк 
    */
     newSort(mtrx,rows,columns);

    return 0;
    }

    catch(std::invalid_argument e)
    {
        std::cout << e.what();
    }
}
