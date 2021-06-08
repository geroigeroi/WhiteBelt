//
//  main.cpp
//  Reversed
//
//  Created by  Mister on 9/17/20.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <vector>

std::vector<int> Reversed(const std::vector<int>& v) {
    int sz = (int)v.size();
    std::vector<int> withReverse(sz);
    for (int i = sz - 1; i >= 0; i--) {
        withReverse[sz - 1 - i] = v[i];
    }
    return withReverse;
}

int main() {
    std::vector<int> numbers = {1, 5, 3, 4, 2};
    numbers = Reversed(numbers);
    
    for (auto x : numbers) {
        std::cout << x << " " << std::endl;
    }
    return 0;
}
