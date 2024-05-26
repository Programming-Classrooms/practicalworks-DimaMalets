#include "FruitTree.hpp"

/* Конструктор с параметрами + по умолчанию */
FruitTree::FruitTree(
 Type treeT,
 std::string newName,
 size_t newAge,
 size_t newMass,
 size_t newDuration):
 Tree(treeT,newName,newAge),
 massCrop(newMass),
 durationStorage(newDuration)
{}

/* Конструктор копирования */
FruitTree::FruitTree(const FruitTree & rhs):
Tree(rhs),
massCrop(rhs.massCrop),
durationStorage(rhs.durationStorage)
{}

/* Изменение массы урожая */
void FruitTree::setMassCrop(size_t newMass)
{
    this->massCrop = newMass;
}

/* Изменение средней продолжительности хранения */
void FruitTree::setDurationStorage(size_t newDuration)
{
    this->durationStorage = newDuration;
}

/* Получение массы урожая */
size_t FruitTree::getMassCrop()
{
    return this->massCrop;
}

/* Получение средней продолжительности хранения */
size_t FruitTree::getDurationStorage()
{
    return this->durationStorage;
}

/* Вывод в поток */
std::ostream &FruitTree::print(std::ostream &out)
{
    Tree::print(out);
    out << "Mass of the crop: " << this->massCrop << std::endl;
    out << "Duration of storage: " << this->durationStorage << std::endl;
    return out;
}
