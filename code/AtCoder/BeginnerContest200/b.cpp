#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ll n, k;

    cin >> n >> k;

    while(k){
        if(n % 200LL == 0LL){
            n /= 200LL;
        }else{
            n = n * 1000LL + 200LL;
        }

        k--;
    }

    cout << n << endl;

    return 0;
}