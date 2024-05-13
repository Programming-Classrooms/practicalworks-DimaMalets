#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

/*
     Заполнение матрицы случайными числами в заданном диапазоне 
*/
void fillSize(int16_t &, int16_t &);


/*
     Заполнение матрицы случайными числами в заданном диапазоне 
*/
void fillMatrixRandom(std::vector<std::vector<int>>&, int16_t, int16_t);

/* 
   Удалить строку и столбец, на пересечении которых стоит максимальный
   элемент матрицы 
*/
void deleteMax(std::vector<std::vector<int>>&, int16_t, int16_t);

/* 
    Упорядочить строки матрицы по возрастанию сумм элементов строк 
*/
void  newSort(std::vector<std::vector<int>>&, int16_t, int16_t);

#endif // Function.hpp
