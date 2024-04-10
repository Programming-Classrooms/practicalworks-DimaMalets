#include "ForestTree.hpp"

/* Конструктор с параметрами + по умолчанию */
ForestTree::ForestTree(
 Type treeT,
 std::string newName,
 size_t newAge,
 size_t newAmount):Tree(treeT,newName,newAge),amountWood(newAmount)
{}

/* Конструктор копирования */
ForestTree::ForestTree(const ForestTree & rhs):Tree(rhs),amountWood(rhs.amountWood)
{}

/* Изменение количества древесины */
void ForestTree::setAmountWood(size_t newAmount)
{
    this->amountWood = newAmount;
}

/* Получение количества древесины */
size_t ForestTree::getAmountWood()
{
    return this->amountWood;
}

/* Вывод в поток */
std::ostream &ForestTree::print(std::ostream &out)
{
    Tree::print(out);
    out << "Amount of Wood: " << this->amountWood << std::endl;
    return out;
}
