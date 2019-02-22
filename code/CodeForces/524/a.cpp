//24, 11, 2018, 05:42:27 Rafaelcs cpp
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

    ll tot = (2LL * n + k - 1LL) / k + (5LL * n + k - 1LL) / k + (8LL * n + k - 1LL) / k;

    cout << tot << endl;

    return 0;
}