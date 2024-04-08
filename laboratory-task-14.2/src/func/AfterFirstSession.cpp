#include "AfterFirstSession.hpp"

/* Конструктор с параметрами */
StudentAfterFirstSession::StudentAfterFirstSession(
    std::string name,
     int16_t cours,
     int16_t gr,
     const int16_t creditNum,
     int16_t * marks):Student(name,cours,gr,creditNum)  
    {   
        for(size_t i = 0; i < 4; ++i){
            this->arrayMarks[i] = marks[i];
        }
    }

/* Конструктор копирования */
StudentAfterFirstSession::StudentAfterFirstSession(const StudentAfterFirstSession &rhs):Student(rhs)
{
    for(size_t i = 0; i < 4; ++i){
        this->arrayMarks[i] = rhs.arrayMarks[i];
    }
}

/* Деструктор */
StudentAfterFirstSession::~StudentAfterFirstSession()
    {
    }

/* Изменение массива отметок */
void StudentAfterFirstSession::setMarks(int16_t * newArr)
{
    for(size_t i = 0; i < 4; ++i){
        this->arrayMarks[i] = newArr[i];
    }
}

/* Получение массива отметок */
int16_t *StudentAfterFirstSession::getMarks()
{
    int16_t copy[4];
    for(size_t i =0; i < 4; ++i){
        copy[i] = this->arrayMarks[i];
    }
    return copy;}

/* Получение среднего балла */
double StudentAfterFirstSession::getAverageMark()
{
    double average =0;
    for(size_t i =0; i < 4;++i){
        average +=this->arrayMarks[i];
    }
    average/=4;
    return average ;
}

/* Вывод */
void StudentAfterFirstSession::print(std::ostream &out) const
{
    out << * this;
}

/* Перегрузка оператора вывода */
std::ostream &operator<<(std::ostream & out, const StudentAfterFirstSession & rhs)
{
    rhs.Student::print(out);
    out << "\nFirst mark: " << rhs.arrayMarks[0]<<'\n';
    out << "Second mark: " << rhs.arrayMarks[1]<<'\n';
    out << "Third mark: " << rhs.arrayMarks[2]<<'\n';
    out << "Fourth mark: " << rhs.arrayMarks[3]<<'\n';
    return out;
}
