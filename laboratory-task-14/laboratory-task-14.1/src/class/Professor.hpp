#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Person.hpp"
#include <cstring>


class Professor final: public Person
{

private:
	char* nameDep;

public:
	// Конструкторы
	Professor();
	Professor(const char*,const char*);
	Professor(const Professor&);

	// Деструктор
	~Professor();

	// Set
	void setNameDep(const char*);

	// Get
	const char* getNameDep();

	// Перегрузка операторов ввода и вывода
	friend std::ostream&operator<<(std::ostream&, const Professor&);
	friend std::istream& operator>>(std::istream& , Professor& );

	void print(std::ostream&) const override;

};

#endif //PROFESSOR_HPP
