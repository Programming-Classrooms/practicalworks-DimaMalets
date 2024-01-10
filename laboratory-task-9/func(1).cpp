#include <iostream>
#include <string>
#include <fstream>
#include "Header.hpp"

void checkFile(std::fstream& fin)
{
	if (!fin.good()) {
		throw std::exception("File does not exist.\n");
	}
	if (!fin) {
		throw std::exception("File is not opened.\n");
	}
	if (fin.peek() == EOF) {
		throw std::exception("File is empty.\n");
	}

}

void readLines(std::fstream& fin, std::string delims, std::string line, size_t& counterMax,std::string& newLine)
{
	while (getline(fin, line)) {
	 searchWords(delims, line,counterMax,newLine);
	}

}

bool checkPalindrom(std::string word) 
{
	size_t length = word.length();

	for (size_t i = 0; i < length / 2; i++)	{
		if (word[i] != word[length - i - 1]) {
			return false;
		}
	}
	return true;

}

std::string searchWords(std::string delims, std::string line, size_t & counterMax, std::string& newLine)
{
	std::string word;
	std::string emptyLine;
	std::string::size_type begInd;
	begInd = line.find_first_not_of(delims);
	while (begInd != std::string::npos) {
		size_t counterMaxInLine{ 0 };
		size_t counter = 0;
		std::string::size_type endInd;
		endInd = line.find_first_of(delims, begInd);
		if (endInd == std::string::npos)
		{
			endInd = line.length();
		}
		word = line.substr(begInd, endInd - begInd);
		if (checkPalindrom(word) == true) {
			counter = word.length();
			if (counter >= counterMaxInLine) {
				counterMaxInLine = counter;
			}
			if (counterMaxInLine > counterMax) {
				newLine.clear();
				newLine += line + ';';
				counterMax = counterMaxInLine;
			}
			else if (counterMaxInLine == counterMax) {
				newLine += line + ';';
				counterMax = counterMaxInLine;
			}
		}
		begInd = line.find_first_not_of(delims, endInd);
	}
	return emptyLine;

}

void createNewLine(std::string newLine)
{
	std::string miniLine;
	std::string::size_type begInd;
	begInd = newLine.find_first_not_of(';');
	for (size_t i = 0; i < 10; ++i) {
		std::string::size_type endInd;
		endInd = newLine.find_first_of(';', begInd);
		miniLine = newLine.substr(begInd, endInd - begInd);
		std::cout << miniLine ;
		begInd = newLine.find_first_not_of(';', endInd);
		if (begInd == std::string::npos) {
			break;
		}
		std::cout <<'\n';
	}

}
