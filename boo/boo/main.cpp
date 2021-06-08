//
//  main.cpp
//  boo
//
//  Created by  Mister on 30.10.2020.
//

#include <iostream>
 
int main()
{
    int array[4] = { 5, 8, 6, 4 };
 
    // Выводим значение массива (переменной array)
    std::cout << "The array has address: " << array << '\n';
 
    // Выводим адрес элемента массива
    std::cout << "Element 0 has address: " << &array[0] << '\n';
 
    return 0;
}
