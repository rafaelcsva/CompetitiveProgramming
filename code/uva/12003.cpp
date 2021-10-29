#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int SQ = 548;

const int N = int(3e5) + 10;
vector< ll > st[SQ + 10];
ll a[N];

int query(int l, int r, ll k){
    int sum = 0;
    
    for(int i = l ; i <= r ; ){
        if (i % SQ == 0 && i + SQ - 1 <= r) {
            sum += (lower_bound(st[i / SQ].begin(), st[i / SQ].end(), k)
                        - st[i / SQ].begin());
            i += SQ;
        }
        else {
            sum += (a[i] < k);
            ++i;
        }
    }
    return sum;
}

int main(){
    int n, m;
    ll u;

    scanf("%d %d %lld", &n, &m, &u);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &a[i]);
        st[i / SQ].push_back(a[i]);
    }

    for(int i = 0 ; i < SQ + 10 ; i++){
        sort(st[i].begin(), st[i].end());
    }

    while(m--){
        int l, r;
        ll v;
        int p;

        scanf("%d %d %lld %d", &l, &r, &v, &p);
        l--, r--, p--;
        int k = query(l, r, v);
        int pos = lower_bound(st[p / SQ].begin(), st[p / SQ].end(), a[p]) - st[p / SQ].begin();

        a[p] = u * ll(k) / ll(r - l + 1);
        st[p / SQ][pos] = a[p];
        sort(st[p / SQ].begin(), st[p / SQ].end());
    }

    for(int i = 0 ; i < n ; i++){
        printf("%lld\n", a[i]);
    }

    return 0;
}
