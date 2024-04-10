#include "../func/ContainerTrees.hpp"

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


int main(){
 try
 {
    std::ifstream in ("src/files/ForTrees.txt");
  if(checkFile(in)){

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
