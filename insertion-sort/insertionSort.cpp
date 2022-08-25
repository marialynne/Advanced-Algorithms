#include <bits/stdc++.h>                                                                                                         
using namespace std;                                                                                                             

void print(vector<int> numbers, int n) {                                                                                         
    cout << "\t";                                                                                                                 
	for(int i = 0; i < n; i++)                                                                                                   
		cout << numbers[i] << " ";                                                                                               
    cout << endl;                                                                                                                
}                                                                                                                                

vector<int> insertionSort(vector<int> numbers, int n, int step) {                                                                          

    if (n == 1) {
		return numbers;  
	}    
	else if (step != n) {
		int pivot = numbers[step];  
        int i = step-1;  

        //cout << "Pivot: " << pivot << "\tIndex: " << i << endl;

        while(i>=0 && pivot <= numbers[i])  
        {  
            numbers[i+1] = numbers[i];   
            i--;  
        }  

        numbers[i+1] = pivot;  
        //cout <<"Pivot: " << pivot << "\t";
        print(numbers,n);
        numbers = insertionSort(numbers,n,step + 1);																												
	}
	return numbers;
}                                                                                                                                

int main() {                                                                                                                     
    vector<int> numbers = {13,10,15,7,8,2,6,9};                                                                                                         
    int n = numbers.size();                                                                                                                  
                                                                                                                                                                                                                                                         
    cout << "\nInput vector: " << endl;
	print(numbers,n);
	cout << "\n";                                                                                                            

    numbers = insertionSort(numbers,n,0);                                                                                                                                                                                         
	
	cout << "\nOutput vector: " << endl;
	print(numbers,n);
}  