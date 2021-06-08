//
//  main.cpp
//  Map_values
//
//  Created by  Mister on 16.10.2020.
//

#include <iostream>
#include <map>
#include <set>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m) {
    std::set<std::string> our_Set;
    for (const auto& item : m) {
        our_Set.insert(item.second);
    }
    return our_Set;
}

int main() {
    
    std::set<std::string> values = BuildMapValuesSet({
        {1, "odd"},
        {2, "even"},
        {3, "odd"},
        {4, "even"},
        {5, "odd"}
    });

    for (const std::string& value : values) {
      std::cout << value << std::endl;
    }
    
    return 0;
}
