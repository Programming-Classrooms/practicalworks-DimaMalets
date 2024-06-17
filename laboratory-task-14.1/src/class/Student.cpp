#include "Student.hpp"


/* Конструктор по умолчанию */
Student::Student():
	Person(),
	course(0),
	group(0)
{}

/* Конструктор с параметрами */
Student::Student(const char* FullNAme, int32_t cours, int32_t gr):
	Person(FullNAme),
	course(cours),
	group(gr)
{}

/* Конструктор копирования */
Student::Student(const Student&rhs):
	Person(rhs),
	course(rhs.course),
	group(rhs.group)
{}

/* Деструктор */
Student::~Student()
{}

/* Set-метод */
void Student::setCourse(int32_t rhsCourse)
{
	this->course = rhsCourse;
}

/* Set-метод */
void Student::setGroup(int32_t rhsGroup)
{
	this->group = rhsGroup;
}

/* Get-метод */
int32_t Student::getcourse()
{
	return this->course;
}

/* Get-метод */
int32_t Student::getGroup()
{
	return this->group;
}

void Student::print(std::ostream & out) const
{
	out<<*this;
}

/* Перегрузка оператора ввода */
std::istream& operator>>(std::istream& in, Student& rhs)
{
	in >> *((Person*)&rhs);
	std::cout << "\nEnter course = ";
	in >> rhs.course;
	std::cout << "\nEnter group = ";
	in >> rhs.group;
	return in;
}

/* Перегрзука оператора вывода */
std::ostream& operator<<(std::ostream& out, const Student& rhs)
{
	rhs.Person::print(out);
	out << "\nCourse: " << rhs.course << "\nGroup: " << rhs.group;
	return out;
}
