//
//  main.cpp
//  read_output_table
//
//  Created by  Mister on 08.11.2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

int main() {
    
    // /Users/mister/Desktop/Cpp/read_output_table/input.txt
    std::ifstream inputData("/Users/mister/Desktop/Cpp/read_output_table/input.txt");
    int row, columns;
    inputData >> row >> columns;
    if (row == 0 || columns == 0) {
        return 0;
    }
    std::vector<int> allDigits;
    int count = 1;
    int allDigitsQuantity = row * columns;
    while(inputData)
    {
        int everyDigit = 0;
        inputData >> everyDigit;
        inputData.ignore(1);
        
        if (!(count % columns)) {
            std::cout << std::setw(10) << everyDigit;
            if (count == row * columns) {
                return 0;
            }
            std::cout << std::endl;
        }
        else {
        std::cout << std::setw(10) << everyDigit << " ";
        }
        ++count;
        
    
    }
    return 0;
}
