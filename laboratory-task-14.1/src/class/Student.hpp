#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"


class Student final:public Person
{
private:
	int32_t course;
	int32_t group;

public:
	// Конструкторы 
	Student();
	Student(const char*, int32_t, int32_t);
	Student(const Student&);

	// Деструктор 
	~Student();

	// Set
	void setCourse(int32_t);
	void setGroup(int32_t);

	// Get
	int32_t getcourse();
	int32_t getGroup();

	// Перегрузка операторов ввода и вывода
	friend std::istream& operator >>(std::istream&, Student&);
	friend std::ostream& operator << (std::ostream&, const Student&);

	void print(std::ostream&) const override;
};

#endif // STUDENT_HPP
