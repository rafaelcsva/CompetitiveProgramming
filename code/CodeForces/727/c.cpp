#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 100;
ll a[N];

ll get(ll a, ll b, ll x){
    if((b - a) % x == 0LL){
        return (b - a) / x -1LL;
    }

    return (b - a) / x;
}

int main(){
    int n;
    ll k, x;

    scanf("%d %lld %lld", &n, &k, &x);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &a[i]);
    }

    sort(a, a + n);
    vector< ll > costs;
    int groups = 1;

    for(int i = 1 ; i < n ; i++){
        if(a[i] - a[i - 1] > x){
            groups++;
            costs.push_back(get(a[i - 1], a[i], x));
        }
    }

    // printf("%d\n", groups);

    sort(costs.begin(), costs.end());

    for(auto u: costs){
        if(u > k){
            break;
        }
        k -= u;
        groups--;
    }

    printf("%d\n", groups);

    return 0;
}