#include <bits/stdc++.h>

using namespace std;

const int N = 6010;
int mark[N];
int x[N];

int main (){
    int n;

    cin >> n;

    int paid = 0;

    for(int i = 0 ; i < n ; i++){
        cin >> x[i];
    }

    sort(x, x + n);

    for(int i = 0 ; i < n ; i++){
        while(mark[x[i]]){
            x[i]++;
            paid++;
        }

        mark[x[i]] = 1;
    }

    cout << paid << '\n';

    return 0;
}