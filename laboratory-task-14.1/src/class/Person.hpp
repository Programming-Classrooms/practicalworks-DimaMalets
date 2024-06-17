#ifndef PERSON_HPP
#define PERSON_HPP
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


class Person
{
protected:
	char* fullName;
public:

	// Конструкторы 
	Person();
	Person(const char*);
	Person(const Person&);

	// Деструктор
	 virtual ~Person();

	// Set
	void setFullName(const char*);

	// Get
	const char* getInfo() const;

	// Перегрузка операторов ввода и вывода
	friend std::istream& operator >>(std::istream&, Person&);
	friend std::ostream& operator <<(std::ostream&, const Person&);

	virtual void print(std::ostream&)const;

};

#endif // PERSON_HPP
