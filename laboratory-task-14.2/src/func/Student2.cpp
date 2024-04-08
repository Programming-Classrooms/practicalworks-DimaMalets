#include "Student2.hpp"

int16_t Student::counter = 0;

/* Конструктор с параметрами */
Student::Student(std::string name, int16_t cours, int16_t gr, const int16_t creditNum) : ID(++counter), name(name),course(cours), group(gr), creditNumber(creditNum)
{}

/* Конструктор копирования */
Student::Student(const Student & rhs):ID(++counter),course(rhs.course),group(rhs.group),creditNumber(rhs.creditNumber)
{}

/* Изменение номера группы */
void Student::setGroup(int16_t newGroup)
{
    this->group = newGroup;
}

/* Изменение номера курса */
void Student::setCourse(int16_t newCourse)
{
    this->course = newCourse;
}

/* Изменение имени */
void Student::setName(std::string newName)
{
    this->name = newName;
}

/* Получение ID */
int16_t Student::getID() const
{
    return this->ID;
}

/* Получение имени */
std::string Student::getName() const
{
    return this->name;
}


/* Получение  номера курса */
int16_t Student::getCourse() const
{
    return this->course;
}

/* Получение номера группы */
int16_t Student::getGroup() const
{
    return this->group;
}

/* Получение номера зачётки */
int16_t Student::getCreditNumber() const
{
    return this->creditNumber;
}

/* Вывод */
void Student::print(std::ostream & out) const
{
    out <<*this;
}

/* Перегрузка оператора вывода */
std::ostream& operator<<(std::ostream & out, const Student & rhs)
{
    out << "ID: " << rhs.ID <<'\n' <<"Name: " << rhs.name << '\n' << "Course: ";
    out << rhs.course <<'\n' << "Group: " << rhs.group <<'\n'<<"Record number: "<<rhs.creditNumber;
    return out;
}
