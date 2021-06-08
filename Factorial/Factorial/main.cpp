//
//  main.cpp
//  Factorial
//
//  Created by  Mister on 07/07/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>

int Factorial(int x) {
    if (x <= 0) {
        return 1;
    } else {
        for (int i = x - 1; i >= 1; --i) {
            x = x * i;
        }
    }
    return x;
}

int main() {
    int a;
    std::cin >> a;
    std::cout << Factorial(a);
    
    return 0;
}
