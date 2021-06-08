//
//  main.cpp
//  Buses2
//
//  Created by  Mister on 14.10.2020.
//

#include <iostream>
#include <map>
#include <vector>


int main() {
    int Q;  // Количество операций
    int i = 0;
    int N;  // Количество остановок
    std::vector<std::vector <std::string>> buses(1);  // Здесь все несортированные вводы
    int dump_index = 0;
    std::string str;
    std::string stop_tmp;
    int new_bus = 0;  // Счетчик новых уникальных маршрутов
    std::vector<std::vector <std::string>> buses_sorted(1);  // А здесь будут только уникальные (неповторяющиеся) маршруты
    bool flag = false;
    bool flag2 = false;
    bool flag3 = false;
    int position;
    
    std::cin >> Q;
    while (i < Q) {
        
        std::cin >> N;  // Ввод количества остановок
        buses[i].resize(N);  // Подготавливаем вложенный вектор к вводу в него остановок
        for (int j = 0; j <= N - 1; ++j) {  // Добавляем остановки
            std::cin >> stop_tmp;
            buses[i][j] = stop_tmp;
        }
        if (i > 0) {  //  Нулевой маршрут проверять не с чем, поэтому начинаем с первого
            flag2 = false;  // Изначальная позиция флага–указателя повторяющегося маршрута
            for (int n = 0; n <= buses.size() - 2; ++n) {
                if (buses[buses.size() - 1] == buses[n]) {
                    flag2 = true; // Указывает, что найден повторящийся маршрут и добавлять его в вектор с уникальными маршрутами не надо
                    break;
                }
            }
            if (flag2 != true) {  // Введенный маршрут –– новый, поэтому добавляем его в вектор уникальных маршрутов
                buses_sorted.push_back(buses[buses.size() - 1]);
                flag3 = true;  // Ставим пометку, что добавили маршрут только что
            }
        }
        if (i > 0) {  // Первый маршрут не сравниваем
            flag = false;
            for (int s = 0; s <= buses_sorted.size() - 1; ++s) {  // s –– перебирает маршруты в векторе уникальных маршрутов, беря все
                if (buses[i] == buses_sorted[s] && flag3 != true) {  // Сравниваем только что введенный маршрут с уникальными маршрутами, хранящимися в buses_sorted
                    flag = true;  // Нашли совпадающий маршрут
                    position = s + 1;  // Сохранили порядковый номер найденного маршрута
                    break;
                }
            }
            if (flag == true) {
                std::cout << "Already exists for " << position << std::endl;
            } else {
                new_bus++;
                std::cout << "New bus " << new_bus << std::endl;
            }
        } else {  // Добавляем первый маршрут
            new_bus++;
            std::cout << "New bus " << new_bus << std::endl;
            buses_sorted[i] = buses[i];
        }
        ++i;
        ++dump_index;
        buses.resize(dump_index + 1);  // Увеличиваем размер под следующий возможный маршрут
        flag3 = false;
    }
    return 0;
}
