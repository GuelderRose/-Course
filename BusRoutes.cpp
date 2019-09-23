#include<iostream>
#include<vector>
#include<string>
#include<map>

// https://www.coursera.org/learn/c-plus-plus-white/programming/1mOPD/avtobusnyie-ostanovki-2
int main() {
	int Q;
	std::cin >> Q;
	std::map<std::vector<std::string>, int> route;
	std::vector<std::vector<std::string>> commands;
	int number, busNumber = 1;
	std::vector<std::string> busStations;
	std::string busStation;
	for (int i = 0; i < Q; i++) {
		std::cin >> number;
		busStations.push_back(std::to_string(number));
		for (int j = 0; j < number; j++) {
			std::cin >> busStation;
			busStations.push_back(busStation);
		}
		commands.push_back(busStations);
		busStations.clear();
	}
	for (const auto& item : commands) {
		if (route.count(item) == 0) {
			route[item] = busNumber;
			std::cout << "New bus " << busNumber << std::endl;
			busNumber++;
		} else {
			std::cout << "Already exists for " << route[item] << std::endl;
		}
	}
	system("pause");
	return(0);
}