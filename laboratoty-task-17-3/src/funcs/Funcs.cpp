#include "Funcs.hpp"

void readFile(std::multimap<std::string,int16_t>& myMap,std::ifstream& in)
{
    std::string word;
    int16_t counter = 0;
    while(in >> word)
    {
        ++counter;
        for(size_t i = 0; i < word.size(); ++i)
        {
            tolower(word[i]);
        }
        myMap.emplace(std::make_pair(word,counter));
    }

}

void printWords(std::multimap<std::string,int16_t>& myMap)
{

   std::multimap <std::string, int16_t> :: const_iterator firstIt = myMap.begin();      
   std::multimap <std::string, int16_t> :: const_iterator temp = myMap.begin();
   std::multimap <std::string, int16_t> :: const_iterator endIt = myMap.end();
   auto range = myMap.equal_range(firstIt->first);
   int16_t counter = 0;
   while(firstIt != endIt)
   {
    ++counter;
    ++temp;
    if(firstIt->first!= temp->first){
    std::cout << "Слово: " << firstIt->first <<" - количество повторений: "<< counter <<"\n";
    counter = 0;
    }
    ++firstIt;
   }
}

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