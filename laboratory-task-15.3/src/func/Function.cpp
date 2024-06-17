#include"Function.hpp"


void checkFile(std::fstream& in)
{
    if(!in.good())
    {
        throw std::invalid_argument("File does not exist");
    }
    if(!in)
    {
       throw std::ios_base::failure("File is not open");
    }
    if(in.peek() == EOF)
    {
        throw std::runtime_error("File is empty");
    }
}

void fillVector(std::vector<std::string>& container)
{
    std::string pathToOutInTxt = "src/files/text.txt";
    std::fstream in(pathToOutInTxt);
    checkFile(in);
    std::string temp;
    while(in)
    {
        in >> temp;
        container.push_back(temp);
    }
    container.erase(container.end());

    std::cout << "Слова из файла: ";
    for(const auto& text: container)
    {
        std::cout << text << " ";
    }
}

void sortVector(std::vector<std::string>& container)
{
    std::sort(container.begin(),container.end());
    std::cout <<"\n\n***********************************************";
    std::cout << "\nОтсортированный массив\n";
    for(const auto& text: container)
    {
        std::cout << text << " ";
    }
}


void printByLetter(std::vector<std::string>& container)
{
    std::cout <<"\n\n***********************************************";
    std::cout << "\nВведите букву по которой нужно искать слова: ";
    char letter;
    std::cin >> letter;
    std::cout << "Слова на заданную букву: ";
    for(const auto& word : container){
        if(word[0] == letter){
            std::cout << word << " ";
        }
    }
}

void deleteByLetter(std::vector <std::string>& container)
{
    std::cout <<"\n\n***********************************************";
    std::cout << "\nВведите букву по которой нужно удалить слова: ";
    char letter;
    std::cin >> letter;
    std::string word;
    for(size_t i = 0; i < container.size();++i)
    {
        word = container[i];
        if(word[0] == letter){
            container.erase(container.begin()+i);
            i--;
        }
    }
    std::cout << "\nПреобразованный массив\n";
    for(const auto& text: container)
    {
        std::cout << text << " ";
    }
}
