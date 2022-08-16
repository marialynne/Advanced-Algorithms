#include <bits/stdc++.h>
using namespace std;
/*
<Method 1>

Complexity: O(N log(N))
Why?
Well, let's see the next scheme:

Divide recursively the array:
     [8,5,2,9,5,6,3]                 O(N)   =  O(N)
    [8,5,2,9] [5,6,3]                O(N/2) =  O(N)
  [8,5] [2,9] [5,6] [3]              O(N/4) =  O(N)
[8][5] [2][9] [5][6] [3]             O(N/8) =  O(N)
                                     O(N log(N))    log(N) = Always devided in half
———————————————————————————————
Merge the array by pointers:        O(Constant)
[5,8] [2,9]     [5,6] [3]            
 ^     ^         ^     ^
 [2,..]        [3,...]
———————————————————————————————
[5,8] [2,9]     [5,6] [3]           O(Constant)
 ^       ^         ^   
[2,5,..]         [3,5,6]
———————————————————————————————
[5,8] [2,9]     [3,5,6]             O(Constant)
   ^     ^           
[2,5,8,9]        [3,5,6]
———————————————————————————————
* The index of each array is
will move, but first iterating
the second array comparing with
the first pointer.

[2,5,8,9]        [3,5,6]    
 ^ -->            ^ -->
    [2,3,5,5,6,8,8]

<Method 2>
But wait, can we do it better? Yes...
Time Complexity: O(N log(N))
Space Complexity: O(N)
            0 1 2 3 4 5 6
M(main) -> [8,5,2,9,5,6,3] 
A(aux)  -> [8,5,2,9,5,6,3] 

A -> [8,5,2,9]  ->   M -> [8,5]
M -> [8,5,2,9]  ->   A -> [8,5]

*/
void print(vector<double> array) {
    for(int i=0; i <= array.size()-1; i++)
        cout << array[i] << " ";
    //cout << endl;
}

// O(N log(N)) time | O(N) space;
vector<double> mergeSort(vector<double> array, bool process) {

    if(array.size() <= 1) return array; // Return array with one element

    /* 
        Middle of array
        Right part of the array
        Left part of the array
    */
    int mid = array.size() / 2; 
    vector<double> left; 
    vector<double> right; 
    copy(array.begin(), array.begin()+mid, back_inserter(left)); 
    copy(array.begin()+mid, array.end(), back_inserter(right));

    if(process) {
        cout << "______________" << endl;
        cout << "|   DEVIDE   |\n"; 
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
        print(left); cout << "\t"; print(right); cout << endl;
    }
    
    // Devide
    left = mergeSort(left,process); // Merge each half left
    right = mergeSort(right,process); // Merge each hlaf right

    vector<double> ans; // Resulting array
    int i = 0;
    int j = 0;

    // Sort
    while(i < left.size() && j < right.size()) {
        if(left[i] < right[j]) {
            ans.push_back(left[i]);
            i++;
        }
        else {
            ans.push_back(right[j]);
            j++;
        }
    }

    if(i == left.size()) {
        i = j;
        left = right;
    }

    while(i < left.size()) {
        ans.push_back(left[i]);
        i++;
    }

    if(process) {
        cout << "______________" << endl;
        cout << "|    SORT    |\n"; 
        cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
        print(ans); cout << endl;
    }
    

    return ans;
}

vector<double> input() {
    int n = 0, in;
    vector<double> aux;
    cout << "Número de elementos en la lista: "; cin >> n;
    for(int i = 0; i < n; i++) {
        cout << i+1 << ": "; 
        cin >> in;
        aux.push_back(in);
    }

    return aux;

}

int main(){
    vector<double> array; //{8,5,2,9,5,6,10,23,32,20,12,13,4,50,1,29,66,77,88};
    bool process;
  /*   ifstream myFile;


    myFile.open("test.txt");
    if (!myFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }   
 */

    array = input();
    cout << "\n¿Ver proceso? \n<1> Sí\n<0> No\n"; cin >> process;

    cout << "\nArray input: ";
    print(array);
    cout << endl;

    array = mergeSort(array,process);

    cout << "\n\nArray sorted: ";
    print(array);
    cout << "\n\n";

    return 0;
}