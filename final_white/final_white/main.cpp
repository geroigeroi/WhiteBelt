//
//  main.cpp
//  final_white
//
//  Created by  Mister on 19.11.2020.
//

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>

class Date {
public:
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
    void SetYear(int new_year) {
        year = new_year;
    }
    void SetMonth(int new_month) {
        month = new_month;
    }
    void SetDay(int new_day) {
        day = new_day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            if (lhs.GetDay() < rhs.GetDay()) {
                return true;
            } else {
                return false;
            }
        } else if (lhs.GetMonth() < rhs.GetMonth()) {
            return true;
        } else {
            return false;
        }
    } else if (lhs.GetYear() < rhs.GetYear()) {
        return true;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& stream, const Date& date) {
    stream << std::setfill('0');
    stream << std::setw(4) << date.GetYear() << "-"
           << std::setw(2) << date.GetMonth() << "-"
           << std::setw(2) << date.GetDay();
    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const std::string& event) {
        if (databaseEntry.count(date) == true) {
            databaseEntry[date].insert(event);
        } else {
            std::set<std::string> addEvent;
            addEvent.insert(event);
            databaseEntry[date] = addEvent;
        }
    }
    bool DeleteEvent(const Date& date, const std::string& event) {
        if (databaseEntry.count(date) == true) {  // Такая дата была ранее добавлена
            if (databaseEntry[date].count(event) == true) {  // В указанную дату есть указанное событие
                databaseEntry[date].erase(event);  // Удалили это событие
                return true;  // и вернули true –– событие было найдено и успешно удалено
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    int DeleteDate(const Date& date) {
        int deletedEvents;
        if (databaseEntry.count(date) == false) {  // Если такой даты не было добавлено ранее,
            deletedEvents = 0;  // то возвращаем, что удаленных событий 0
        } else {  // Если дата ранее добавлена была
            deletedEvents = (int)databaseEntry[date].size();
            databaseEntry[date].clear();
        }
        return deletedEvents;
    }
    
    std::set<std::string> Find(const Date& date) const {
        if (databaseEntry.count(date) == false) {  // Если такой даты не было добавлено ранее,
            std::set<std::string> emptySet;
            return emptySet;
        } else {
            return databaseEntry.at(date);
        }
    }
    
    void Print() const {
        for (const auto& [key, value] : databaseEntry) {
            if (value.empty() == false) {  // Если дата есть, и в ней есть события
                for (auto i : value) {
                    std::cout << key << " " << i << "\n";
                }
            }
        }
    }
private:
    std::map<Date, std::set<std::string>> databaseEntry;
};

Date ParseDate(std::string& parseNewDate) {
    for (int i = 0; i < parseNewDate.length(); ++i) {
        if ((parseNewDate[i] < 48 || parseNewDate[i] > 57) && (parseNewDate[i] != 43 && parseNewDate[i] != 45)) {  // Проверяю, что в дате могут быть только цифры, знаки "+" и "-", более ничего
            std::string error = "Wrong date format: " + parseNewDate;
            throw std::runtime_error(error);
        }
    }
    Date newDate;
    bool isYearNegative = false;
    int year, month, day;
    int first_dash, last_dash;
    std::string parseNewDate_CheckedForNegativeYear = parseNewDate;
    if (parseNewDate[0] == '-') {  // Год начинается с "-"
        isYearNegative = true;
        parseNewDate_CheckedForNegativeYear.erase(0, 1);
    }
    first_dash = (int)parseNewDate_CheckedForNegativeYear.find('-', 0);
    last_dash = (int)parseNewDate_CheckedForNegativeYear.rfind('-', parseNewDate_CheckedForNegativeYear.length() - 2);
    if (first_dash == last_dash) {  // Есть только год и месяц
        std::string error = "Wrong date format: " + parseNewDate;
        throw std::runtime_error(error);
    }
    if (parseNewDate_CheckedForNegativeYear[parseNewDate_CheckedForNegativeYear.length() - 1] == '-') {  // Проверяем последний символ, он не должен быть дефисом
        std::string error = "Wrong date format: " + parseNewDate;
        throw std::runtime_error(error);
    }
    int dashBetweenMonthAndday = 0;
    for (int j = last_dash; j > first_dash ;--j) {
        if (parseNewDate_CheckedForNegativeYear[j] >= 48 && parseNewDate_CheckedForNegativeYear[j] <= 58) { // Проверяем символ является ли он числом
            dashBetweenMonthAndday = j + 1;
            break;
        }
    }
    std::string year_str = parseNewDate.substr(0, first_dash);
    std::string month_str = parseNewDate.substr(first_dash + 1, dashBetweenMonthAndday - first_dash - 1);
    std::string day_str = parseNewDate.substr(dashBetweenMonthAndday + 1);
    year = std::stoi(year_str);
    try {
        month = std::stoi(month_str);
    } catch (const std::invalid_argument& ex) {
        std::string error = "Wrong date format: " + parseNewDate;
        throw std::runtime_error(error);
    }
    if (month < 1 || month > 12) {  // Формат месяца неверный
        std::string error = "Month value is invalid: " + month_str;
        throw std::runtime_error(error);
    }
    try {
        day = std::stoi(day_str);
    } catch (const std::invalid_argument& ex) {
        std::string error = "Wrong date format: " + parseNewDate;
        throw std::runtime_error(error);
    }
    if (day < 1 || day > 31) {
        std::string error = "Day value is invalid: " + day_str;
        throw std::runtime_error(error);
    }
    newDate.SetYear(year);
    newDate.SetMonth(month);
    newDate.SetDay(day);
    return newDate;
}

std::string ParseMainCommand(std::string& command) {
    int firstWhitespacePos = (int)command.find(' ');  // Нашли первое вхождение пробела
    std::string mainCommand = command.substr(0, firstWhitespacePos);  // Вычленили первую команду
    command = command.substr(firstWhitespacePos + 1);  // Здесь остаток команды
    return mainCommand;
}

std::string ParseEvent(std::string& commandWithoutMainCommand) {
    int secondWhitespacePos = (int)commandWithoutMainCommand.find(' ');  // Нашли второе вхождение пробела
    std::string event = commandWithoutMainCommand.substr(secondWhitespacePos + 1);
    commandWithoutMainCommand = commandWithoutMainCommand.substr(0, secondWhitespacePos);
    return event;
}

int main() {
    Database db;
    std::string command;
    while (getline(std::cin, command)) {
        std::string mainCommand = ParseMainCommand(command);
        
        if (mainCommand == "Print") {
            db.Print();
        } else if (mainCommand == "Find") {
            Date dateToFind;
            try {
                dateToFind = ParseDate(command);
            } catch (std::exception& ex) {
                std::cout << ex.what() << "\n";
                break;
            }
            std::set<std::string> eventsOnDate = db.Find(dateToFind);
            for (auto i : eventsOnDate) {
                std::cout << i << "\n";
            }
        } else if (mainCommand == "Del") {
            if (command.find(' ') == -1) {  // Команда Del без указания конкретного собятия
                Date dateWhenDellAllEvents;
                try {
                    dateWhenDellAllEvents = ParseDate(command);
                } catch (std::exception& ex) {
                    std::cout << ex.what() << "\n";
                    break;
                }
                std::cout << "Deleted " << db.DeleteDate(dateWhenDellAllEvents) << " events\n";
            } else {  // Есть событие
                std::string eventToDel = ParseEvent(command);
                Date dateWhenDelEvent;
                try {
                    dateWhenDelEvent = ParseDate(command);
                } catch (std::exception& ex) {
                    std::cout << ex.what() << "\n";
                    break;
                }
                if (db.DeleteEvent(dateWhenDelEvent, eventToDel) == true) {
                    std::cout << "Deleted successfully\n";
                } else {
                    std::cout << "Event not found\n";
                }
            }
        } else if (mainCommand == "Add") {
            std::string new_event = ParseEvent(command);
            Date new_date;
            try {
                new_date = ParseDate(command);
            } catch (std::exception& ex) {
                std::cout << ex.what() << "\n";
                break;
            }
            db.AddEvent(new_date, new_event);
        } else if (mainCommand == "\0" || mainCommand == "\t") {
            continue;
        } else {
            std::cout << "Unknown command: " << mainCommand << "\n";
            break;
        }
    }
    return 0;
}
