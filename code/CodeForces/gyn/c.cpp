//06, 12, 2018, 14:52:52 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll pref[N];
ll a[N];
const int lim = 20;
int n;

ll solve(int i, int j){
    // cout << i << 
    if(i >= j){
        return 0LL;
    }

    ll best = 1e18;

    int mid = (i + j) / 2;

    best = min(best, solve(i, mid) + solve(mid + 1, j) + pref[j] - pref[i - 1]);

    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 1 ; i <= n ; i++){
            cin >> a[i];
        }

        sort(a + 1, a + n + 1);

        for(int i = 1 ; i <= n ; i++){
            pref[i] = a[i] + pref[i - 1];
        }
        
        ll best = 1e18;
        int mn = min(lim, n);
        ll carry = 0LL;
        // cout << "here" << endl;

        for(int ki = 0 ; ki <= mn ; ki++){
            // cout << "tentando para " << 1 + ki << " " << n << endl;
            best = min(best, solve(1 + ki, n) + carry);

            if(!ki){
                carry = pref[n];
            }else{
                carry = ki * a[i] + pref[ki - 1];
            }
        }

        cout << best << endl;
    }

    return 0;
}