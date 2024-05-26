#ifndef FRUITTREE_HPP
#define FRUITTREE_HPP

#include "Tree.hpp"

class FruitTree:public Tree
{
protected:

size_t massCrop;
size_t durationStorage;

public:

// Конструкторы 
FruitTree(Type = Type::Deciduous, std::string = "", size_t = 0,size_t = 0,size_t = 0);
FruitTree(const FruitTree&);

// Деструктор
~FruitTree() = default;

//Set-метод
void setMassCrop(size_t);
void setDurationStorage(size_t);

//Get-метод
size_t getMassCrop();
size_t getDurationStorage();

// Вывод в поток
virtual std::ostream& print(std::ostream&) override;
};


#endif // FruitTree.hpp