#include <iostream>
#include <map>
#include<vector>
#include<string>

//https://www.coursera.org/learn/c-plus-plus-white/programming/4FQn4/imiena-i-familii-1
/*
Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.

class Person {
public:
void ChangeFirstName(int year, const string& first_name) {
// добавить факт изменения имени на first_name в год year
}
void ChangeLastName(int year, const string& last_name) {
// добавить факт изменения фамилии на last_name в год year
}
string GetFullName(int year) {
// получить имя и фамилию по состоянию на конец года year
}
private:
// приватные поля
};

Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени. 
При этом с течением времени могут открываться всё новые факты из прошлого человека, 
поэтому года́ в последовательных вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.

Гарантируется, что все имена и фамилии непусты.

Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и фамилию человека 
по состоянию на конец данного года.

Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
Если к данному году случилось изменение фамилии, но не было ни одного изменения имени,
верните "last_name with unknown first name".
Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, 
верните "first_name with unknown last name".

Пример
Код

int main() {
Person person;

person.ChangeFirstName(1965, "Polina");
person.ChangeLastName(1967, "Sergeeva");
for (int year : {1900, 1965, 1990}) {
cout << person.GetFullName(year) << endl;
}

person.ChangeFirstName(1970, "Appolinaria");
for (int year : {1969, 1970}) {
cout << person.GetFullName(year) << endl;
}

person.ChangeLastName(1968, "Volkova");
for (int year : {1969, 1970}) {
cout << person.GetFullName(year) << endl;
}

return 0;
}

Вывод

Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria Sergeeva
Polina Volkova
Appolinaria Volkova
*/

class Person {
    public:
    void ChangeFirstName(int year, const std::string& first_name) {
        FullNameForYear[year].firstName = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        FullNameForYear[year].lastName = last_name;
    }
    std::string GetFullName(int year) {
        for (auto& item : FullNameForYear) {
            if (year < item.first) {
                return "Incognito";
            } else {
                break;
            }
        }
        std::string name, surname;
        if (FullNameForYear.count(year) == 0) {
            for (auto& item : FullNameForYear) {
                if (item.first > year) {
                    break;
                }
                if (item.second.firstName != "") {
                    name = item.second.firstName;
                }
                if (item.second.lastName != "") {
                    surname = item.second.lastName;
                }
            }
            if ((name == "") || (surname == "")) {
                if (name == "") {
                    return surname + " with unknown first name";
                } else {
                    return name + " with unknown last name";
                }
            } else {
                return name + " " + surname;
            }
        }
        if (FullNameForYear[year].firstName == "") {
            for (auto& item : FullNameForYear) {
                if (item.first > year) {
                    break;
                }
                if (item.second.firstName != "") {
                    name = item.second.firstName;
                }
            }
            if (name == "") {
                return FullNameForYear[year].lastName + " with unknown first name";
            } else {
                return name + " " + FullNameForYear[year].lastName;
            }
        } else {
            for (auto& item : FullNameForYear) {
                if (item.first > year) {
                    break;
                }
                if (item.second.lastName != "") {
                    surname = item.second.lastName;
                }
            }
            if (surname == "") {
                return FullNameForYear[year].firstName + " with unknown last name";
            } else {
                return FullNameForYear[year].firstName + " " + surname;
            }
        }
    }
    
    private:
    struct Name {
        std::string firstName = "";
        std::string lastName = "";
    };
    std::map<int, Name> FullNameForYear;
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
    system("pause");
    return(0);
}
