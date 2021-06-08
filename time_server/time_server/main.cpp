//
//  main.cpp
//  time_server
//
//  Created by  Mister on 15.11.2020.
//

#include <iostream>
#include <exception>
#include <string>
#include <system_error>
using namespace std;

string AskTimeServer() {
    std::string str = "11:11:00";  // Верное время
        if (str == "11:11:00") {  // Сетевые проблемы
            throw std::system_error(std::error_code());
        } else if (str == "11:11:XX") {
            throw exception();
        }
        return str;  // "11:11:11"
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
            return last_fetched_time;
        } catch (std::system_error&) {
            return last_fetched_time;
        }
        catch (...) {
            throw;
        }
        
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
