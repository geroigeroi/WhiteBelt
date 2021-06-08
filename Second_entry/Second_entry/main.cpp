//
//  main.cpp
//  Second_entry
//
//  Created by  Mister on 04/07/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int number_in_str = 0;       // Порядковый номер символа 'f' в слове
    int quantity = 0;            // Количество вхождений символа 'f' в слове
    cin >> str;
    for (auto i : str){
        if (i == 'f'){
            ++quantity;
            if (quantity == 2) {
                cout << number_in_str;
            }
        }
        ++number_in_str;
    }
    if (quantity == 0) {
        cout << -2;
    }
    if (quantity == 1) {
        cout << -1;
    }
    
    return 0;
}
