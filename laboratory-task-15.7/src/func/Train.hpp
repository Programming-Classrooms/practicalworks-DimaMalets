#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <iostream>
#include <string>

enum class typeTrain {Passenger, Fast};

class Train
{
    private:

    int16_t  numTrain;
    std::string destinationName;
    typeTrain type;
    std::string departureTime;
    std::string timeInRoad;

    public:

    /* Конструктор с параметрами */
    Train(int16_t, std::string, typeTrain, std::string, std::string);
    
    /* Геттеры */
    typeTrain getType() const;
    std::string getTimeInRoad() const;
    std::string getDepTime() const;
    std::string geDestantionName() const;
    
    /* Перегрузка операторов */
    Train&  operator = (const Train& rhs);
    bool operator < (const Train& rhs);
    friend std::ostream& operator <<(std::ostream &,const Train&);
};

#endif // Train.hpp
