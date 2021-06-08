//
//  main.cpp
//  Maximization
//
//  Created by  Mister on 15/09/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>

void UpdateIfGreater (int first, int& second) {
    if (first > second) {
        second = first;
    }
}

int main() {
    int a = 4;
    int b = 2;
    UpdateIfGreater (5, b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    return 0;
}
