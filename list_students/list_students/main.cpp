//
//  main.cpp
//  list_students
//
//  Created by  Mister on 11.11.2020.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

struct Student {
    std::string firstname;
    std::string lastname;
    int dayDOB;
    int monthDOB;
    int yearDOB;
};

int main() {
    std::vector<Student> students;
    int numberOfStudents, countRequests;
    int n = 0, c = 0;  // Счётчики
    //std::cin >> numberOfStudents;
    std::cin >> numberOfStudents;
    std::cin.ignore();
    
    while (n < numberOfStudents) {
        Student student;
        std::stringstream fullData;
        std::string fulldata_string;
        std::getline(std::cin, fulldata_string);
        int day, month, year;
        std::string name, soname;
        fullData << fulldata_string;
        fullData >> name;
        fullData >> soname;
        fullData >> day;
        fullData >> month;
        fullData >> year;
        student.firstname = name;
        student.lastname = soname;
        student.dayDOB = day;
        student.monthDOB = month;
        student.yearDOB = year;
        students.push_back(student);
        ++n;
    }
    std::cin >> countRequests;
    
    while (c < countRequests) {
        std::string request;
        int numberOfStudent;
        std::cin >> request >> numberOfStudent;
        if (request == "name") {
            std::cout << students[numberOfStudent - 1].firstname << " " << students[numberOfStudent - 1].lastname << "\n";
        } else if (request == "date") {
            std::cout << students[numberOfStudent - 1].dayDOB << "." << students[numberOfStudent - 1].monthDOB << "." << students[numberOfStudent - 1].yearDOB << "\n";
        } else {
            std::cout << "bad request\n";
        }
        ++c;
    }
    
    return 0;
}
