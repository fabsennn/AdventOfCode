#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int readData() {

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

int main() {
	cout << readData() << "\n";

	system("PAUSE");
}
