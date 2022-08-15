#include <bits/stdc++.h>                                                                                                         
using namespace std;                                                                                                             

void print(int *t1, int *t2, int *t3,int n) {

    cout << "\n\tTorre 1" << "\tTorre 2" << "\tTorre 3" << endl;
    for(int j = 0; j < n; j++) {
        cout << "\t" << t1[j] << "\t" << t2[j] << "\t" << t3[j] << endl;;
        
    }

    cout << "\t—————————————————————————" << endl;
}

void towerOfHanoi(int n, int *from_rod,
                    int *to_rod, int *aux_rod) { 
    if (n == 0) return;  
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); 
    cout << "Move disk " << n << " from rod " << from_rod <<
                                " to rod " << to_rod << endl; 
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
} 
  
// Driver code
int main() 
{ 
    int n = 4; // Number of disks
	int arr[n];
    towerOfHanoi(n, arr, {0}, {0}); // A, B and C are names of rods 
    return 0; 
} 
