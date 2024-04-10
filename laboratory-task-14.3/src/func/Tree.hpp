#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

enum class Type
{
    Coniferous,
    Deciduous   
};


class Tree
{
protected:

Type typeTree;
std::string name;
size_t age;

public:

// Конструкторы
Tree(Type = Type::Deciduous, std::string = "", size_t = 0);
Tree(const Tree&);

// Деструктор 
~Tree() = default;

// Set-методы
void setTypeTree(Type) ;
void setName(std::string);
void setAge(size_t);

// Get-методы
Type getTypeTree() const;
std::string getName() const;
size_t getAge() const;

// Вывод в поток
 virtual std::ostream& print (std::ostream&) = 0;
};



#endif // Tree.hpp