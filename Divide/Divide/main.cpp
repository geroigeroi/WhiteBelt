//
//  main.cpp
//  Divide
//
//  Created by  Mister on 04/07/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b;
    if (b == 0) {
        cout << "Impossible";
    } else {
        c = a / b;
        cout << c;
    }
    
    return 0;
}
