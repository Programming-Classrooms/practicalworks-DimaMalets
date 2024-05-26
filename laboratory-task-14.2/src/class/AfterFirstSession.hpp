#ifndef AFTERFIRSTSESSION_HPP
#define AFTERFIRSTSESSION_HPP

#include "Student2.hpp"

class StudentAfterFirstSession:public Student
{
protected:
    int16_t arrayMarks[4];
public:
    // Конструкторы 
    StudentAfterFirstSession() = delete;
    StudentAfterFirstSession(std::string,int16_t,int16_t,const int16_t,int16_t*);
    StudentAfterFirstSession(const StudentAfterFirstSession&);

    // Деструктор
    ~StudentAfterFirstSession();

    //Set-метод
    void setMarks(int16_t*);

    //Get-метод
    int16_t* getMarks();

    // Получение среднего балла
    virtual double getAverageMark();

    // Вывод
    virtual void print(std::ostream&)const  override;

    //Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream&, const StudentAfterFirstSession&);
};
#endif //AfterFirstSession.hpp
