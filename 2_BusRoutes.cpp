#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

//https://www.coursera.org/learn/c-plus-plus-white/programming/WRbZE/sinonimy
/*
Два слова называются синонимами друг друга, если они имеют похожие значения.
Реализуйте следующие операции над словарём синонимов:

- ADD word1 word2 — добавить в словарь пару синонимов (word1, word2).
- COUNT word — узнать количество синонимов слова word.
- CHECK word1 word2 — проверить, являются ли слова word1 и word2 синонимами.
Слова word1 и word2 считаются синонимами, если среди запросов ADD
был хотя бы один запрос ADD word1 word2 или ADD word2 word1.

Формат ввода
Сначала вводится количество запросов Q, затем Q строк с описаниями запросов.
Гарантируется, что в каждом запросе CHECK и ADD слова word1 и word2 различны.
Все слова состоят лишь из латинских букв, цифр и символов подчёркивания.

Формат вывода
Для каждого запроса в соответствующей строке выведите ответ на него:
В ответ на запрос COUNT word выведите единственное целое число — количество синонимов слова word.
В ответ на запрос CHECK word1 word2 выведите строку YES, если word1 и word2 являются синонимами, и NO в противном случае.
*/

int main() {
    int number_of_commands = 0;
    std::cout << "Enter the number of commands : ";
    std::cin >> number_of_commands;
    std::vector<std::vector<std::string>> Commands(number_of_commands);
    std::string command, word, word1, word2;
    std::cout << "Enter commands: " << std::endl;
    for (int i = 0; i < number_of_commands; i++) {
        std::cin >> command;
        if (command == "ADD" || command == "CHECK" || command == "COUNT") {
            if ((command == "ADD") || (command == "CHECK")) {
                std::cin >> word1 >> word2;
                Commands[i].push_back(command);
                Commands[i].push_back(word1);
                Commands[i].push_back(word2);
            }
            if (command == "COUNT") {
                std::cin >> word;
                Commands[i].push_back(command);
                Commands[i].push_back(word);
            }
        } else {
            Сommands[i].push_back("Wrong command");
        }
    }
    std::map<std::string, std::set<std::string>> SynonymDictionary;
    for (int i = 0; i < number_of_commands; i++) {
        if (Commands[i][0] == "ADD") {
            SynonymDictionary[Commands[i][1]].insert(Commands[i][2]);
            SynonymDictionary[Commands[i][2]].insert(Commands[i][1]);
        }
        if (Commands[i][0] == "COUNT") {
            std::cout << SynonymDictionary[Commands[i][1]].size() << std::endl;
        }
        if (Commands[i][0] == "CHECK") {
            if (SynonymDictionary[Commands[i][1]].count(Commands[i][2]) == 1) {
                std::cout << "YES" << std::endl;
            }
            else {
                std::cout << "NO" << std::endl;
            }
        }
        if (Сommands[i][0] == "Wrong command") {
            std::cout << "Wrong command" << std::endl;
        }
    }
    return(0);
}
