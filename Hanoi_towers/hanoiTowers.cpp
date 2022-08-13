#include <bits/stdc++.h>                                                                                                         
using namespace std;                                                                                                             

void print(int *t1, int *t2, int *t3,int n) {

    cout << "\n\tTorre 1" << "\tTorre 2" << "\tTorre 3" << endl;
    for(int j = 0; j < n; j++) {
        cout << "\t" << t1[j] << "\t" << t2[j] << "\t" << t3[j] << endl;;
        
    }

    cout << "\t—————————————————————————" << endl;
}

void hanoi_towers(int t1[], int t2[], int t3[], int n, int &c) {

    if(n==1)
    { 
        t2[n] = t1[n];
        print(t1,t2,t3,n);
    }

    else
    {
        c++;
        hanoi_towers(t1, t2, t3, n - 1,c);
        t1[n] = t3[n];
        print(t1,t2,t3,n);
        c++;
        hanoi_towers(t2, t3, t1, n - 1,c);
    }
    
}


int main() {
    int n,c=1;
    cout << "n: "; cin >> n;
    int tower_1[n],tower_2[n]={0},tower_3[n]={0};


    

    for(int i = 0; i < n; i++) {
        tower_1[i] = i+1;
        //cout << tower_1[i] << endl;
    }

    //print(tower_1,tower_2,tower_3,n);

    
    hanoi_towers(tower_1, tower_2, tower_3, n, c);

    cout << c << endl;
}