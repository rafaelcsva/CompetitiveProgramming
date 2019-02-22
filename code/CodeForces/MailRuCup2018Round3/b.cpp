//25, 11, 2018, 14:46:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
ll cnt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;

    cin >> n >> m;

    for(ll i = 1 ; i <= min(m, n) ; i++){
        cnt[(i * i) % m] += (n - i) / m + 1LL;
    }

    ll tot = 0LL;

    for(ll i = 0LL ; i < m ; i++){
        for(ll j = 0LL ; j < m ; j++){
            if((i + j) % m == 0LL){
                tot += cnt[i] * cnt[j];
            }
        }
    }

    cout << tot << endl;

    return 0;
}