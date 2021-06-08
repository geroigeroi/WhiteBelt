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

std::vector<std::string> PalindromFilter (std::vector<std::string> words, int minLength) {
    /* Сначала переберем все слова на соответствие минимальной длине */
    
    int sz = (int)words.size();          // Количество элементов вектора
    int sz_string;                       // Длина каждого элемента вектора
    for (int i = 0; i <= sz - 1; ++i) {      // Перебираем каждый элемент начального вектора
        sz_string = (int)words[i].size();             // Размер каждой подряд строки из начального вектора
        if (sz_string < minLength) {
            words.erase(words.begin() + i);       // Если слово меньше минимальной длины, удаляем его из вектора
            sz--;
        }
    }
    /* Оставшиеся слова проверяем на палиндром, не соответствующие –– удаляем из вектора */
    
    int mdl;                // Значение середины строки
    std::string defin_str;  // Записываем каждый элемент вектора в эту переменную и работаем уже с этой строковой переменной
    int defin_str_size;     // Длина каждой такой записанной строки
    sz = (int)words.size(); // Количество элементов вектора
    for (int i = 0; i <= sz - 1; ++i) {     // Перебираем каждый элемент вектора
        defin_str = words[i];   // Записываем сюда слово, с которым будем работать
        defin_str_size = (int)defin_str.size(); // Количество символов в слове
        mdl = defin_str_size / 2;
        for (int j = 0; j < mdl; ++j) {
            if (defin_str[j] != defin_str[defin_str_size - 1]) {
                words.erase(words.begin() + i);
                i--;
                break;
            }
            --defin_str_size;
        }
    }
    return words;
}

int main() {
    std::vector<std::string> words;
    int minLength = 4;
    words ={"weew","bro","code"};
    words = PalindromFilter (words, minLength);
    for (auto n : words) {
        std::cout << n << " ";
    }
    return 0;
}

