//
//  main.cpp
//  Buses1
//
//  Created by  Mister on 10/6/20.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

int main() {
    int Q;  // Количество операций
    int i = 0;
    std::string command;
    std::string bus, stop;
    int stop_count;
    std::map<std::string, std::vector<std::string>> buses;
    std::string names_of_stations;
    bool stop_finded = false;
    std::vector<std::string> order;
    bool interchange_finded = false;
    std::map<std::string, int> check;
    std::string tmp;
    
    
    std::cin >> Q;
    
    while(i < Q) {
        std::cin >> command;
        if (command == "ALL_BUSES") {
            // Здесь вывод всех маршрутов с остановками
            if (buses.size() == 0) {
                std::cout << "No buses" << std::endl;
            } else {
                for (const auto& [key, value] : buses) {
                    std::cout << "Bus " << key << ": ";
                    for (const auto& d : value) {
                        std::cout << d << " ";
                    }
                    std::cout << std::endl;
                }
            }
        } else if (command == "STOPS_FOR_BUS") {
            std::cin >> bus;
            // Здесь вывод названия всех остановок данного маршрута со списком автобусов, на которые можно пересесть
            if (buses.count(bus) == 0) {  // Если маршрута с таким названием не добавлено, то вывводим No bus
                std::cout << "No bus" << std::endl;
            } else {
                for (auto u : buses[bus]) { // u = "Vnukovo", "Moskovsky" ...
                    std::cout << "Stop " << u << ": ";  // Stop Vnukovo:
                    for (auto s : order) {  // s = "32", "32K", "950", "272"
                        if (s != bus) {
                            for (auto p : buses[s]) {  // Перебираем внутри нужного по порядку вектора остановок.
                                tmp = p;
                                interchange_finded = false;  // По умолчанию пересадок нет
                                if (p == u) {  // Если нашли данную остановку
                                    std::cout << s << " ";
                                    check[p]++;
                                    interchange_finded = true;
                                    break;
                                }
                            }
                        }
                    }
                    if (check[tmp] > 0) {
                        std::cout << "no interchange" << std::endl;
                    } else {
                        std::cout << std::endl;
                    }
                }
            }
        } else if (command == "BUSES_FOR_STOP") {
            std::cin >> stop;
            // Здесь вывод названий всех маршрутов, проходящих через данную остановку
            for (auto k : buses) {
                for (auto l : k.second) {
                    if (l == stop) {  // Если нашли остановку, то выводим соответствующее название маршрута
                        std::cout << k.first << " ";
                        stop_finded = true;  // Показываем, что остановка хотя бы раз нашлась
                    }
                }
            }
            if (stop_finded != true) {
                std::cout << "No stop";
            }
            std::cout << std::endl;
        } else if (command == "NEW_BUS") {
            std::cin >> bus >> stop_count;
            order.push_back(bus);  // Здесь маршруты отсортированы по порядку добавления 0:32, 1:32k, 2:950, 3:272
            for (int j = 0; j <= stop_count - 1; ++j) {
                std::cin >> names_of_stations;
                buses[bus].push_back(names_of_stations);
            }
        }
        ++i;
    }
    return 0;
}
