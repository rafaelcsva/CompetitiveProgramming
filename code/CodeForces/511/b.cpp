//21, 09, 2018, 11:40:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const ll mx = 1e18;

typedef pair<ll, ll> pll;

const int N = int(1e5 + 100);
pll p[N];
int n;

bool can(ll b){
    for(int i = 0 ; i < n ; i++){
        ll y = b - p[i].first;

        if(y < p[i].second){
            return false;
        } 
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld %lld", &p[i].first, &p[i].second);
    }

    ll lo = 1LL, hi = mx;
    ll r = -1LL;

    while(lo <= hi){
        ll mid = (lo + hi) / 2LL;

        if(can(mid)){
            r = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }

    printf("%lld\n", r);

    return 0;
}