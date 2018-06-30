//23, 06, 2018, 09:22:12 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 90000000;

int sum_digits(int j){
    int d = 0;

    while(j){
        d += j % 10;
        j /= 10;
    }

    return d;
}

bool can(int j){
    int sdj = sum_digits(j);

    for(int i = j + 1 ; i < j + 1000000 ; i++){
        int sdi = sum_digits(i);

        if(j * sdi > i * sdj ){
            return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k;

    cin >> k;

    for(int j = 1 ; j < 100000000 ; j++){
        if(can(j)){
            cout << j << endl;
        }
    }
    return 0;
}