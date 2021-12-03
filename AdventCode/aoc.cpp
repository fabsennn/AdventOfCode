#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int day1() {

	ifstream input("input.txt");

	int result = 0;
	vector<int> measurements;

	for (std::string line; getline(input, line); ) {
		int newVal = stoi(line);
		measurements.push_back(newVal);
	}


	for (int i = 0; i < measurements.size() - 3; i++) {
		int sumA, sumB;
		sumA = measurements[i]   + measurements[i+1] + measurements[i+2];
		sumB = measurements[i+1] + measurements[i+2] + measurements[i+3];


		if (sumB> sumA)
			result++;
	}

	return result;
}
int day2() {

int hor = 0, vert = 0;
ifstream input("input2.txt");

int result = 0;
vector<vector<string>> movement;

for (string line; getline(input, line); ) {
	movement.resize(movement.size() + 1);
	string s = line;
	string delimiter = " ";
	size_t pos = s.find(delimiter);
	string direction = s.substr(0, pos);
	string number = s.substr(pos + 1, s.length() - pos -1);
	

	movement[movement.size() - 1].push_back(direction);
	movement[movement.size() - 1].push_back(number);
}


for (int i = 0; i < movement.size() - 1; i++) {
	int val = stoi(movement[i][1]);

	if (movement[i][0] == "forward") {
		hor = hor + val;
	}
	else if (movement[i][0] == "down") {
		vert = vert + val;
	}
	else if (movement[i][0] == "up") {
		vert = vert - val;
	}
}

return hor * vert;
}

int main() {
	//cout << day1() << "\n";
	cout << day2() << "\n";

	system("PAUSE");
}
