#include <bits/stdc++.h>
 
using namespace std;
 
const int N = int(1e6) + 10;
int bit[N];
int k[N];
 
int LSOne(int x){
    return x & (-x);
}
 
int query(int x){
    int sum = 0;
 
    while(x > 0){
        sum += bit[x];
        x -= LSOne(x);
    }
 
    return sum;
}
 
void update(int x, int add){
    while(x < N){
        bit[x] += add;
        x += LSOne(x);
    }
}
 
int rsq(int l, int r){
    return query(r) - query(l - 1);
}

int bit_search(int v){
    int sum = 0;
    int pos = 0;

    for(int i = 20 ; i >= 0 ; i--){
        if(pos + (1 << i) < N && sum + bit[pos + (1 << i)] < v){
            sum += bit[pos + (1 << i)];
            pos += (1 << i);
        }
    }

    return pos + 1;
}

int main(){
    int n, q;
 
    scanf("%d %d", &n, &q);
 
    for(int i = 0 ; i < n ; i++){
        int ai;
 
        scanf("%d", &ai);
 
        update(ai, 1);
    }
 
    int add = n;
    int rmv = 0;
 
    for(int i = 0 ; i < q ; i++){
        scanf("%d", &k[i]);
 
        if(k[i] < 0){
            rmv++;
        }else{
            add++;
        }
    }
 
    if(rmv >= add){
        printf("0\n");
        return 0;
    }
 
    for(int i = 0 ; i < q ; i++){
        int ki = k[i];
 
        if(ki < 0){
            int lo = 1, hi = n;
            int r = -1;
            ki = abs(ki);
 
            // printf("rmv %d %d %d\n", r, query(r), ki);
            update(bit_search(ki), -1);
        }else{
            update(ki, 1);
        }
    }
 
    for(int i = 1 ; i <= n ; i++){
        if(rsq(i, i)){
            printf("%d\n", i);
            return 0;
        }
    }
 
    printf("0\n");
 
    return 0;
}
