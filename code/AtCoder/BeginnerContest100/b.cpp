//16, 06, 2018, 09:05:20 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int pot(int b, int d){
    int p = 1LL;

    while(d--){
        p *= b;
    }

    return p;
}

int main(){
    int d, n;

    cin >> d >> n;
    
    int ini = pot(100, d);
    int tmp = 0;
 
    if(n == 100){
        cout << ini * n + ini << endl;
    }else{
        cout << ini * n << endl;
    }
    
    return 0;
}