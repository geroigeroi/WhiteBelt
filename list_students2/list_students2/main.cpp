//
//  main.cpp
//  list_students2
//
//  Created by  Mister on 13.11.2020.
//

#include <iostream>
#include <vector>
#include <string>


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
    std::cin >> numberOfStudents;
    
    while (n < numberOfStudents) {
        Student student;
        std::cin >> student.firstname >> student.lastname >>student.dayDOB >> student.monthDOB >> student.yearDOB;
        students.push_back(student);
        ++n;
    }
    std::cin >> countRequests;
    
    while (c < countRequests) {
        std::string request;
        int numberOfStudent;
        std::cin >> request >> numberOfStudent;
        if (request == "name") {
            if (numberOfStudent > numberOfStudents || numberOfStudent <= 0) {
                std::cout << "bad request\n";
            } else {
            std::cout << students[numberOfStudent - 1].firstname << " " << students[numberOfStudent - 1].lastname << "\n";
            }
        } else if (request == "date") {
            if (numberOfStudent > numberOfStudents || numberOfStudent <= 0) {
                std::cout << "bad request\n";
            } else {
            std::cout << students[numberOfStudent - 1].dayDOB << "." << students[numberOfStudent - 1].monthDOB << "." << students[numberOfStudent - 1].yearDOB << "\n";
            }
        } else {
            std::cout << "bad request\n";
        }
        ++c;
    }
    
    return 0;
}
