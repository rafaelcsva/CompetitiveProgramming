//15, 07, 2018, 17:46:12 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> n >> m;

    ll current = 0LL;
    ll greater = ((1LL + n - 1LL) * (n - 1LL)) / 2LL;
    ll small;
    ll keep = n;
    
    if(n & 1LL){
        n = n / 2 + 1;

        small = ((1LL + n - 1LL) * (n - 1LL));
    }else{
        n = n / 2;
        small = ((1LL + n - 1LL) * (n - 1LL)) / 2LL;
        n++;
        small += ((1LL + n - 1LL) * (n - 1LL)) / 2LL;
    }

    ll best = -2e18;
    
    for(int i = 0 ;i < m ; i++){
        ll x, d;

        cin >> x >> d;

        current = current + keep * x + max(small * d, greater * d);
    }

    cout << fixed << setprecision(10) << ld(current) / ld(keep) << endl;
    
    return 0;
}