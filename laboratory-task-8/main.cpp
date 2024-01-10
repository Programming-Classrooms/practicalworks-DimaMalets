/* 
 6. Строка состоит из слов, разделённых знаками препинания.За один 
 просмотр символов строки найти все самые длинные слова и занести их в 
 новую строку.Слова в новой строке должны разделяться ровно одним 
 пробелом. 
*/ 
 
 
#include <iostream> 
#include "Header.hpp" 
 
 
int main() { 
    try{
     std::string line; 
     size_t counter = 0; 
     size_t reserveCounter = 0; 
     std::string newLine; 
     std::string delim = " /.,:;'  "; 
     inputAndCheckLine(line); 
     searchWords(line, delim, newLine, counter, reserveCounter); 
     std::cout << newLine; 
    }
     catch(std::exception e){
        std::cout << e.what();
    }
    return 0;
}
