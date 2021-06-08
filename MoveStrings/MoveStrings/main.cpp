//
//  main.cpp
//  MoveStrings
//
//  Created by  Mister on 15/09/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <vector>

void MoveStrings (std::vector<std::string>& source, std::vector<std::string>& destination) {
    for (auto x : source) {
        destination.push_back(x);
    }
    source.clear();
}

int main() {
    std::vector<std::string> source = {"a", "b", "c"};
    std::vector<std::string> destination = {"z", "y"};
    MoveStrings(source, destination);
    for (auto x : destination) {
        std::cout << x << std::endl;
    }
    return 0;
}
