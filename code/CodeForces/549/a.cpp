//30, 03, 2019, 14:32:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector< ll > p1, p2;
ll nn;

ll solve(ll tmp){
    return nn / __gcd(tmp, nn);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    ll a, b;

    cin >> n >> k;
    cin >> a >> b;

    if(n == k && n == 1){
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    if(k % 2LL != 0LL || a != k / 2LL){
        p1.push_back(a + 1LL);
    }

    p1.push_back(k - a + 1LL);

    if(k % 2 != 0LL || b != k / 2LL){
        p2.push_back(b + 1LL);
    }

    p2.push_back(k - b + 1LL);

    nn = n * k;

    ll best_mn = ll(1e18), best_max = -1LL;

    for(int i = 0 ; i < p1.size() ; i++){
        // cout << "p[i] = " << p1[i] << endl;
        for(int j = 0 ; j < p2.size() ; j++){
            // cout << "p[j] = " << p2[j] << endl;
            ll diff = p2[j] - p1[i];

            for(ll p = 0 ; p <= n + 10LL ; p++){
                ll tmp = diff + p * k;

                if(tmp < 0LL){
                    continue;
                }
                // cout << tmp << endl;

                best_mn = min(best_mn, solve(tmp));
                best_max = max(best_max, solve(tmp));
            }        
        }
    }

    cout << best_mn << " " << best_max << endl;

    return 0;
}