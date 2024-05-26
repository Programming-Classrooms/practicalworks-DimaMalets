#include "Tree.hpp"

/* Конструктор с параметрами + по умолчанию */
Tree::Tree(Type treeT, std::string newName, size_t newAge):
typeTree(treeT),
name(newName),
age(newAge)
{}

/* Конструктор копирования */
Tree::Tree(const Tree & rhs):
typeTree(rhs.typeTree),
name(rhs.name),
age(rhs.age)
{}

/* Изменение типа дерева */
void Tree::setTypeTree(Type newType)
{
    this->typeTree = newType;
}

/* Изменение названия дерева */
void Tree::setName(std::string newName)
{
    this->name = newName;
}

/* Изменение возраста дерева */
void Tree::setAge(size_t newAge)
{
    this->age = newAge;
}

/* Получение типа дерева */
Type Tree::getTypeTree() const
{
    return this->typeTree;
}

/* Получение названия дерева */
std::string Tree::getName() const
{
    return this->name;
}

/* Получение возраста дерева */
size_t Tree::getAge() const
{
    return this->age;
}

std::ostream &Tree::print(std::ostream & out)
{
    out << "Type: " << (this->typeTree == Type::Coniferous?"Coniferous":"Deciduous") << std::endl;
    out << "Name: " << this->name << std::endl;
    out <<"\nAge: " << this->age << std::endl;
    return out;
}
