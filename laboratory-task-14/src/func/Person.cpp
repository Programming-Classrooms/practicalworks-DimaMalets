#include "Person.hpp"

#include <cstring>
#include <string>


/* Конструктор по умолчанию */
Person::Person():fullName(nullptr)
{}

/* Конструктор с параметрами */
Person::Person(const char* fullName)
{
	this->fullName = new char[strlen(fullName)+1];
	strcpy(this->fullName, fullName);
}

/* Конструктор копирования */
Person::Person(const Person&rhs)
{
	if (rhs.fullName) {
		this->fullName = new char[strlen(rhs.fullName) + 1];
		strcpy(this->fullName, rhs.fullName);
	}
	else {
		this->fullName = nullptr;
	}
}

/* Деструктор */
Person::~Person()
{
	delete[] this->fullName;
}

/* Set-метод */
void Person::setFullName(const char* rhs)
{
	delete[] fullName;
	this->fullName = new char[strlen(rhs) + 1];
	strcpy(fullName, rhs);
}

/* Get-метод */
const char* Person::getInfo() const
{
	char* copy = new char[strlen(fullName) + 1];
	strcpy(copy, fullName);
	return copy ;
}


void Person::print(std::ostream & out) const
{
	out << *this;
}

/* Перегрузка оператора ввода */
std::istream& operator>>(std::istream& in,  Person& rhs)
{
	std::cout << "Enter --> Suname \n";
	char buffer[2048];
	in >> buffer;
	std::cout << "Enter --> Name \n";
	char buffer2[2048];
	in >> buffer2;
	if (rhs.fullName) {
		delete[] rhs.fullName;
		rhs.fullName = nullptr;
	}
	rhs.fullName = new char[strlen(buffer) + strlen(buffer2) +1];
	strcpy(rhs.fullName, buffer);
	strcat(rhs.fullName," ");
	strcat(rhs.fullName,buffer2);
	return in;
}

/* Перегрзука оператора вывода */
std::ostream& operator<<(std::ostream& out, const Person& rhs)
{
	if (rhs.fullName) {
		out <<"Fullname: " << rhs.fullName;
	}
	return out;
}
