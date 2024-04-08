#ifndef STUDENT2_HPP
#define STUDENT2_HPP

#include <iostream>
#include <string>

class Student
{

	protected:

	 static  int16_t counter;
	 const int16_t ID;
	 std::string name;
 	 int16_t course;
	 int16_t group;
	 const int16_t creditNumber;

	public:
	 //Конструкторы
	 Student() = delete;
	 Student(std::string,int16_t,int16_t,const int16_t);
	 Student(const Student&);

	 // Деструктор
	  virtual ~Student(){};

	  // Set-методы
	  void setGroup(int16_t);
	  void setCourse(int16_t);
	  void setName(std::string);

	  // Get-методы
	  int16_t getID()const;
	  std::string getName()const;
	  int16_t getCourse() const;
	  int16_t getGroup() const;
	  int16_t getCreditNumber() const;
	  

};

#endif // STUDENT2_HPP
