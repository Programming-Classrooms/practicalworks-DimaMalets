#ifndef HEADER_HPP 
#define HEADER_HPP 


#include <iostream> 
 
 
void inputAndCheckLine(std::string& line); 
 
void searchWords(std::string line, std::string delim, std::string& newLine, size_t& counter, size_t& reserveCounter); 
 
void createNewLine(std::string word, std::string& newLine, size_t& counter, size_t& reserveCounter);

#endif //Header.hpp 
