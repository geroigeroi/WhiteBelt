//
//  main.cpp
//  Synonyms
//
//  Created by  Mister on 16.10.2020.
//

#include <iostream>
#include <set>
#include <vector>
#include <map>

int main() {
    int Q;  // Количество операций
    int i = 0;
    std::string command;
    std::map<std::string, std::set<std::string>> syn;

    std::cin >> Q;
    
    while (i < Q) {
        std::cin >> command;
        
        if (command == "COUNT") {
            std::string word_count;
            std::cin >> word_count;
            std::cout << syn[word_count].size() << std::endl;;

        } else if (command == "ADD") {
            std::string word1_add, word2_add;
            std::cin >> word1_add >> word2_add;
            syn[word1_add].insert(word2_add);
            syn[word2_add].insert(word1_add);
            
        } else if (command == "CHECK") {
            std::string word1_chk, word2_chk;
            std::cin >> word1_chk >> word2_chk;
            int entry_word1 = (int)syn[word1_chk].count(word2_chk);
            int entry_word2 = (int)syn.count(word1_chk);
            if (entry_word1 == entry_word2) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
        ++i;
    }
    return 0;
}
