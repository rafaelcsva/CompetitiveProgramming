//18, 09, 2018, 17:45:31 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;
ll x, y, d;

// store x, y, and d as global variables
void extendedEuclid(ll a, ll b) {
    if (b == 0) { x = 1; y = 0; d = a; return; }
    // base case
    extendedEuclid(b, a % b);
    // similar as the original gcd
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

const int N = int(1e6 + 10);
ll inverso[N];

ll MOD(ll x){
    return (x % mod + mod) % mod;
}

const int M = 1010;
ll e[M][M];
int a[M][M];

typedef pair< ll, ll >  pll;
typedef pair< int, pll > plpii;
vector< plpii > mat;

ll ris, cis, risq, cisq, es, guys;
ll c1, c2, c3, c4, c5, c6;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(ll i = 1 ; i < N ; i++){
        extendedEuclid(i, mod);
        inverso[i] = MOD(x);
    }    

    int n, m;

    scanf("%d %d", &n, &m);
    
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= m ; j++){
            scanf("%d", &a[i][j]);
            mat.push_back({a[i][j], {i, j}});
        }
    }

    sort(mat.begin(), mat.end());

    int r, c;

    scanf("%d %d", &r, &c);
    
    int last = -1;
    
    for(int i = 0 ; i < mat.size() ; i++){
        int val = mat[i].first;
        
        if(val != last){
            ris += c1;
            ris = MOD(ris);
            cis += c2;
            cis = MOD(cis);
            risq += c3;
            risq = MOD(risq);
            cisq += c4;
            cisq = MOD(cisq);
            es += c5;
            es = MOD(es);
            guys += c6;
            c1 = c2 = c3 = c4 = c5 = c6 = 0LL;
            last = val;
        }
        ll calc = 0LL;

        if(guys){
            calc = (mat[i].second.second * mat[i].second.second + mat[i].second.first * mat[i].second.first);
            calc += MOD(MOD(-2LL * mat[i].second.first * ris) * inverso[guys]);
            calc = MOD(calc);
            calc += MOD(MOD(-2LL * mat[i].second.second * cis) * inverso[guys]);
            calc = MOD(calc);
            calc += MOD(risq * inverso[guys]);
            calc = MOD(calc);
            calc += MOD(cisq * inverso[guys]);
            calc = MOD(calc);
            calc += MOD(es * inverso[guys]);
            calc = MOD(calc);
        }

        e[mat[i].second.first][mat[i].second.second] = calc;
        c1 += mat[i].second.first;
        c1 = MOD(c1);
        c2 += mat[i].second.second;
        c2 = MOD(c2);
        c3 += mat[i].second.first * mat[i].second.first;
        c3 = MOD(c3);
        c4 += mat[i].second.second * mat[i].second.second;
        c4 = MOD(c4);
        c5 += calc;
        c5 = MOD(c5);
        c6++;
    }

    printf("%lld\n", e[r][c]);

    return 0;
}