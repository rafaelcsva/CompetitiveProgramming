#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long   ll;
 
const ll inf = ll(1e11);
 
const int N = int(3e5) + 10;
ll mn[3];
ll sum[3];
ll a[3][N];

int main(){
    int n[3];
    scanf("%d %d %d", &n[0], &n[1], &n[2]);
 
    vector< ll > v;

    ll ret = ll(1e18);
 
    for(int j = 0 ; j < 3 ; j++){
        mn[j] = inf;
        for(int i = 0 ; i < n[j] ; i++){
            scanf("%lld", &a[j][i]);
            sum[j] += a[j][i];
            mn[j] = min(mn[j], a[j][i]);
        }
        ret = min(ret, sum[j]);
    }
    
    v = {mn[0], mn[1], mn[2]};
    sort(v.begin(), v.end());
    
    ret = min(ret, v[0] + v[1]);

    printf("%lld\n", sum[0] + sum[1] + sum[2] - 2LL * ret);
 
    return 0;
}