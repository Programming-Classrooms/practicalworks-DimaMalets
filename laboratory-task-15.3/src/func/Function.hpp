#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

/* Заполнение вектора */
void fillVector(std::vector<std::string>&);

/* Сортировка и печать вектора*/
void sortVector(std::vector<std::string>&);

/* Печать элементов списка, начинающихся на заданную букву */
void printByLetter(std::vector<std::string>&);

/* 
   Удаление элементов списка на заданную букву;
   Печать списка после удаления элементов.
*/
void deleteByLetter(std::vector <std::string>&);

void checkFile(std::fstream&);

#endif //Function.hpp