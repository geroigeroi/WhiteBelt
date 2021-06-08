//
//  main.cpp
//  Synonyms
//
//  Created by  Mister on 16.10.2020.
//

#include <iostream>
#include <set>
#include <vector>

int main() {
    int Q;  // Количество операций
    int i = 0;
    std::string command;
    std::string word_count;
    std::string word1_add, word2_add;
    std::string word1_check, word2_check;
    // std::set<std::string> syn;
    std::vector<std::set<std::string>> syn(1);
    std::set<std::string> words_check;
    int dump_index = 0;
    
    std::cin >> Q;
    
    while (i < Q) {
        std::cin >> command;
        
        if (command == "COUNT") {
            /* Здесь узнаем количество синонимов */
            int quant = 0;
            std::cin >> word_count;
            for (auto l : syn) {
                quant = quant + (int)l.count(word_count);
            }
            std::cout << quant << std::endl;
            
        } else if (command == "ADD") {
            /* Здесь добавляем пару синонимов */
            std::cin >> word1_add >> word2_add;
            
            syn[dump_index].insert(word1_add);
            syn[dump_index].insert(word2_add);
            
            ++dump_index;
            syn.resize(dump_index + 1);
            
        } else if (command == "CHECK") {
            /* Здесь проверяем являются ли два слова синонимами */
            bool flag = false;
            std::cin >> word1_check >> word2_check;
            words_check.insert(word1_check);
            words_check.insert(word2_check);
            for (int j = 0; j < syn.size(); ++j) {
                if (words_check == syn[j]) {
                    flag = true;
                    // std::cout << "YES" << std::endl;
                    break;
                }
                // std::cout << "NO" << std::endl;
            }
            if (flag == true) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
        ++i;
    }
    
    return 0;
}
