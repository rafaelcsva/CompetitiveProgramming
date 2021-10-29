#include <bits/stdc++.h>

using namespace std;

const int SQ = 448;

typedef long long   ll;

const int N = int(2e5) + 10;
vector< int > blk[SQ];
int a[N];

int range(int idx, int val){
    int pos = blk[idx].end() - lower_bound(blk[idx].begin(), blk[idx].end(), val);

    return pos;
}

ll query(int l, int r){
    int ans = 0;
    
    for(int i = l + 1 ; i <= r ;){
        if(i % SQ == 0 && i + SQ <= r){
            ans += range(i / SQ, l);
            i += SQ;
        }else{
            ans += (a[i] >= l);
            i++;
        }
    }

    return ll(ans);
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);

        blk[i / SQ].push_back(a[i]);
    }

    for(int i = 0 ; i < SQ ; i++){
        sort(blk[i].begin(), blk[i].end());
    }

    ll ans = 0LL;

    for(int i = 1 ; i <= n ; i++){
        ans += query(i, min(a[i], n));
    }

    printf("%lld\n", ans);

    return 0;
}