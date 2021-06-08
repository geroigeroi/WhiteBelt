//
//  main.cpp
//  read_and_write_file
//
//  Created by  Mister on 08.11.2020.
//

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream input("/Users/mister/Desktop/Cpp/read_from_file/read_from_file/input.txt");
    std::ofstream output("/Users/mister/Desktop/Cpp/read_from_file/read_from_file/output.txt");
    std::string line;
    if (input.is_open()) {
        while(getline(input, line)) {
            output << line << std::endl;
        }
    } else {
        std::cout << "Did not open";
    }
    return 0;
}
