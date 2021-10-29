#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(3e5) + 10;
ll a[N];
ll suf[N];

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &a[i]);
    }

    for(int i = n ; i >= 1 ; i--){
        suf[i] = a[i] + suf[i + 1];
    }

    ll ans = suf[1];
    vector< ll > vsuf;

    for(int i = 2 ; i <= n ; i++){
        vsuf.push_back(suf[i]);
    }

    sort(vsuf.begin(), vsuf.end());
    reverse(vsuf.begin(), vsuf.end());

    for(int i = 0 ; i < k - 1 ; i++){
        ans += vsuf[i];
    }

    printf("%lld\n", ans);

    return 0;
}