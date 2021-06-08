//
//  main.cpp
//  struct_LectureTitle
//
//  Created by  Mister on 04.11.2020.
//

#include <iostream>

struct Specialization {
    std::string value;
    explicit Specialization(std::string new_value) {
        value = new_value;
    }
};

struct Course {
    std::string value;
    explicit Course(std::string new_value) {
        value = new_value;
    }
};

struct Week {
    std::string value;
    explicit Week(std::string new_value) {
        value = new_value;
    }
};

struct LectureTitle {
    std::string specialization;
    std::string course;
    std::string week;
    
    LectureTitle(Specialization new_spec, Course new_crs, Week new_week) {
        specialization = new_spec.value;
        course = new_crs.value;
        week = new_week.value;
    }
};

void PrintLecture (const LectureTitle& title) {
    std::cout << title.specialization << " " << title.course << " " << title.week << "\n";
}

int main() {
    
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );
    
    PrintLecture(title);
    
    return 0;
}
