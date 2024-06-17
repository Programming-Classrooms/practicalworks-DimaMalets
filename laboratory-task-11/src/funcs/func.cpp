#include "Header.hpp"

void checkFile(std::fstream& file)
{
	if (!file.good()) {
		throw std::ios_base::failure("Bad file!");
	}
	if (!file) {
		throw std::ios_base::failure("File is not find");
	}
	if (file.peek() == EOF) {
		throw std::ios_base::failure("File is empty");
	}
}


size_t checkSizeForNumbers(std::string line, std::string delims, size_t& size) {

	std::string word;
	std::string number;
	std::string::size_type begIndx;
	std::string::size_type endIndx;
	size_t i = 0;
	begIndx = line.find_first_not_of(delims);

	while (begIndx != std::string::npos) {
		endIndx = line.find_first_of(delims, begIndx);
		if (endIndx == std::string::npos) {
			endIndx = line.length();
		}
		word = line.substr(begIndx, endIndx - begIndx);
		if (checkNumbers(word) == true) {
			++i;
			size++;
		}
		begIndx = line.find_first_not_of(delims, endIndx);
	}
	if (i == 0) {
		throw std::invalid_argument("0 numbers");
	}
	return size;
}

bool checkNumbers(std::string words)
{
	bool flag = true;
	int32_t size = words.length();
	if (words[0] == '-') {
		for (size_t i = 1; i < size; ++i) {
			if (isdigit(words[i]) == false) {
				flag = false;
				break;
			}
		}
	}
	else {
		for (size_t i = 0; i < size; ++i) {
			if (isdigit(words[i]) == false) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}

void createAllNumbers(std::string line, std::string delims, int32_t* arr)
{
	std::string word;
	std::string number;
	std::string::size_type begIndx;
	std::string::size_type endIndx;
	size_t i = 0;
	begIndx = line.find_first_not_of(delims);

	while (begIndx != std::string::npos) {
		endIndx = line.find_first_of(delims, begIndx);
		if (endIndx == std::string::npos) {
			endIndx = line.length();
		}
		word = line.substr(begIndx, endIndx - begIndx);
		if (checkNumbers(word) == true) {
			arr[i] = stoi(word);
			++i;
		}
		begIndx = line.find_first_not_of(delims, endIndx);
	}
}

void createAllNumbersCopy(int32_t* arr, int32_t* arrCopy, size_t size)
{
	size_t j = 0;

	for (size_t i = 0; i < size; ++i) {
		if (arr[i] %2  == 0) {
			arrCopy[j] = arr[i];
			++j;
		}
	}

	for (size_t i = 0; i < size; ++i) {
		if (arr[i] %2 != 0) {
			arrCopy[j] = arr[i];
			++j;
		}
	}

}

bool checkSurname(std::string words)
{
	bool flag = true;
	int32_t size = words.length();
	if (islower(words[0])) {
		flag = false;
		return flag;
	}
	else {
		for (size_t i = 1; i < size; ++i) {
			if (isalpha(words[i]) == false || !islower(words[i])) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}


bool checkWords(std::string words)
{
	bool flag = true;
	int32_t size = words.length();
	for (size_t i = 0; i < size; ++i) {
		if (isalpha(words[i]) == false) {
			flag = false;
			break;
		}
	}
	return flag;
}

void checkSizeText(std::string line, std::string delims, size_t& size)
{
	std::string word;
	std::string number;
	std::string::size_type begIndx;
	std::string::size_type endIndx;
	size_t i = 0;
	begIndx = line.find_first_not_of(delims);

	while (begIndx != std::string::npos) {
		endIndx = line.find_first_of(delims, begIndx);
		if (endIndx == std::string::npos) {
			endIndx = line.length();
		}
		word = line.substr(begIndx, endIndx - begIndx);
		if (checkWords(word) == true && checkSurname(word) == true) {
			++i;
			size++;
		}
		begIndx = line.find_first_not_of(delims, endIndx);
	}

}

void createAllSurname(std::string line, std::string delims, std::string* arr)
{
	std::string word;
	std::string number;
	std::string::size_type begIndx;
	std::string::size_type endIndx;
	size_t i = 0;
	begIndx = line.find_first_not_of(delims);

	while (begIndx != std::string::npos) {
		endIndx = line.find_first_of(delims, begIndx);
		if (endIndx == std::string::npos) {
			endIndx = line.length();
		}
		word = line.substr(begIndx, endIndx - begIndx);
		if (checkSurname(word) == true) {
			arr[i] = word;
			++i;
		}
		begIndx = line.find_first_not_of(delims, endIndx);
	}

}

void insertionSort(std::string* arr, size_t sizeText) {

	for (size_t i = 1; i < sizeText; ++i) {
		int32_t  j = i - 1;
		while (j >= 0 && arr[j] > arr[j + 1]) {
			std::swap(arr[j], arr[j + 1]);
			--j;
		}
	}

}

void outputAllNumbers(int32_t* arr, size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void outputAllSurname(std::string* arr, size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void inputEmployees(
	Employee* employes,
	size_t sizeText,
	std::string* allSurname,
	int32_t* allNumbers,
	size_t size
)
{
	bool flag = true;
	size_t temp = 0;
	size_t counter = 0;
		while (sizeText) {
			employes[counter].surname = allSurname[counter];
			while (allNumbers[temp] > 9 || allNumbers[temp] < 0) 
			{
				temp++;
				if (temp >= size) 
				{
					std::cout << " Enter the number of children for " << counter << " = ";
					std::cin >> employes[counter].children;
					while (employes[counter].children < 0 || employes[counter].children > 9) 
					{
						std::cout << " Enter the number of children for(number >= 0 and <10) " << counter << " = ";
						std::cin >> employes[counter].children;
					}
					flag = false;
					break;
				}

			}
			if (flag) {
				employes[counter].children = allNumbers[temp];
				temp++;
			}
			sizeText--;
			counter++;
		}


}


void outputStruct(Employee* employes, size_t sizeText) {
	std::cout << std::endl << std::endl;
	for (size_t i = 0; i < sizeText; ++i) {
		std::cout << employes[i].surname << " " << employes[i].children << std::endl;
	}
}


void outputInTxtFile(Employee* employes ,size_t sizeText) {
	std::cout << std::endl;
	std::ofstream fout("result.txt");
	for (size_t i = 0; i < sizeText; ++i) {
		fout << employes[i].surname << " " << employes[i].children << std::endl;
	}
	std::cout << "Output in txt File good";
}

void outputInBinFile(Employee* employes, size_t sizeText) {
	std::ofstream fbin("result.bin", std::ios::binary);
	for (size_t i = 0; i < sizeText; ++i) {
		fbin.write((char*)&employes[i], sizeof(Employee));
	}
	std::cout << std::endl <<std::endl << "output in BIN file good";
	fbin.close();
}

std::string toUpper(std::string word)
{
	for (size_t i = 0; i < word.size(); ++i) {
		word[i] = std::toupper(word[i]);
	}
	return word;
}

bool comp(Employee employes1, Employee employes2) {
	if (toUpper(employes1.surname) == toUpper(employes2.surname)) {
		return employes1.children > employes1.children;
	}
	return toUpper(employes1.surname) > toUpper(employes2.surname);
}
 
void swapString(Employee* employes,size_t sizeText) {
	std::swap(employes[0].surname, employes[sizeText-1].surname);
	std::swap(employes[0].children, employes[sizeText-1].children);
}
