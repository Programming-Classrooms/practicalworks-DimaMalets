#include "AfterYear.hpp"

/* Конструктор копирования */
StudentAfterYear::StudentAfterYear(
    std::string name,
     int16_t cours,
     int16_t gr,
     const int16_t creditNum,
     int16_t * marks,
     int16_t* marksYear):StudentAfterFirstSession(name,cours,gr,creditNum,marks)
{
    for(size_t i = 0; i < 5; ++i){
    this->arrMarksAfterYear[i] = marksYear[i];
    }
}

/* Конструктор копирования */
StudentAfterYear::StudentAfterYear(const StudentAfterYear & rhs):StudentAfterFirstSession(rhs)
{
    for(size_t i = 0; i < 5; ++i){
        this->arrMarksAfterYear[i] = rhs.arrMarksAfterYear[i];
    }
}

/* Деструктор */
StudentAfterYear::~StudentAfterYear()
{}

/* Изменение отметок */
void StudentAfterYear::setMarks(int16_t * newMarks)
{
    for(size_t i =0; i < 5;++i){
        this->arrMarksAfterYear[i] =newMarks[i]; 
    }
}

/* Получение отметок */
int16_t *StudentAfterYear::getMarks()
{
    int16_t copy[5];
    for(size_t i =0; i < 5; ++i){
        copy[i] = this->arrayMarks[i];
    }
    return copy;
}

/* Получение среднего балла */
double StudentAfterYear::getAverageMark()
{
    double  average = StudentAfterFirstSession::getAverageMark();
    double averageSecond =0;
    for(size_t i =0; i < 5;++i){
        averageSecond +=this->arrMarksAfterYear[i];
    }
    averageSecond/=5;

    return (average +averageSecond)/2 ;
}

/* Вывод */
void StudentAfterYear::print(std::ostream & out) const
{
    out << *this;
}

/* Перегрузка оператора вывода */
std::ostream &operator<<(std::ostream & out, const StudentAfterYear & rhs)
{
    rhs.StudentAfterFirstSession::print(out);
    out << '\n' << "********************\n"; 
    out << "\nFirst mark: " << rhs.arrMarksAfterYear[0]<<'\n';
    out << "Second mark: " << rhs.arrMarksAfterYear[1]<<'\n';
    out << "Third mark: " << rhs.arrMarksAfterYear[2]<<'\n';
    out << "Fourth mark: " << rhs.arrMarksAfterYear[3]<<'\n';
    out << " Fifth mark: " << rhs.arrMarksAfterYear[4] << '\n';
    return out;
}
