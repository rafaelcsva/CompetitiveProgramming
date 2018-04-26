//25, 04, 2018, 15:34:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
ll n, k, m, d;

bool can(ll mid){
    for(ll i = 1LL ; i <= d ; i++){
       
        ll coef = (mid + i - 1LL) / i;
        
        ll num = n / coef;
        
        if(coef <= m && (num + k - 1LL) / k <= d && (coef * (i - 1LL) * k + coef <= n)){
            cout << mid << ' ' << coef * i << endl;
            return coef * i;
        }
    }

    return -1LL;
}

int main(){
    

    cin >> n >> k >> m >> d;

    ll start = 1LL, end = n;
    ll r = 0LL;
    
    while(start <= end){
        ll mid = (start + end) / 2LL;
        ll t = can(mid);

        if(t != -1){
            start = mid + 1LL;
            r = t;
        }else{
            end = mid - 1LL;
        }
    }

    if(d == 1LL){
        r = m;
    }

    cout << r << endl;

    return 0;
}