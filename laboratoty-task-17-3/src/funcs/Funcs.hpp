#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <iostream>
#include <fstream>
#include <map>


/* Чтение из файла */
void readFile(std::multimap<std::string,int16_t>&, std::ifstream&);

/* Вывод всех слов с количеством повторений */
void printWords(std::multimap<std::string,int16_t>&);

/* Проверка файла */
bool checkFile(std::ifstream & in);
#endif // Funcs.hpp