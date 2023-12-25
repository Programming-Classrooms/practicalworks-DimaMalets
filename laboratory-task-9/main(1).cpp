/*
	6. Задан текстовый файл input.txt. Требуется определить строки этого файла, 
	содержащие максимальную по длине подстроку-палиндром. Если таких 
	строк несколько, найти первые 10. Результат вывести на консоль в форме, 
	удобной для чтения
*/


#include <iostream>
#include<string>
#include<fstream>
#include "Header.hpp"


int main() {
	try {
		setlocale(LC_ALL, "1251");
		std::string newLine;
		size_t counterMax{ 0 };
		std::string line, delims;
		delims = " ,.:/!? ";
		std::fstream fin("input.txt");
		checkFile(fin);
		readLines(fin, delims, line, counterMax, newLine);
		if (newLine.empty()) {
			std::cout << "Palindroms a not exist";
		}
		else {
			createNewLine(newLine);
		}
		fin.close();

	}
	catch (std::exception e) {
		std::cout << e.what();
	}
	return 0;

}
