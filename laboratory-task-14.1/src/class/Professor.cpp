#include "Professor.hpp"


/* Конструктор по умолчанию */
Professor::Professor():
	Person(),
	nameDep(nullptr)
{}

/* Конструктор с параметрами */
Professor::Professor(const char* fullName,const char* Department):Person(fullName)
{
	this->nameDep = new char[strlen(Department) + 1];
	strcpy(nameDep, Department);
}

/* Конструктор копирования */
Professor::Professor(const Professor& rhs):Person(rhs)
{
	if (rhs.nameDep) {
		this->nameDep = new char[strlen(rhs.nameDep) + 1];
		strcpy(this->nameDep, rhs.nameDep);
	}
	else {
		this->nameDep = nullptr;
	}
}

/* Деструктор */
Professor::~Professor()
{}

/* Set-метод */
void Professor::setNameDep(const char* rhs)
{
	delete[] this->nameDep;
	nameDep = new char[strlen(rhs) + 1];
	strcpy(this->nameDep, rhs);
}

/* Get-метод */
const char* Professor::getNameDep()
{
	Professor copy(*this);
	return copy.nameDep;
}


void Professor::print(std::ostream & out) const
{
	out<<*this;
}

/* Перегрзука оператора вывода */
std::ostream& operator<<(std::ostream& out, const Professor& rhs)
{
	rhs.Person::print(out);
	out << '\n'<<"Name Department: " << rhs.nameDep;
	return out;
}

/* Перегрузка оператора ввода */
std::istream& operator>>(std::istream& in, Professor& rhs)
{
	in >> *((Person*)&rhs);
	std::cout << "Enter --> Name Department \n";
	char buffer[2048];
	in >> buffer;
	if (rhs.nameDep) {
		delete[] rhs.nameDep;
		rhs.nameDep = nullptr;
	}
	rhs.nameDep = new char[strlen(buffer) + 1];
	strcpy(rhs.nameDep, buffer);
	return in;
}
