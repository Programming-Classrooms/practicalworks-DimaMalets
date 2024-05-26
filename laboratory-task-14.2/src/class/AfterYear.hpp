#ifndef AFTERYEAR_HPP
#define AFTERYEAR_HPP

#include "AfterFirstSession.hpp"

class StudentAfterYear:public StudentAfterFirstSession
{
private:

int16_t arrMarksAfterYear[4];

public:
// Конструкторы 
StudentAfterYear() = delete;
StudentAfterYear(std::string,int16_t,int16_t,const int16_t,int16_t*,int16_t*);
StudentAfterYear(const StudentAfterYear&);

// Деструктор
~StudentAfterYear();

//Set-метод
void setMarks(int16_t*);

//Get-метод
int16_t* getMarks();

// Получение среднего балла
 double getAverageMark();

//Вывод
void print(std::ostream&)const override;

//Перегрузка оператора вывода
friend std::ostream& operator<<(std::ostream&, const StudentAfterYear&);
};

#endif // AfteYear.hpp
