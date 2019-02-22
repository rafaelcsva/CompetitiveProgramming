//05, 10, 2018, 08:17:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5);
ll a[N], b[N];
int n;

bool can(ll mid, ll ballons){
    for(int i = 0 ; i < n ; i++){
        ll candy = mid / b[i];

        if(candy + ballons < a[i]){
            return false;
        } 

        if(a[i] > candy){
            ballons -= (a[i] - candy);
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll m;

    scanf("%d %lld", &n, &m);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &a[i]);
    }

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &b[i]);
    }

    ll lo = 0LL, hi = 1e18;
    ll r = -1LL;

    while(lo <= hi){
        ll mid = (lo + hi) / 2LL;

        if(can(mid, m)){
            r = mid;
            hi = mid - 1LL;
        }else{
            lo = mid + 1LL;
        }
    }

    printf("%lld\n", r);

    return 0;
}