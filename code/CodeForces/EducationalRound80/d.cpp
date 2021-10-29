#include <bits/stdc++.h>

using namespace std;

const int D = 8;
const int N = int(3e5) + 10;

vector< int > msks[1 << D];
int n, m;
int a[N][D];
int ans[1 << D];
int wh[N];

pair< int, int > can(int x){
    memset(ans, -1, sizeof ans);

    for(int i = 0 ; i < n ; i++){
        int msk = 0;
        for(int j = 0 ; j < m ; j++){
            if(a[i][j] >= x){
                msk |= (1 << j);
            }
        }
        ans[msk] = i;
        // printf("%d is %d\n", i, msk);
        wh[i] = msk;
    }

    for(int i = 0 ; i < n ; i++){
        for(auto u: msks[wh[i]]){
            if(ans[u] != -1){
                return {i, ans[u]};
            }
        }
    }

    return {-1, -1};
}

int main(){
    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int d = 0 ; d < (1 << D) ; d++){
        for(int e = 0 ; e < (1 << D) ; e++){
            if((d | e) == (1 << m) - 1){
                msks[d].push_back(e);
            }
        }
    }

    int lo = 0, hi = int(1e9) + 1;
    pair< int, int > r = {-1, -1};
    // r = can(3);
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        auto res = can(mid);

        if(res.first != -1){
            r = res;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    printf("%d %d\n", r.first + 1, r.second + 1);

    return 0;
}