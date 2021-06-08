//
//  main.cpp
//  SortwithoutLetterCase
//
//  Created by  Mister on 18.10.2020.
//

#include <iostream>
#include <algorithm>
#include <map>

//  2 q A                   A q
//  3 a C b                 a b C
//  2 StringB stRiNgA       stRiNgA StringB

int main() {
    int N;
    std::map<std::string, std::string> strs;
    
    std::cin >> N;
    
    for (int i = 0; i < N; ++i) {
        std::string various_case;
        std::cin >> various_case;
        char character;
        std::string lower_case;
        for (int i = 0; i < various_case.size(); ++i) {
            character = various_case[i];
            lower_case += (char)tolower(character);
        }
        strs.insert(std::make_pair(lower_case, various_case));
    }
    for (const auto& [key, value] : strs) {
        std::cout << value << " ";
    }
    
    return 0;
}
