//01, 07, 2018, 08:33:55 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const ll INF = 1000000;
const int N = 200010;
ll a[N];
ll pref[N];
ll suf[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    ll mn = INF;
    ll sum = 0LL;
    
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];

        a[i] -= i;
        
        mn = min(mn, a[i]);

        sum += abs(a[i]);
    }
    
    sort(a + 1, a + 1 + n, greater<ll>());

    ll tmp = 0LL;
    for(int i = n ; i >= 1 ; i--){
        suf[i] = a[i] + suf[i + 1];
    }
    
    ll best = sum;
    
    for(int i = 1 ; i <= n ; i++){
        if(a[i] > 0LL){
            ll rg = n - i;
            ll lf = i;

            best = min(best, abs(suf[i + 1] - a[i] * rg) + abs((tmp + a[i]) - a[i] * lf));
        }else{
            ll rg = n - i + 1;
            ll lf = i - 1;

            best = min(best, abs(suf[i] - a[i] * rg) + abs(tmp - a[i] * lf));
        }

        tmp += a[i];
    }

    cout << best << endl;
    
    return 0;
}