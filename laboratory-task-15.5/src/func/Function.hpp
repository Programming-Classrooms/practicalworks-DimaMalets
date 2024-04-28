#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>


struct Student
{
    std::string surname;
    std::string name;
    std::string patronymic;
    int16_t group;
    int16_t course;
};

/* Создание массива студентов */
void fillList(Student*,int16_t &);

/* Вывод массива студентов */
void printList(Student*,int16_t);

/* Вывод в текстовый файл Fio.txt */
void createFIO(Student*, int16_t);

/* Вывод в текстовый файл Groups.txt */
void createGroups(Student*,int16_t);