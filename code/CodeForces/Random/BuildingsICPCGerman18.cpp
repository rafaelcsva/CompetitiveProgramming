//17, 10, 2018, 17:07:39 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 510;
int mark[N];
const ll mod = 1e9 + 7;

ll fast_pow(ll x, ll n){
    if(n == 1LL)
        return x;

    if(n == 0LL)
        return 1LL;

    ll a = fast_pow(x, n / 2LL);
    a *= a;
    a %= mod;

    if(n & 1LL){
        a *= x;
        a %= mod;
    }

    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(mark, -1, sizeof mark);

    ll n, m, c;

    cin >> n >> m >> c;

    ll val = fast_pow(c, n * n);
    ll sum = 0LL;

    for(int turns = 0 ; turns < m ; turns++){
        ll comp = 0;

        for(int j = 0 ; j < m ; j++){
            if(mark[j] != turns){
                comp++;

                int x = j;

                while(mark[x] != turns){
                    mark[x] = turns;

                    x += turns;
                    x %= m;
                }
            }
        }

        sum += fast_pow(val, comp);
        sum %= mod;
    }

    sum *= fast_pow(m, mod - 2LL);
    sum %= mod;

    cout << sum << endl;

    return 0;
}