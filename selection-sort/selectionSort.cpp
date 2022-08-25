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

vector<int> selectionSort(vector<int> numbers, int n, int step) {                                                                          

    if (n == 1) {
		return numbers;  
	}
	else if (step != n) {
		int min = step;
		for (int i = step + 1; i < n; i++) {
			if(numbers[i] < numbers[min]) {
				min = i;                   
			}
		}
																																
		swap(numbers[min], numbers[step]);
		print(numbers,n);
		numbers = selectionSort(numbers,n,step + 1);
	}
	return numbers;
}                                                                                                                                

int main() {                                                                                                                     
    vector<int> numbers;                                                                                                         
    int n = 20;                                                                                                                  
    int maxNumber = 20;                                                                                                                                                                                                                                            
    numbers = randomNumbers(numbers,n,maxNumber);                                                                                
                                                                                                                                 
    cout << "\nInput vector: " << endl;
	print(numbers,n);
	cout << "\n";                                                                                                            
	                                                                                                                  
    numbers = selectionSort(numbers,n,0);                                                                                                  
	
	cout << "\nOutput vector: " << endl;
	print(numbers,n);
}                     
