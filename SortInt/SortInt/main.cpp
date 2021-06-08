//
//  main.cpp
//  SortInt
//
//  Created by  Mister on 18.10.2020.
//

#include <iostream>
#include <algorithm>
#include <vector>

// 2   -4 3               3   1 -3 2
// 3   -4                     1 2 -3


bool our_sort (int a, int b) {
    return abs(b) > abs(a);
}

int main() {
    int N;
    std::vector<int> digits;
    
    std::cin >> N;
    // digits.resize(N + 1);
    for (int i = 0; i < N; ++i) {
        int A;
        std::cin >> A;
        digits.push_back(A);
    }
    
    // digits.erase(digits.begin());
    
    sort(begin(digits), end(digits), our_sort);
    
    for (const auto& dg : digits) {
        std::cout << dg << " ";
    }
    return 0;
}
