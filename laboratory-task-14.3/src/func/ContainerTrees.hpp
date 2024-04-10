#ifndef CONTAINERTREES_HPP
#define CONTAINERTREES_HPP

#include "ForestTree.hpp"
#include "FruitTree.hpp"
#include <vector>
#include<algorithm>
#include <fstream>

class ContainerTrees
{
private:
std::vector<Tree*>arrTrees;

public:

// Конструктор
ContainerTrees(size_t =0);

// Деструктор 
~ContainerTrees() = default;

//Get-метод
size_t getSize();

// Методы для подсчета количества 
size_t countingTypesEnum(Type) const;
size_t countingTypes(Tree*) const;

// Вывод в поток
std::ostream& print (std::ostream&);

// Компаратор
 static bool compare(Tree*,Tree*);

// Вывод с сортировкой
std::ostream& sortPrint(std::ostream&);

// Добавление дерева в вектор
void addTree(Tree*);

// Чтение из файла
void readFile(std::istream&);
};
#endif // ContainerTrees.hpp
