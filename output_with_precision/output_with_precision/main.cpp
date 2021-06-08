//
//  main.cpp
//  output_with_precision
//
//  Created by  Mister on 08.11.2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


int main() {
    
    std::ifstream input("input.txt");
    
    double digit;
    std::cout << std::fixed << std::setprecision(3);
    if (input) {
        for (; input >> digit; ) {
            std::cout << digit << std::endl;
        }
    }
    // std::cout << digit << " " << digit2;
    
    return 0;
}
