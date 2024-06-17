/* 
 Вариант 6 
 В целочисленной прямоугольной матрице найти: 
 - сумму элементов в тех строках, которые не содержат нулей; 
 - переставить местами 1-ый и последний столбец, 2-ой и предпоследний и т. д. 
*/ 
 
 
#include <iostream> 
#include <iomanip> 
 
void enterNumberOfRowsAndColumns(int16_t& numberOfLines, int16_t& numberOfColumns) 
{ 
 std::cout << "Enter the number of rows and columns " << '\n'; 
 std::cin >> numberOfLines; 
 std::cin >> numberOfColumns; 
 while(numberOfLines <= 0 || numberOfColumns <= 0) {
 std::cout << "Enter the number of rows and columns " << '\n'; 
 std::cin >> numberOfLines; 
 std::cin >> numberOfColumns; 
}
} 
 
void allocationMemoryForTheMatrix(int32_t**& matrix, int16_t numberOfLines, int16_t numberOfColumns) 
{ 
 matrix = new int* [numberOfLines]; 
 for (size_t i = 0; i < numberOfLines; ++i) { 
  matrix[i] = new int[numberOfColumns]; 
 } 
} 
 
void FillingWithRandomNumbers(int32_t** matrix, int16_t numberOfLines, int16_t numberOfColumns) 
{ 
 int16_t  first = 0, last = 0; 
 std::cout << "indicate boundaries from = "; 
 std::cin >> first; 
 std::cout << "before = "; 
 std::cin >> last; 
 if (first >= last) { 
  std::cout << "incorrect range"; 
 } 
 else { 
  for (size_t i = 0; i < numberOfLines; ++i) { 
   for (size_t j = 0; j < numberOfColumns; ++j) { 
    int16_t temp = rand() % (last  - first ) + first ; 
    matrix[i][j] = temp; 
   } 
  } 
 } 
} 
 
void inputElementsMtrx(int32_t** matrix, int16_t numberOfLines, int16_t numberOfColumns) 
{ 
 for (size_t i = 0; i < numberOfLines; ++i) { 
  for (size_t j = 0; j < numberOfColumns; ++j) { 
   std::cin >> matrix[i][j]; 
  } 
 } 
} 
 
void choosingTheFillingMtrx(int32_t** matrix, int16_t numberOfLines, int16_t numberOfColumns) 
{ 
 size_t op; 
 std::cout << " random - 1, keyboard input - 0 \n"; 
 std::cin >> op; 
 switch (op) 
 { 
 default:std::cout << "1 and 0"; 
  break; 
 case 0: 
  inputElementsMtrx(matrix, numberOfLines, numberOfColumns); 
  break; 
 case 1: 
  FillingWithRandomNumbers(matrix, numberOfLines, numberOfColumns); 
  break; 
 
 } 
} 
 
void sumOfTheItemsInTheRow(int32_t** matrix, int16_t numberOfLines, int16_t numberOfColumns) { 
 int64_t sum = 0; 
 bool isExist = true; 
 size_t counter = 0; 
 for (size_t i = 0; i < numberOfLines; ++i) { 
  for (size_t j = 0; j < numberOfColumns; ++j) { 
   if (matrix[i][j] != 0) { 
    sum += matrix[i][j]; 
   } 
   else { 
    ++counter; 
    isExist = false; 
    break; 
   } 
  } 
  if (isExist) { 
   std::cout << " sum str - " << i + 1 << " = " << sum << std::endl; 
  } 
  sum = 0; 
 } 
 if (counter == numberOfLines) { 
  std::cout << "All lines contain 0" << std::endl; 
 } 
 std::cout << std::endl; 
} 
 
void swapColumns(int32_t** matrix, int16_t numberOfLines, int16_t numberOfColumns) 
{ 
 for (size_t i = 0; i < numberOfLines; ++i) { 
  for (size_t j = 0; j < numberOfColumns / 2; ++j) { 
   std::swap(matrix[i][j], matrix[i][numberOfColumns - 1 - j]); 
  } 
 } 
} 
 
void printMatrix(int32_t** matrix, int16_t numberOfLines, int16_t numberOfColumns)
{
 for (size_t i = 0; i < numberOfLines; ++i) {  
	for (size_t j = 0; j < numberOfColumns; ++j) {
   std::cout << std::setw(3) << matrix[i][j] << " ";  }
  std::cout << std::endl; }
 std::cout << '\n';}

void clearMemory(int32_t**& matrix, int16_t numberOfLines)
{ 
  for (size_t i = 0; i < numberOfLines; ++i) {
  delete[] matrix[i]; 
  }
 delete[] matrix;
 }

int main() { 
int16_t numberOfLines = 0, numberOfColumns = 0;
enterNumberOfRowsAndColumns(numberOfLines, numberOfColumns); 
int32_t** matrix = nullptr;
allocationMemoryForTheMatrix(matrix, numberOfLines, numberOfColumns); 
choosingTheFillingMtrx(matrix, numberOfLines, numberOfColumns);
system("cls"); 
printMatrix(matrix, numberOfLines, numberOfColumns);
sumOfTheItemsInTheRow(matrix, numberOfLines, numberOfColumns); 
swapColumns(matrix, numberOfLines, numberOfColumns);
outputMatrix(matrix, numberOfLines, numberOfColumns); 
clearMemory(matrix, numberOfLines);
}

