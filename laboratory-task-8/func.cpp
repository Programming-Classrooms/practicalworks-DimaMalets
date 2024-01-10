#include <iostream> 
#include <string> 
#include "Header.hpp" 
 

void inputAndCheckLine(std::string& line) 
{ 
 std::cout << "Enter the line \n"; 
 getline(std::cin, line); 

 if (line.empty() == true) { 
  std::cout << "Line is empty"; 
 } 
} 
 
void createNewLine(std::string word, std::string& newLine, size_t& counter, size_t& reserveCounter) 
{ 
    counter = word.length(); 
    if (counter >=  reserveCounter) { 
        newLine = newLine + word + ' '; 
        reserveCounter = counter; 
    } 
} 
 
void searchWords(std::string line, std::string delim,std::string& newLine, size_t& counter, size_t& reserveCounter)  
{ 
    std::string::size_type begInd; 
    std::string word; 
    
    begInd = line.find_first_not_of(delim); 
    while (begInd != std::string::npos) { 
        std::string::size_type endInd; 
        endInd = line.find_first_of(delim, begInd); 
        if (endInd == std::string::npos) { 
            endInd = line.length(); 
        } 
        word = line.substr(begInd, endInd - begInd); 
        createNewLine(word, newLine, counter, reserveCounter); 
        begInd = line.find_first_not_of(delim, endInd); 
    } 
}
