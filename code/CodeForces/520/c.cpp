//14, 11, 2018, 14:32:43 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll pref0[N], pref1[N];
int qtd[N];
const ll mod = 1e9 + 7;

ll fast_pow(ll n, int x){
    if(x == 0){
        return 1LL;
    }

    if(x == 1){
        return n;
    }

    ll a = fast_pow(n, x / 2);
    a *= a;
    a %= mod;

    if(x & 1LL){
        a *= n;
        a %= mod;
    }

    return a;
}

ll MOD(ll x){
    return ((x % mod) + mod) % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    pref1[0] = 1LL;

    for(int i = 1 ; i < N ; i++){
        pref1[i] = 2LL * pref1[i - 1];
        pref1[i] %= mod;

        pref0[i] = pref1[i] - 1LL;
    }

    for(int i = 1 ; i < N ; i++){
        pref1[i] += pref1[i - 1];
        pref1[i] %= mod;
    }

    int n, q;

    cin >> n >> q;

    string s;

    cin >> s;

    for(int i = 1 ; i <= n ; i++){
        if(s[i - 1] == '1'){
            qtd[i] = 1;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        qtd[i] += qtd[i - 1];
    }

    while(q--){
        int l, r;

        cin >> l >> r;

        int one_guys = qtd[r] - qtd[l - 1];

        if(one_guys == 0){
            printf("0\n");
        }else{
            int qtd2 = (r - l + 1) - one_guys;
            ll r = pref1[one_guys - 1];
            // printf("%lld\n", pref1[one_guys - 1]);
            ll a1 = pref0[one_guys];
            // printf("%lld\n", a1);
            r += MOD(a1 * MOD(fast_pow(2LL, qtd2) - 1LL));
            r = MOD(r);

            printf("%lld\n", r); 
        }
    }
    
    return 0;
}