//
//  main.cpp
//  Unique
//
//  Created by  Mister on 16.10.2020.
//

#include <iostream>
#include <set>

int main() {
    int Q;  // // Количество строк
    int i = 0;
    std::set<std::string> words;
    std::string word;
    
    std::cin >> Q;
    
    while (i < Q) {
        std::cin >> word;
        words.insert(word);
        
        ++i;
    }
    std::cout << words.size();
    return 0;
}
