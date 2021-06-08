//
//  main.cpp
//  Greatest_common_divisor_AlgEvklid
//
//  Created by  Mister on 05/07/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int a, b;
    
    cin >> a >> b;
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    cout << a + b;
    return 0;
}
