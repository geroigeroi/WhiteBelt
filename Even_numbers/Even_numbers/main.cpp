//
//  main.cpp
//  Even_numbers
//
//  Created by  Mister on 04/07/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>

using namespace std;
int main() {
    
    int a, b;
    cin >> a >> b;
    for (a; a <= b; ++a) {
        if (a % 2 == 0) {
            cout << a << " ";
        }
    }
    return 0;
}
