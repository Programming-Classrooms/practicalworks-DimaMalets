#include "Student2.hpp"

int16_t Student::counter = 0;

Student::Student(std::string name, int16_t cours, int16_t gr, const int16_t creditNum):ID(++counter),course(cours),group(gr),creditNumber(creditNum)
{}

Student::Student(const Student & rhs):ID(++counter),course(rhs.course),group(rhs.group),creditNumber(rhs.creditNumber)
{}

void Student::setGroup(int16_t newGroup)
{
    this->group = newGroup;
}

void Student::setCourse(int16_t newCourse)
{
    this->course = newCourse;
}

void Student::setName(std::string newName)
{
    this->name = newName;
}
