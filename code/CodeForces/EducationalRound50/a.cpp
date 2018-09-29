//07, 09, 2018, 11:40:22 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k;

    cin >> n >> k;

    n = 2 * n + 1LL;

    n = n / 2LL;

    ll r = k / n;
    
    if(k % n != 0LL){
        r++;
    }

    cout << r << endl;
    
    return 0;
}