//05, 03, 2019, 11:12:14 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const double EPS = 1E-9;
const ll mod = 998244353LL;
const int N = 500;
int gauss (vector < bitset<N> > a, int n, int m) {
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }

    int rank = n;

    for(int i = 0 ; i < n ; i++){
        bool has_one = false;

        for(int j = 0 ; j < m ; j++){
            if(a[i][j]){
                has_one = true;
                break;
            }
        }

        if(!has_one){
            rank--;
        }
    }

    return rank;    
}

vector< bitset< N > > a;

ll fast_pow(ll base, int n){
    ll carry = base;
    ll res = 1LL;

    while(n){
        if(n & 1){
            res = (res * carry) % mod;
        }

        n /= 2;
        carry = (carry * carry) % mod;
    }
    
    return res;
}

ll MOD(ll x){
    return ((x % mod) + mod) % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    // cout << mod * mod << endl;
    cin >> n >> m;

    a.resize(n);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int x;
            cin >> x;
            a[i][j] = x; 
        }
    }

    int rank = gauss(a, n, m);
    // cout << "rank = " << rank << endl;
    // cout << "voltei!" << endl;
    ll nn = fast_pow(2LL, n + m - 1);
    ll nr = fast_pow(2LL, n + m - rank - 1);   
    ll mm = fast_pow(2LL, m - 1);

    cout << MOD(nn - nr) << endl; 

    return 0;
}