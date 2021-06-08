//
//  main.cpp
//  Names1
//
//  Created by  Mister on 19.10.2020.
//

#include <iostream>
#include <vector>
#include <map>

class Person {
public:
    void AddAnyName(int year, const std::string& name, bool isFirstName) {
        std::vector<std::string> vectorName;  // Создали словарь из двух строк: имя и фамилия
        vectorName.resize(2); // Выделяем в векторе две строки: для имени и фамилии
        if (isFirstName == true) {  // Добавляем ИМЯ
            vectorName[0] = name;
        } else {  // Добавляем ФАМИЛИЮ
            vectorName[1] = name;
        }
        OnePerson.insert(std::make_pair(year, vectorName));  // Добавили в словарь пару год –– вектор с внесенным именем
    }
    
    void ChangeFirstName(int year, const std::string& first_name) {
        bool isFirstName = true;
        if (OnePerson.empty() == false) {  // Если НЕ пустой, т.е. уже НЕ первое внесение
            std::vector<std::string> addedName;
            addedName.resize(2);
            if (OnePerson.count(year) == 1) {  // Проверка, что этот год уже был добавлен ранее. Тогда запишем в эту же пару
                addedName[1] = OnePerson[year][1];  // Взял из добавленного ранее года сохраненное там значение фамилии
            }
            addedName[0] = first_name;
            OnePerson[year] = addedName;
            
        } else {  // Если пустой, т.е. это первое добавление
            AddAnyName(year, first_name, isFirstName);
        }
    }
    
    void ChangeLastName(int year, const std::string& last_name) {
        bool isFirstName = false;
        if (OnePerson.empty() == false) {  // Если НЕ пустой!
            std::vector<std::string> addedName;
            addedName.resize(2);
            if (OnePerson.count(year) == 1) {  // Проверка, что этот год уже был добавлен ранее. Тогда запишем в эту же пару
                addedName[0] = OnePerson[year][0];  // Взял из добавленного ранее года сохраненное там значение имени
            }
            addedName[1] = last_name;
            OnePerson[year] = addedName;
        } else {  // Если пустой, т. е. это первое добавление
            AddAnyName(year, last_name, isFirstName);
        }
    }
    
    std::string GetFullName(int year) {
        std::string output;
        if (OnePerson.empty() == true) {  // Сразу проверяем, что если ничего внесено не было, то и проверять нечего.
            return output = "Incognito";
        }
        std::map<int, std::vector<std::string>> :: iterator it_begin = OnePerson.end(); // Итератор на начало словаря (сортировка словаря –– обратная)
        std::string LNforOutput, FNforOutput;
        it_begin--;
        if ((*it_begin).first > year) {  // Если проверяемый год меньше самого меньшего уже добавленного года
            return output = "Incognito";
        }
        std::map<int, std::vector<std::string>> :: iterator it;  // Итератор, который будет искать запись года, который НЕ БОЛЬШЕ (меньшая либо равная) входного
        it = OnePerson.lower_bound(year);
        if ((*it).second[0] == "") {  // Если имени нет, но есть фамилия
            LNforOutput = (*it).second[1];  // Сохранили фамилию для последующего вывода
            for (it; it != OnePerson.end(); ++it) {  // Движемся по годам в сторону уменьшения года
                if ((*it).second[0] != "") {  // Нашли имя
                    FNforOutput = (*it).second[0];
                    return output = FNforOutput + " " + LNforOutput;
                }
            }
            return output = LNforOutput + " with unknown first name";
        } else if ((*it).second[1] == "") {  // Если фамилии нет, но есть имя
            FNforOutput = (*it).second[0];  // Сохранили имя для последующего вывода
            for (it; it != OnePerson.end(); ++it) {  // Движемся по годам в сторону уменьшения года
                if ((*it).second[1] != "") {  // Нашли фамилию
                    LNforOutput = (*it).second[1];
                    return output = FNforOutput + " " + LNforOutput;;
                }
            }
            return output = FNforOutput + " with unknown last name";
        } else {  // Тот случай, когда ранее для данного года было добавлено как имя, так и фамилия. А значит либо то, либо другое искать, двигаясь по годам назад, не нужно
            FNforOutput = (*it).second[0];
            LNforOutput = (*it).second[1];
            return output = FNforOutput + " " + LNforOutput;
        }
    }
private:
    // приватные поля
    std::map< int, std::vector<std::string>, std::greater<int> > OnePerson;  // Словарь создаем с сортировкой в порядке уменьшения ключей
};

int main() {
    
    Person person;
      
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullName(year) << std::endl;
    }
      
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }
      
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }
      
    person.ChangeLastName(1960, "Pupsikova");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullName(year) << std::endl;
    }
    
    return 0;
}
