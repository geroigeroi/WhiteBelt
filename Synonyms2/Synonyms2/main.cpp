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
    std::set<std::set<std::string>> syn;
    
    std::cin >> Q;
    
    while (i < Q) {
        std::cin >> command;
        
        if (command == "COUNT") {
            std::string word_count;
            int quant = 0;
            
            std::cin >> word_count;
            for (auto l : syn) {
                quant = quant + (int)l.count(word_count);
            }
            std::cout << quant << std::endl;
            
        } else if (command == "ADD") {
            std::string word1_add, word2_add;
            
            std::cin >> word1_add >> word2_add;
            std::set<std::string> tmp_set = {word1_add, word2_add};
            syn.insert(tmp_set);
            
        } else if (command == "CHECK") {
            std::string word1_check, word2_check;
            bool flag = false;
            std::set<std::string> words_check;
            
            std::cin >> word1_check >> word2_check;
            words_check.insert(word1_check);
            words_check.insert(word2_check);
            for (auto l : syn) {
                if (words_check == l) {
                    flag = true;
                    break;
                }
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
