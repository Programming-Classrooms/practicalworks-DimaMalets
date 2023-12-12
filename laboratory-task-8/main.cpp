#include <iostream>
#include "Header.h"

//6. Строка состоит из слов, разделённых знаками препинания. За одинпросмотр символов строки найти все самые длинные слова и занести их в
//новую строку. Слова в новой строке должны разделяться ровно однимпробелом.

int main() {
	std::string line;
	size_t counter = 0;
	size_t reserveCounter = 0;
	std::string newLine;
	std::string delim = " /.,:;'  ";
	inputAndCheckLine(line);
	searchWords(line, delim, newLine, counter, reserveCounter);
	std::cout << newLine;
}
