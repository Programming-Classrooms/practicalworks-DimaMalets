#include "../funcs/Funcs.hpp"

int main()
{
    try{
    std::multimap<std::string,int16_t> myMap;
    std::ifstream in ("src/files/text.txt");
    checkFile(in);
    readFile(myMap,in);
    printWords(myMap);
    return 0;
    }
    catch(std::invalid_argument e)
    {
        std::cout << e.what();
    }
    catch(std::ios_base::failure e)
    {
        std::cout << e.what();
    }
    catch(std::runtime_error e)
    {
        std::cout << e.what();
    }
}
