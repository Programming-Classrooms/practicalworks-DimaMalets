#include "Function.hpp"


void fillSize(int16_t & rows, int16_t & columns)
{
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    if(rows <=0){
        throw std::invalid_argument("Количество строк должно быть натуральным числом");
    }
    std::cout << "Введите количество столбцов: ";
    std::cin >> columns;
    if(columns <=0){
        throw std::invalid_argument("Количество столбцов должно быть натуральным числом");
    }
}

void fillMatrixRandom(std::vector<std::vector<int>>& mtrx, int16_t rows, int16_t columns)
{
    int16_t first;
    int16_t last;
    std::cout << "\nВведите диапазон из которого взять занчения\n";
    std::cout <<"От: ";
    std::cin >> first;
    std::cout << "До: ";
    std::cin >> last;
    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < columns; ++j)
        {
            mtrx[i][j] = rand()%(last - first) + first;
        }
    }
    std::cout << "\nСозданная матрица\n";
    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < columns; ++j)
        {
            std::cout << mtrx[i][j] << " ";
        }
        std::cout << std::endl;
    }
} 

void deleteMax(std::vector<std::vector<int>>& mtrx, int16_t rows, int16_t columns)
{
    int32_t maxEl = INT32_MIN;
    int16_t maxRows;
    int16_t maxColumns;
    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < columns; ++j)
        {
            if(mtrx[i][j] > maxEl)
            {
                maxEl = mtrx[i][j];
                maxRows = i;
                maxColumns = j;
            }
        }
    }
    std::cout << "Максимальный элемент: " << maxEl;
    mtrx.erase(mtrx.begin()+maxRows);
    for(size_t i=0; i < mtrx.size();++i){
        mtrx[i].erase(mtrx[i].begin()+ maxColumns);
    }

    std::cout << "\nПреобразованная матрица\n";
    for(size_t i = 0; i < rows-1; ++i)
    {
        for(size_t j = 0; j < columns-1; ++j)
        {
            std::cout << mtrx[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void  newSort(std::vector<std::vector<int>>& mtrx, int16_t rows, int16_t columns)
{
    int32_t sum = 0;
    int32_t tempSum =0;
    for(size_t i = 0; i < rows; ++i){
        for(size_t j = i+1; j < rows-1;++j){
            tempSum = std::accumulate(mtrx[j].begin(),mtrx[j].end(),0);
            sum = std::accumulate(mtrx[j-1].begin(),mtrx[j-1].end(),0);
            if(sum> tempSum){
                std::swap(mtrx[j],mtrx[j-1]);
            }
        }
    }
            tempSum = std::accumulate(mtrx[0].begin(),mtrx[0].end(),0);
            sum = std::accumulate(mtrx[1].begin(),mtrx[1].end(),0);
            if(sum < tempSum){
                std::swap(mtrx[0],mtrx[1]);
            }
            
    std::cout << "\nПреобразованная матрица\n";
    for(size_t i = 0; i < rows-1; ++i)
    {
        for(size_t j = 0; j < columns-1; ++j)
        {
            std::cout << mtrx[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
