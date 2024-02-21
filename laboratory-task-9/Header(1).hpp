#ifndef HEADER_HPP
#define HEADER_HPP


#include <iostream>


void checkFile(std::fstream& fin);

void readLines(std::fstream& fin, std::string delims, std::string line, size_t& counterMax, std::string& newLine);

std::string searchWords(std::string delims, std::string line, size_t& counterMax, std::string& newLine);

bool checkPalindrom(std::string word);

void createNewLine(std::string newLine);

#endif  // !HEADER_HPP
