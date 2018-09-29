//28, 07, 2018, 10:12:44 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll bit[N];
int a[N];
int p[N];

int LSOne(int x){
    return x & (-x);
}

ll query(int b){
    ll s = 0LL;

    while(b > 0){
        s += bit[b];
        b -= LSOne(b);
    }

    return s;
}

ll rsq(int l, int r){
    return query(r) - query(l - 1);
}

void update(int b, int val){
    while(b < N){
        bit[b] += val;
        b += LSOne(b);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);
        }

        for(int i = 1 ; i <= n ; i++){
            int x;

            scanf("%d", &x);

            p[x] = i;
        }

        ll sum = 0LL;

        for(int i = 1 ; i <= n ; i++){
            sum += rsq(p[a[i]] + 1, n);
            update(p[a[i]], 1);
        }

        printf("%lld\n", sum);
        memset(bit, 0, sizeof bit);
    }

    return 0;
}