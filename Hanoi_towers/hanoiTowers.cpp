#include <bits/stdc++.h>                                                                                                         
using namespace std;                                                                                                             

void print(int t1[], int t2[], int t3[]) {
    //for(int i = 0; i < n; i++) {

//    }
}

void hanoi_towers(int t1[], int t2[], int t3[], int n) {
    //for (int i = 0; i < n; i++) {
    
    //}

    if(n==1)
    { 
        t2[n] = t1[n];
        t1[n] = begin(t1)
    }

    else
    {
    
      hanoi (t1, t2, t3, n - 1);
   
      hanoi (t2, t3, t1, n - 1);
    }
    
}


int main() {
    int n;
    int tower_1[n],tower_2[n],tower_3[n];

    cout << "n: "; cin >> n;
    hanoi_towers(tower_1, tower_2, tower_3, n);
}