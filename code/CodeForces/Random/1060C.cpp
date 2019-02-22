//04, 10, 2018, 12:52:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 10000;
ll lena[N], lenb[N];
ll a[N], b[N];
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    ll x;

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        lena[i + 1] = INF;
        cin >> a[i];
    }

    for(int i = 0 ; i < m ; i++){
        lenb[i + 1] = INF;
        cin >> b[i];
    }

    cin >> x;

    for(int i = 0 ; i < n ; i++){
        ll s = 0LL;

        for(int j = i ; j < n ; j++){
            s += a[j];
            lena[j - i + 1] = min(s, lena[j - i + 1]);
        }
    }

    for(int i = 0 ; i < m ; i++){
        ll s = 0LL;

        for(int j = i ; j < m ; j++){
            s += b[j];
            lenb[j - i + 1] = min(s, lenb[j - i + 1]);
        }
    }

    int best = 0LL;
    
    // cout << lena[1] << " " << lenb[1] << endl;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(lena[i] * lenb[j] <= x){
                best = max(best, i * j);
            }
        }
    }

    cout << best << endl;

    return 0;
}