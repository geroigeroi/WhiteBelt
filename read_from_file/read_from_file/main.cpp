//
//  main.cpp
//  read_from_file
//
//  Created by  Mister on 08.11.2020.
//

#include <iostream>
#include <fstream>
#include <string>

int main() {
    
    std::ifstream input("/Users/mister/Desktop/Cpp/read_from_file/read_from_file/input.txt");
    std::string line;
    if (input.is_open()) {
        while(getline(input, line)) {
            std::cout << line << std::endl;
        }
    } else {
        std::cout << "Did not open";
    }
    return 0;
}
