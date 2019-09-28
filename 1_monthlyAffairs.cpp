#include<iostream>
#include<vector>
#include<string>

// https://www.coursera.org/learn/c-plus-plus-white/programming/gLemQ/iezhiemiesiachnyie-diela
/*
У каждого из нас есть ежемесячные дела,
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
а затем их названия, разделяя их пробелом. Порядок вывода дел в рамках каждой операции значения не имеет.

Пример
Ввод

12
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 5
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28

Вывод

1 Salary
2 WalkPreparations Walk
0
0
2 WalkPreparations Walk
3 WalkPreparations Walk Payment
*/
int main() {
    std::vector<std::vector<std::string>> days(31);
    std::vector<int> daysInMonth { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int Q = 0;
    int next = 0;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите количество операций: ";
    std::cin >> Q;
    std::vector<std::vector<std::string>> commands(Q);
    std::string command, day, deal;
    for (int i = 0; i < Q; i++) {
        std::cin >> command;
        if (command == "ADD") {
            std::cin >> day >> deal;
            commands[i].push_back(command);
            commands[i].push_back(day);
            commands[i].push_back(deal);
        }
        if (command == "DUMP") {
            std::cin >> day;
            commands[i].push_back(command);
            commands[i].push_back(day);
        }
        if (command == "NEXT") {
            commands[i].push_back(command);
        }
    }
    for (int i = 0; i < Q; i++) {
        if (commands[i][0] == "ADD") {
            days[stoi(commands[i][1]) - 1].push_back(commands[i][2]);
        }
        if (commands[i][0] == "NEXT") {
            next++;
            if (next == 12) {
                next = 1;
            }
            if (daysInMonth[next] > daysInMonth[next - 1]) {
                for (int j = daysInMonth[next - 1]; j < daysInMonth[next] + 1; j++) {
                    std::vector<std::string> oneDay;
                    days.push_back(oneDay);
                }
            }
            if (daysInMonth[next] < daysInMonth[next - 1]) {
                std::vector<std::vector<std::string>> days1(daysInMonth[next]);
                for (int j = 0; j < days1.size(); j++) {
                    days1[j] = days[j];
                }
                for (int j = 0; j < daysInMonth[next - 1] - daysInMonth[next]; j++) {
                    if (days[daysInMonth[next] + j].size() != 0) {
                        days1[days1.size() - 1].insert(end(days1[days1.size() - 1]), begin(days[daysInMonth[next] + j]), end(days[daysInMonth[next] + j]));
                    }
                }
                days = days1;
            }
        }
        if (commands[i][0] == "DUMP") {
            std::cout << days[stoi(commands[i][1]) - 1].size() << "  ";
            for (int j = 0; j < days[stoi(commands[i][1]) - 1].size(); j++) {
                std::cout << days[stoi(commands[i][1]) - 1][j] << "  ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}


