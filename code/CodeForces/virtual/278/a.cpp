#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

bool thereIsNo8(ll n){
    while(n){
        if(n % 10LL == 8LL){
            return false;
        }

        n /= 10LL;
    }

    return true;
}

int main (){
    ll n;

    cin >> n;

    ll b = 1LL;
    n++;

    while(thereIsNo8(abs(n))){
        b++;
        n++;
    }

    cout << b << '\n';
    
    return 0;
}