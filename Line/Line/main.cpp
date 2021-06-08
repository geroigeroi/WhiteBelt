//
//  main.cpp
//  Line
//
//  Created by  Mister on 9/19/20.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <vector>

void come(std::vector<bool>& line, int k) {
    line.resize(line.size() + k);
}

void worry(std::vector<bool>& line, int k) {
    line[k] = true;
}

void quiet(std::vector<bool>& line, int k) {
    line[k] = false;
}

int main() {
    int Q;  // Количество операций
    int k;
    int i = 0;
    int worry_quantity = 0;  //  Количество беспокоящихся людей
    std::vector<int> worry_quantity_overal;
    std::vector<bool> line;  // Очередь. Беспокоящиеся будут true
    std::string command;
    std::cin >> Q;
    
    while(i < Q) {
        std::cin >> command;
        if (command == "WORRY_COUNT") {
            for (auto d : line) {
                if (d == true) {
                    worry_quantity++;
                }
            }
            worry_quantity_overal.push_back(worry_quantity);
            worry_quantity = 0;
        } else {
            std::cin >> k;  // Если введено не WORRY_COUNT, то считываем циффру для других команд
            if (command == "COME") {
                come(line, k);
            }
            else if (command == "WORRY") {
                worry(line, k);
            }
            else if (command == "QUIET") {
                quiet(line, k);
            }
        }
        ++i;
    }
    for (auto s : worry_quantity_overal) {
        std::cout << s << std::endl;
    }
    return 0;
}
