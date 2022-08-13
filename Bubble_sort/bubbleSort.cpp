#include<bits/stdc++.h>
using namespace std;


void print(int arr[], int n) {
	cout << "\t";
	for (int i = 0; i < n; i++) {                                                          
          cout << arr[i] << " ";                                                             
	} 
	cout << endl;
}

void bubbleSort(int arr[], int n, int m)
{
    if (n == 1) return;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
		    print(arr, m);
        }
    }

	bubbleSort(arr, n - 1, m);
}

int main() {

	int arr[] = {8,6,7,4,5,3,2};
	int n = *(&arr + 1) - arr;
    
	cout << "\nInput array: " << endl;
    print(arr,n);
	cout << "\n";

    bubbleSort(arr,n,n); // Sort elements in ascending order
	
    cout << "\nOutput array: "<< endl;
    print(arr,n);
}
