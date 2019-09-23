#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;
int main() {
	int Q;
	cin >> Q;
	map<vector<string>, int> route;
	vector<vector<string>> commands;
	int number, busNumber = 1;
	vector<string> busStations;
	string busStation;
	for (int i = 0; i < Q; i++){
		cin >> number;
		busStations.push_back(to_string(number));
		for (int j = 0; j < number; j++){
			cin >> busStation;
			busStations.push_back(busStation);
		}
		commands.push_back(busStations);
		busStations.clear();
	}
	for (const auto& item:commands) {
		if (route.count(item) == 0) {
			route[item] = busNumber;
			cout << "New bus " << busNumber << endl;
			busNumber++;
		}
		else {
			cout << "Already exists for " << route[item] << endl;
		}
	}
	system("pause");
	return(0);
}