#include "ContainerTrees.hpp"

/* Конструктор по умолчанию */
ContainerTrees::ContainerTrees(size_t size):
arrTrees(std::vector<Tree*>(size,nullptr))
{}

/* Получение размера вектора */
size_t ContainerTrees::getSize()
{
    return this->arrTrees.size();
}

/* Счтчик определенного типа деревьев */
size_t ContainerTrees::countingTypesEnum(Type seekType) const
{
    size_t counter = 0;
    for(size_t i = 0; i < this->arrTrees.size();++i){
        if(arrTrees[i]->getTypeTree() == seekType){
            ++counter;
        }
    }
    return counter;
}

/* Счтчик определенного вида деревьев */
size_t ContainerTrees::countingTypes(Tree * seekType) const
{
    size_t counter = 0;
    if(dynamic_cast<ForestTree*>(seekType)){
        for(size_t i = 0; i < this->arrTrees.size();++i){
            if(dynamic_cast<ForestTree*>(arrTrees[i])){
                ++counter;
            }
        }
        return counter;
    }
    if(dynamic_cast<FruitTree*>(seekType)){
        for(size_t i = 0; i < this->arrTrees.size();++i){
            if(dynamic_cast<FruitTree*>(arrTrees[i])){
                ++counter;
            }
        }
        return counter;
    }
}

/* Вывод в поток */
std::ostream &ContainerTrees::print(std::ostream & out)
{
    for(size_t i =0 ; i < this->arrTrees.size();++i){
        if(arrTrees[i] != nullptr){
            arrTrees[i]->print(out);
        }
        out << "\n**********************\n";
    }
    return out;
}

/* Компаратор */
bool ContainerTrees::compare(Tree * firstTree, Tree * secondTree)
{
    std::string firstName = firstTree->getName();
    std::string secondName = secondTree->getName();
    if ((firstName < secondName)) 
    {
        return true;
    }
    else if(firstName == secondName) 
    {
        if(firstTree->getAge() > secondTree->getAge())
        { 
         return true;
        }
    }

    return false;
}

/* Вывод отсортированного вектора */
std::ostream &ContainerTrees::sortPrint(std::ostream & out)
{
    std::vector<Tree*> copy = this->arrTrees;
    std::sort(copy.begin(),copy.end(),compare);
    for(size_t i =0; i < this->arrTrees.size();++i){
        if(copy[i] != nullptr){
        copy[i]->print(out);
        out << "\n*****************\n";
        }
    }
    return out;
}

/* Добавление дерева в вектор */
void ContainerTrees::addTree(Tree * temp)
{
    this->arrTrees.push_back(temp);
}

/* Чтение данных из файла */
void ContainerTrees::readFile(std::istream & in)
{
    std::string typeEnum;
    std::string name;
    size_t age;
    std::string type;
    std::string tempCon = "Coniferous";
    std::string tempDec =  "Decidious";
    size_t woodAmount;
    size_t cropMass;
    size_t storageDuration;
    Tree* newTree = nullptr;

    while(in >> typeEnum) {
        if((typeEnum == tempCon) || (typeEnum == tempDec)) {
            in >> name;
            in >> age;
            in >> type;
            if (type == "Forest" || type == "forest") {
                in >> woodAmount;
                newTree = new ForestTree((type == tempCon ? Type::Coniferous : Type::Deciduous),name, age, woodAmount);
                addTree(newTree);
            }   
            else if (type == "Fruit" || type == "fruit") {
                in >> cropMass;
                in >> storageDuration;
                newTree = new FruitTree((type == tempCon ? Type::Coniferous : Type::Deciduous),name, age, cropMass, storageDuration);
                addTree(newTree);
            }
            else {
                throw std::invalid_argument("Invalid argument !!!");
            }
        }
        else {
            throw std::invalid_argument("Invalid argument !!!");
        }
    }
}
