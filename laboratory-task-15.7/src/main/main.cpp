#include "../func/Train.hpp"

#include <fstream>
#include <algorithm>
#include <vector>



void fillVector(std::vector<Train>& myVector)
{
    std::fstream in ("src/files/text.txt");
    int16_t num;
    std::string destinationName;
    std::string type;
    std::string departureTime;
    std::string timeInRoad;
    while(in >> num){
        in >> destinationName;
        in >> type;
        in >> departureTime;
        in >> timeInRoad;
        Train a(num,destinationName,type == "Passenger" ? typeTrain::Passenger :typeTrain::Fast,departureTime,timeInRoad);
        myVector.push_back(a);
    }
    for(auto& elem : myVector){
        std::cout << elem << "\n";
    }
    in.close();
 }

void printByRange(const std::vector<Train>& myVector)
{
    std::cout << "\n*************************************\n";
    std::cout << "Введите нужный диапазон в формате ЧЧ:ММ";
    std::cout << "\n*************************************\n";
    std::cout << "От: ";
    std::string start;
    std::cin >> start;
    std::cout << "\nДо: ";
    std::string end;
    std::cin >> end;
    for(auto& elem : myVector){
        if(elem.getDepTime() >= start && elem.getDepTime() <= end){
            std::cout << "\nСписок поездов из диапазона: \n";
            std::cout << elem;
        }
    }
}

void printByDestName(const std::vector<Train>& myVector)
{
    std::cout << "\n*************************************\n";
    std::cout << "Введите нужный пункт назначения\n";
    std::cout << "\n*************************************\n";
    std::string name;
    std::cin >> name;
    bool flag = false;
    for(auto& elem : myVector){
        if(elem.geDestantionName() == name){
            std::cout << "\nСписок поездов направляющихся в : " << name << std::endl;
            std::cout << elem;
            flag = true;
        }
    }
    if(!flag){
         std::cout << "\nВ данный пункт назначения поезда не направляются\n";
    }
}

void printByDestNameFast(const std::vector<Train>& myVector)
{
    std::cout << "\n*************************************\n";
    std::cout << "\nВведите нужный пункт назначения\n";
    std::cout << "\n*************************************\n";
    std::string name;
    bool flag = false;
    std::cin >> name;
    for(auto& elem : myVector){
        if(elem.geDestantionName() == name && elem.getType() == typeTrain::Fast){
            std::cout << "\nСписок скоростных поездов направляющихся в : " << name << std::endl;
            std::cout << elem;
            flag = true;
        }
    }
    if(!flag){
        std::cout << "\nВ данный пункт назначения скоростные поезда не направляются\n";
    }
}

void seekFastest(const std::vector<Train>& myVector)
{
    std::cout << "\n*************************************\n";
    std::cout << "\nВведите нужный пункт назначения\n";
    std::cout << "\n*************************************\n";
    std::string name;
    std::cin >> name;
    Train temp(1,"test",typeTrain::Passenger,"00:00","43221454:12");
    bool flag = false;
    for(auto& elem : myVector){
        if(elem.geDestantionName() == name && elem.getTimeInRoad() < temp.getTimeInRoad()){
            temp = elem;
            flag = true;
        }
    }
     if(!flag){
         std::cout << "\nВ данный пункт назначения поезда не направляются\n";
    }
    else{
    std::cout << "\nСамый быстрый поезд: \n" << temp;
    }
}


int main()
 {
     std::vector<Train> myVector;
     fillVector(myVector);
     std::cout << "\n*************************************";
     std::cout << "Сортировка по времени отправления: \n";
     std::cout << "\n*************************************";
     std::sort(myVector.begin(), myVector.end(), [](Train& a, Train& b){return a < b;});
     for(auto& elem : myVector){
        std::cout << elem << "\n";
    }
     printByRange(myVector);
     printByDestName(myVector);
     printByDestNameFast(myVector);
     seekFastest(myVector);
    return 0;
}
