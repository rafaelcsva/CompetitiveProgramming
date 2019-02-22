//28, 11, 2018, 08:54:47 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        ll k, p, n;

        cin >> k >> p >> n;

        ll mx = max(0LL, k - p);

        cout << mx * n << endl;
    }

    return 0;
}