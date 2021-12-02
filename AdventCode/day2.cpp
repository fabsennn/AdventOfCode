#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int readData() {
	int hor = 0, vert = 0;
	ifstream input("input2.txt");

	int result = 0;
	vector<vector<string>> movement;

	for (string line; getline(input, line); ) {
		movement.resize(movement.size() + 1);
		string s = line;
		string delimiter = " ";
		size_t pos = 0;
		string token;
		int i = 0;

		while ((pos = s.find(delimiter)) != string::npos) {
			token = s.substr(0, pos);
			movement[movement.size() - 1][i] = token; 
			s.erase(0, pos + delimiter.length());
			i++;
		}
		
		
		//movement[movement.size() - 1][0] = ;
		//movement[movement.size() - 1][1] = ;
	}


	for (int i = 0; i < movement.size()-1 ; i++) {
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

