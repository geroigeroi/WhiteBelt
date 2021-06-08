//
//  main.cpp
//  Value_of_goods
//
//  Created by  Mister on 04/07/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>

/*
 n - Исходная стоимость товара
 a - Увеличенная стоимость для получения первой скидки
 b - Увеличенная стоимость для получения второй скидки
 x - Значение первой скидки
 y - Значение второй скидки
 */

using namespace std;

int main() {
    
    double n, a, b, x, y, value;
    cin >> n >> a >> b >> x >> y;
    if (n > b) {
        value = n - (n * y * 0.01);
        cout << value;
    }
    if (n <= b && n > a) {
        value = n - (n * x * 0.01);
        cout << value;
    }
    if (n <= a) {
    value = n;
    cout << value;
    }
    
    return 0;
}
