#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>

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

Пример
Ввод

8
ADD program code
COUNT cipher
ADD code cipher
COUNT code
COUNT program
CHECK code program
CHECK program cipher
CHECK cpp java

Вывод

0
2
1
YES
NO
NO
*/

int main() {
    int Q = 0;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите количество операций: ";
    std::cin >> Q;
    std::vector<std::vector<std::string>> commands(Q);
    std::string command, word, word1, word2;
    for (int i = 0; i < Q; i++) {
        std::cout << "Введите операции: " << std::endl;
        std::cin >> command;
        if ((command == "ADD") || (command == "CHECK")) {
            std::cin >> word1 >> word2;
            commands[i].push_back(command);
            commands[i].push_back(word1);
            commands[i].push_back(word2);
        }
        if (command == "COUNT") {
            std::cin >> word;
            commands[i].push_back(command);
            commands[i].push_back(word);
        }
    }
    std::map<std::string, std::set<std::string>> synonymDictionary;
    for (int i = 0; i < Q; i++) {
        if (commands[i][0] == "ADD") {
            synonymDictionary[commands[i][1]].insert(commands[i][2]);
            synonymDictionary[commands[i][2]].insert(commands[i][1]);
        }
        if (commands[i][0] == "COUNT") {
            std::cout << synonymDictionary[commands[i][1]].size() << std::endl;
        }
        if (commands[i][0] == "CHECK") {
            if (synonymDictionary[commands[i][1]].count(commands[i][2]) == 1) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    return(0);
}