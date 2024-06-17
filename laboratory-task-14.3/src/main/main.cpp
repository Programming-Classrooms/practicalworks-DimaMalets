#include "../class/ContainerTrees.hpp"

/* Проверка файла */
bool checkFile(std::ifstream & in)
{
    if (!in.good()) {
		throw std::invalid_argument("File is not good !!!");
	}
	if (!in) {
		throw std::ios_base::failure("File is bad !!!");
	}
	if (in.peek() == EOF) { 
		throw std::runtime_error("File is empty !!!");
	}
	return true;
}


int main()
{
 	try
 	{
		std::ifstream in ("src/files/ForTrees.txt");
	    if(checkFile(in))
		{
			ContainerTrees container;
			container.readFile(in);
			container.print(std::cout);
			FruitTree* seekFruit = new FruitTree;
			ForestTree* seekForest = new ForestTree;
			std::cout << std::endl << "Coniferous: "<< container.countingTypesEnum(Type::Coniferous);
			std::cout << std::endl << "Deciduous: "<< container.countingTypesEnum(Type::Deciduous);
			std::cout << std::endl <<  "count Fruit: " <<container.countingTypes(seekFruit);
			std::cout << std::endl <<  "count Forest: " <<container.countingTypes(seekForest) << '\n';
			container.sortPrint(std::cout);
		}
  	 return 0;
	}
	catch(std::invalid_argument  e)
	{
     std::cout << e.what();
	}
	catch(std::runtime_error e)
	{
     std::cout << e.what();
	}
	catch(std::ios_base::failure e)
	{
     std::cout << e.what();
	}
}
