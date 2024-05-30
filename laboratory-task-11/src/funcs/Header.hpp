#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

struct Employee {
	std::string surname;
	size_t children;
};

void checkFile(std::fstream& file);

bool checkSurname(std::string words);

void createAllNumbers(std::string line, std::string delims, int32_t* arr);

bool checkNumbers(std::string words);

size_t checkSizeForNumbers(std::string line, std::string delims, size_t& size);

void createAllNumbersCopy(int32_t* arr, int32_t* arrCopy, size_t size);

void checkSizeText(std::string line, std::string delims, size_t& size);

bool checkWords(std::string words);

void createAllSurname(std::string line, std::string delims, std::string* arr);

template <typename T1>
void tempSort(T1* arr, size_t sizeText) {
	for (size_t i = 1; i < sizeText; ++i) {
		int32_t  j = i - 1;
		while (j >= 0 && arr[j] > arr[j + 1]) {
			std::swap(arr[j], arr[j + 1]);
			--j;
		}
	}
}


void insertionSort(std::string* arr, size_t sizeText);

void outputAllNumbers(int32_t* arr, size_t size);

void outputAllSurname(std::string* arr, size_t size);


void inputEmployees(Employee* employees, size_t sizeText, std::string* allSurname, int32_t* allNumbers, size_t size);

void outputStruct(Employee* employes, size_t sizeText);

void outputInTxtFile(Employee* employes, size_t sizeText);

void outputInBinFile(Employee* employes, size_t sizeText);

bool comp(Employee employes1, Employee employes2);

void swapString(Employee* employes, size_t sizeText);

#endif //Header.hpp