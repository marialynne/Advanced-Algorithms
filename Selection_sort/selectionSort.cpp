#include <bits/stdc++.h> 
using namespace std;

vector<int> randomNumbers(vector<int> numbers, int n, int maxNumber) {
	for(int i = 0; i < n; i++) {
	    numbers.push_back(rand() % maxNumber);
	}
	return numbers;
}

void print(vector<int> numbers, int n) {
	cout << "\t";
	for(int i = 0; i < n; i++)
		cout << numbers[i] << " ";
	cout << endl;
}

int main() {
	vector<int> numbers;
	int n = 10;
	int maxNumber = 20;

	numbers = randomNumbers(numbers,n,maxNumber);

	cout << "Input vector: " << endl;
	print(numbers,n);

}
