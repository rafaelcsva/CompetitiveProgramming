#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;
const int N = int(5e5) + 10;
pair< int, int > bit[N];
int a[N];

pii best(pii a, pii b){
    if(a.first > b.first){
        return a;
    }else if(b.first > a.first){
        return b;
    }else if(a.second < b.second){
        return a;
    }else{
        return b;
    }
}

int LSOne(int x){
    return x & (-x);
}

void update(int pos, pii x){
    while(pos < N){
        bit[pos] = best(x, bit[pos]);
        pos += LSOne(pos);
    }
}

pii query(int pos){
    pii res = {0, 0};
    
    while(pos > 0){
        res = best(res, bit[pos]);
        pos -= LSOne(pos);
    }

    return res;
}

const int K = 20;
int st[N][K];
int llog[N + 1];

void build(int n){
    for(int i = 0 ; i < n ; i++){
        st[i][0] = a[i];
    }

    for(int j = 1 ; j <= K ; j++){
        for(int i = 0 ; i + (1 << j) <= n ; i++){
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int queryM(int L, int R){
    if(L > R){
        return -1;
    }
    int j = llog[R - L + 1];

    int res = max(st[L][j], st[R - (1 << j) + 1][j]);

    return res; 
}

int main(){
    llog[1] = 0;
    for(int i = 2 ; i < N ; i++){
        llog[i] = llog[i / 2] + 1;
    }

    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);

            bit[i] = {0, 0};
        }

        build(n + 1);

        int ans = 1;
        update(1, {1, 1});

        for(int i = 2 ; i <= n ; i++){
            pii u = query(a[i]);
            int ge = queryM(u.second + 1, i - 1);
            int gl = queryM(i + 1, n);

            if(ge >= a[i]){
                // printf("1. %d %d %d %d \n", i, ge, u.first + 2, u.second);
                ans = max(ans, u.first + 2 + (gl >= a[i]));
                update(a[i], {u.first + 2, i});
            }else{
                // printf("2. %d %d %d %d\n", i, ge, u.first + 1, u.second);
                ans = max(ans, u.first + 1 + (gl >= a[i]));
                update(a[i], {u.first + 1, i});
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}