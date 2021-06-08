//
//  main.cpp
//  Binary_numbers
//
//  Created by  Mister on 05/07/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <vector>

int main() {
    int n;                 // Начальное число в десятичной системе
    int sz;                // Размер получившегося вектора
    std::vector<int> binary;
    
    std::cin >> n;
    while (n >= 1) {
        binary.push_back(n % 2);
        n = n / 2;
    }
    sz = (int)binary.size();
    for (int i = sz; i > 0;--i) {
        std::cout << binary[i - 1];
    }
    
    return 0;
}
