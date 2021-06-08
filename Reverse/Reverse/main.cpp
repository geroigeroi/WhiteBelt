//
//  main.cpp
//  Reverse
//
//  Created by  Mister on 15/09/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <vector>

void Reverse(std::vector<int>& v) {
    int sz = (int)v.size();
    std::vector<int> withReverse(sz);
    
    for (int i = sz - 1; i >= 0; i--) {
        withReverse[sz - 1 - i] = v[i];
        
    }
    v = withReverse;
    
}

int main() {
    std::vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    
    for (auto x : numbers) {
        std::cout << x << " " << std::endl;
    }
    return 0;
}
