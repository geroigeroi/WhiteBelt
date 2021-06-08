//
//  main.cpp
//  Anagrams
//
//  Created by  Mister on 10/2/20.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

std::map <char, int> BuildCharCounters(const std::string& word) {
    std::map <char, int> occurrence;
    
    for (const auto& c : word) {
        ++occurrence[c];
    }
    return occurrence;
}

int main() {
    
    int Q;  // Количество операций
    int i = 0;
    std::string word1, word2;
    std::map <char, int> occurrence;
    std::vector<std::string> output;
    
    std::cin >> Q;
    
    while(i < Q) {
        std::cin >> word1 >> word2;
        if (BuildCharCounters(word1) == BuildCharCounters(word2)) {
            output.push_back("YES");
        } else {
            output.push_back("NO");
        }
        
        
        ++i;
    }
    for (const auto& o : output) {
        std::cout << o << std::endl;
    }
    
    return 0;
}
