#include "Function.hpp"


bool comp(Student a, Student b)
{
    return a.surname < b.surname;
}

bool groupAndCourseComp(Student a, Student b)
{
    if(a.course != b.course){
        return a.course < b.course;
    }
    if(a.group != b.group){
        return a.group < b.group;
    }
    if(a.surname != b.surname){
        return a.surname < b.surname;
    }
}

void fillList(Student* students, int16_t & size)
{
    std::fstream in ("src/files/Students.txt");
    int16_t temp = 0;
    while(in)
    {
        in >> students[temp].surname;
        in >> students[temp].name;
        in >> students[temp].patronymic;
        in >> students[temp].course;
        in >> students[temp].group;
        ++temp;
        ++size;
    }
    size--;
    in.close();
}

void printList(Student* students, int16_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        std::cout << "Student :\n";
        std::cout << students[i].surname << " " << students[i].name << " " << students[i].patronymic;
        std::cout << "\nCourse : " << students[i].course;
        std::cout << "\nGroup : " << students[i].group << std::endl << std::endl;
    }
}

void createFIO(Student* students,int16_t size)
{
    std::fstream out ("src/files/Fio.txt");
    std::sort(students,students+size, comp);
    for(size_t i = 0; i < size; ++i)
    {
        out << "Student :\n";
        out << students[i].surname << " " << students[i].name << " " << students[i].patronymic;
        out << "\nCourse : " << students[i].course;
        out << "\nGroup : " << students[i].group << std::endl << std::endl;
    }

}

void createGroups(Student* students,int16_t size)
{
    std::fstream out ("src/files/Groups.txt");
    std::sort(students,students+size, groupAndCourseComp);
    for(size_t i = 0; i < size; ++i)
    {
        out << "Student :\n";
        out << students[i].surname << " " << students[i].name << " " << students[i].patronymic;
        out << "\nCourse : " << students[i].course;
        out << "\nGroup : " << students[i].group << std::endl << std::endl;
    }

}
