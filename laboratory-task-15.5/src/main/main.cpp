#include "../func/Function.hpp"


int main()
{
    int16_t size = 0;
    Student* listStudents = new Student[100];
    fillList(listStudents, size);
    printList(listStudents,size);
    createFIO(listStudents,size);
    createGroups(listStudents,size);
    return 0;
}