#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "../funcs/Header.hpp"


int main() {
	try {
		setlocale(LC_ALL, ".1251");
		std::fstream file("src/files/Numbers.txt");
		checkFile(file);
		std::string delims;
		std::string line;
		size_t size = 0;

		getline(file, delims);

		while (getline(file, line)) {
			checkSizeForNumbers(line, delims, size);
		}

		int32_t* allNumbers = new int32_t[size];
		std::fstream file1("src/files/Numbers.txt");

		while (getline(file1, line)) {
			createAllNumbers(line, delims, allNumbers);
		}
		outputAllNumbers(allNumbers, size);

		int32_t* allNumbersCopy = new int32_t[size];
		createAllNumbersCopy(allNumbers, allNumbersCopy, size);
		outputAllNumbers(allNumbersCopy, size);
		file1.close();
		std::cout << std::endl;

		std::string delimsText;
		std::string lineText;
		std::fstream textFile("src/files/Strings.txt");
		size_t sizeText = 0;

		checkFile(textFile);
		getline(textFile, delimsText);

		while (getline(textFile, lineText)) {
			checkSizeText(lineText, delims, sizeText);
		}

		std::string* allSurname = new std::string[sizeText];
		std::fstream textFile1("src/files/Strings.txt");

		while (getline(textFile1, lineText)) {
			createAllSurname(lineText, delimsText, allSurname);
		}

		outputAllSurname(allSurname, sizeText);

		tempSort(allSurname, sizeText);

		outputAllSurname(allSurname, sizeText);

		textFile1.close();
		file.close();
		textFile.close();

		Employee* employes = new Employee[sizeText];
		inputEmployees(employes, sizeText, allSurname, allNumbers, size);
		outputStruct(employes, sizeText);
		//tempSort(employes, sizeText);
		outputStruct(employes, sizeText);
		outputInTxtFile(employes, sizeText);
		swapString(employes,sizeText);
		outputInBinFile(employes, sizeText);
	}


	catch (std::invalid_argument& e) {
		std::cerr << e.what();
	}
	catch(std::ios_base::failure& e){
		std::cerr << e.what();
	}

	return 0;
}
