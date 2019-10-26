#include <iostream>
#include <vector>
#include <string>
#include <exception>

// https://www.coursera.org/learn/c-plus-plus-white/programming/gLemQ/iezhiemiesiachnyie-diela
/*У каждого из нас есть ежемесячные дела,
каждое из которых нужно выполнять в конкретный день каждого месяца
оплата счетов за электричество, абонентская плата за связь и пр.
Вам нужно реализовать работу со списком таких дел, а именно, обработку следующих операций:
ADD i s
Добавить дело с названием s в день i.
NEXT
Закончить текущий месяц и начать новый. Если новый месяц имеет больше дней, чем текущий,
добавленные дни изначально не будут содержать дел. Если же в новом месяце меньше дней,
дела со всех удаляемых дней необходимо будет переместить на последний день нового месяца.
Обратите внимание, что количество команд этого типа может превышать 11.
DUMP i
Вывести все дела в день i.
Изначально текущим месяцем считается январь. Количества дней в месяцах соответствуют
Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.
Формат ввода
Сначала число операций Q, затем описания операций.
Названия дел s уникальны и состоят только из латинских букв, цифр и символов подчёркивания.
Номера дней i являются целыми числами и нумеруются от 1 до размера текущего месяца.
Формат вывода
Для каждой операции типа DUMP в отдельной строке выведите количество дел в соответствующий день,
а затем их названия, разделяя их пробелом. Порядок вывода дел в рамках каждой операции значения не имеет.*/
void AddCommandAdd(std::vector<std::vector<std::string>>& Сommands, 
    const std::string& command, const int i) {
    std::string day, deal;
    std::cin >> day >> deal;
    Сommands[i].push_back(command);
    Сommands[i].push_back(day);
    Сommands[i].push_back(deal);
}
void AddCommandDump(std::vector<std::vector<std::string>>& Сommands, 
    const std::string& command, const int i) {
    std::string day;
    std::cin >> day;
    Сommands[i].push_back(command);
    Сommands[i].push_back(day);
}
void CallCommandAdd(const std::vector<std::vector<std::string>>& Сommands,
    const std::vector<int>& DaysInMonth, 
    std::vector<std::vector<std::string>>& Days,
    int next_month, int i) {
    if (std::stoi(Сommands[i][1]) > DaysInMonth[next_month]) {
        throw std::runtime_error("There is no such number in this month");
    } else {
        Days[stoi(Сommands[i][1]) - 1].push_back(Сommands[i][2]);
    }
}
void CallCommandNext(const std::vector<std::vector<std::string>>& Сommands,
    const std::vector<int>& DaysInMonth,
    std::vector<std::vector<std::string>>& Days,
    int& next_month, int i) {
    next_month++;
    if (next_month == 12) {
        next_month = 1;
    }
    if (DaysInMonth[next_month] > DaysInMonth[next_month - 1]) {
        for (int j = DaysInMonth[next_month - 1];
            j < DaysInMonth[next_month] + 1; j++) {
            std::vector<std::string> oneDay;
            Days.push_back(oneDay);
        }
    }
    if (DaysInMonth[next_month] < DaysInMonth[next_month - 1]) {
        std::vector<std::vector<std::string>> Days1(DaysInMonth[next_month]);
        for (int j = 0; j < Days1.size(); j++) {
            Days1[j] = Days[j];
        }
        for (int j = 0;
            j < DaysInMonth[next_month - 1] - DaysInMonth[next_month]; j++) {
            if (Days[DaysInMonth[next_month] + j].size() != 0) {
                Days1[Days1.size() - 1].insert(end(Days1[Days1.size() - 1]),
                    begin(Days[DaysInMonth[next_month] + j]), 
                    end(Days[DaysInMonth[next_month] + j]));
            }
        }
        Days = Days1;
    }
}
void CallCommandDump(const std::vector<std::vector<std::string>>& Сommands,
    const std::vector<int>& DaysInMonth, 
    std::vector<std::vector<std::string>>& Days,
    int next_month, int i) {
    if (std::stoi(Сommands[i][1]) > DaysInMonth[next_month]) {
        throw std::runtime_error("There is no such number in this month");
    } else {
        std::cout << Days[stoi(Сommands[i][1]) - 1].size() << "  ";
        for (int j = 0; j < Days[stoi(Сommands[i][1]) - 1].size(); j++) {
            std::cout << Days[stoi(Сommands[i][1]) - 1][j] << "  ";
        }
        std::cout << std::endl;
    }
}
int main() {
    std::vector<std::vector<std::string>> Days(31);
    std::vector<int> DaysInMonth{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int number_of_operations = 0;
    int next_month = 0;
    std::cout << "Enter the number of commands : ";
    std::cin >> number_of_operations;
    std::vector<std::vector<std::string>> Сommands(number_of_operations);
    std::string command, day, deal;
    std::cout << "Enter commands: " << std::endl;
    for (int i = 0; i < number_of_operations; i++) {
        std::cin >> command;
        if (command == "ADD" || command == "DUMP" || command == "NEXT") {
            if (command == "ADD") {
                AddCommandAdd(Сommands, command, i);
            }
            if (command == "DUMP") {
                AddCommandDump(Сommands, command, i);
            }
            if (command == "NEXT") {
                Сommands[i].push_back(command);
            }
        } else {
            Сommands[i].push_back("Wrong command");
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < number_of_operations; i++) {
        try {
            if (Сommands[i][0] == "ADD") {
                CallCommandAdd(Сommands, DaysInMonth, Days, next_month, i);
            }
        } catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        if (Сommands[i][0] == "NEXT") {
            CallCommandNext(Сommands, DaysInMonth, Days, next_month, i);
        }
        try {
            if (Сommands[i][0] == "DUMP") {
                CallCommandDump(Сommands, DaysInMonth, Days, next_month, i);
            }
        } catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        if (Сommands[i][0] == "Wrong command") {
            std::cout << "Wrong command" << std::endl;
        }
    }
    return 0;
}