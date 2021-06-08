//
//  main.cpp
//  PalindromFilter
//
//  Created by  Mister on 07/07/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

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

std::vector<std::string> PalindromFilter (std::vector<std::string> words, int minLength) {
    std::vector<std::string> words_with_minLenght;
    std::vector<std::string> words_with_minLenght_andPalindrom;
    int sz = (int)words.size(); // Количество элементов вектора
    int sz_string;                       // Длина каждого элемента вектора
    int i = 0;
    do {
        sz_string = (int)words[i].size();
        if (sz_string >= minLength) {
         words_with_minLenght.push_back(words[i]);
        }
        ++i;
    }
    while (i <= sz - 1);
    int sz_ml;
    std::string defin_str;
    sz_ml = (int)words_with_minLenght.size();
    for (int j = 0; j <= sz_ml - 1; ++j) {   // Перебираем каждый элемент вектора, где элементы, отобранные по длине
        defin_str = words_with_minLenght[j];
        if (IsPalindrom(defin_str) == true) {
            words_with_minLenght_andPalindrom.push_back(words_with_minLenght[j]);
        }
    }
    return words_with_minLenght_andPalindrom;
}

int main() {
    std::vector<std::string> words;
    int minLength = 1;
    words ={"abacaba", "aba", "a"};
    words = PalindromFilter (words, minLength);
    for (auto n : words) {
        std::cout << n << " ";
    }
    return 0;
}
