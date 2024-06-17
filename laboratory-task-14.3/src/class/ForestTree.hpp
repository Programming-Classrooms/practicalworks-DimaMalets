#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP

#include "Tree.hpp"

class ForestTree:public Tree
{
protected:

size_t amountWood;

public:

// Конструкторы 
ForestTree(Type = Type::Deciduous, std::string = "", size_t = 0,size_t = 0);
ForestTree(const ForestTree&);

// Деструктор
~ForestTree() = default;

//Set-метод
void setAmountWood(size_t);

//Get-метод
size_t getAmountWood();

// Вывод в поток
virtual std::ostream& print(std::ostream&) override;
};


#endif // ForestTree.hpp