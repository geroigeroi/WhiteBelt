//
//  main.cpp
//  Palindrom
//
//  Created by  Mister on 07/07/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <string>

bool IsPalindrom(std::string w) {
    int sz;                         // Размер строки
    int mdl;                        // Значение середины строки
    sz = (int)w.size();
    mdl = sz / 2;
        for (int i = 0; i < mdl; ++i){
            if (w[i] == w[sz - 1]) {
                --sz;
            } else {
                return false;
            }
        }
    return true;
}

int main() {
    std::string w;
    std::cin >> w;
    std::cout << IsPalindrom(w) << std::endl;
    
    return 0;
}
