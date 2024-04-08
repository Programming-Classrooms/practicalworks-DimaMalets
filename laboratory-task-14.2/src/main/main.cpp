#include"../func/Student2.hpp"
#include"../func/AfterFirstSession.hpp"
#include "../func/AfterYear.hpp"

double averageMarksAfterFirstSession(Student** arr,size_t size,size_t numberGroup)
{
    double averageMark = 0;
    double numberStudents = 0;
    for (size_t i = 0; i < size; ++i) 
    {
        if(dynamic_cast<StudentAfterFirstSession*>(arr[i]) && arr[i]->getGroup() == numberGroup) 
        {
            averageMark += dynamic_cast<StudentAfterFirstSession*>(arr[i])->getAverageMark();
            ++numberStudents;
        }
    }
    
    if(numberStudents == 0) {
        return 0;
    }

    return averageMark / numberStudents;
}

double averageMarksAfterYear(Student** arr,size_t size,size_t numberGroup)
{
    double averageMark = 0;
    double numberStudents2 = 0;

    for (size_t i = 0; i < size; ++i) 
    {
        if(dynamic_cast<StudentAfterYear*>(arr[i]) && arr[i]->getGroup() == numberGroup) 
        {
            averageMark += dynamic_cast<StudentAfterYear*>(arr[i])->getAverageMark();
            ++numberStudents2;
        }
    }
    
    if(numberStudents2 == 0) {
        return 0;
    }

    return averageMark / numberStudents2;
}

void randomFillingFirst(int16_t*arr){
    for(size_t i =0; i < 4; ++i)
    {
        arr[i] = (rand() %10)+ 1;
    }
}

void randomFillingSecond(int16_t* arr){
for(size_t i =0; i < 5; ++i)
    {
        arr[i] = (rand() %10)+ 1;
    }

}
int main(){
    srand(time(0));

    /* Демонстрация среднего балла группы после первой сессии  */

    size_t size = 5;
    size_t  counter = 0;
    int16_t arr[4];
    Student** listStudent = new Student*[5]; 
    randomFillingFirst(arr);
    listStudent[0] = new StudentAfterFirstSession(std::string("Dasha"), 1, 7121, 112, arr);
    randomFillingFirst(arr);
    listStudent[1] = new StudentAfterFirstSession(std::string("Vadim"), 1, 7121, 113, arr);
    randomFillingFirst(arr);
    listStudent[2] = new StudentAfterFirstSession(std::string("Danik"), 1, 7121, 114, arr);
    for(size_t i =0; i < 3; ++i){
        dynamic_cast<StudentAfterFirstSession*>(listStudent[i]);
        listStudent[i]->print(std::cout);
        std::cout << "\n\n";
    }
    int16_t group;
    std::cout << "Enter group: ";
    std::cin >> group;
    double average = averageMarksAfterFirstSession(listStudent,5,group);
    std::cout << "Average mark after first session in this group : " << average;

    /* Демонстрация среднего балла группы после года  */

    std::cout << std::endl <<"\n\n";
    size_t size2 = 5;
    size_t  counter2 = 0;
    int16_t arr2[5];
    Student** listStudent2 = new Student*[5]; 
    randomFillingFirst(arr);
    randomFillingSecond(arr2);
    listStudent2[0] = new StudentAfterYear(std::string("Dasha"), 1, 7121, 112, arr,arr2);
    randomFillingFirst(arr);
    randomFillingSecond(arr2);
    listStudent2[1] = new StudentAfterYear(std::string("Vadim"), 1, 7121, 113, arr, arr2);
    randomFillingFirst(arr);
    randomFillingSecond(arr2);
    listStudent2[2] = new StudentAfterYear(std::string("Danik"), 1, 7121, 114, arr, arr2);
    for(size_t i =0; i < 3; ++i){
        dynamic_cast<StudentAfterYear*>(listStudent2[i]);
        listStudent2[i]->print(std::cout);
        std::cout << "\n\n";
    }
    int16_t group2;
    std::cout << "Enter group: ";
    std::cin >> group2;
    double average2 = averageMarksAfterYear(listStudent2,5,group2);
    std::cout << "Average mark after year in this group : " << average2;
    
    return 0;   
}
