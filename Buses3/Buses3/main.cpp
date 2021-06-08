//
//  main.cpp
//  Buses3
//
//  Created by  Mister on 18.10.2020.
//

#include <iostream>
#include <set>
#include <map>

int main() {
    int Q;  // Количество операций
    int i = 0;
    int N;  // Количество остановок
    std::map<std::set<std::string>, int> buses;
    int order = 1;
    
    std::cin >> Q;
    while (i < Q) {
        std::cin >> N;  // Ввод количества остановок
        
        std::set<std::string> stops;  // Список остановок конкретного добавляемого маршрута
        for (int j = 0; j < N; ++j) {
            std::string stop;
            std::cin >> stop;
            stops.insert(stop);
        }
        if (buses.count(stops) == 1) {  // Проверяем есть ли уже такой маршрут
            std::cout << "Already exists for " << buses[stops] << std::endl;
        } else {
            
            // buses.insert(std::pair<std::set, int>(stops, order));
            buses[stops] = order;
            std::cout << "New bus " << buses[stops] << std::endl;
            order++;
        }
        ++i;
    }
    
    return 0;
}
