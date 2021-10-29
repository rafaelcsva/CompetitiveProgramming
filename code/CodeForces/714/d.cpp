#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long   ll;
 
const int N = int(2e5) + 10;
const int K = 20;
int st[N][K + 1];
int a[N];
int llog[N];
int father[N];
 
void build(int n){
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];
 
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = __gcd(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}
 
int query(int L, int R){
    int j = llog[R - L + 1];
    int res = __gcd(st[L][j], st[R - (1 << j) + 1][j]);
 
    return res;
}
 
int find(int x){
    if(x == father[x]){
        return x;
    }
 
    return father[x] = find(father[x]);
}
 
void merge(int a, int b){
    int x = find(a);
    int y = find(b);
 
    if(x != y){
        if(x < y){
            father[y] = x;
        }else{
            father[x] = y;
        }
    }
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
        ll p;
 
        scanf("%d %lld", &n, &p);
 
        vector< pair< int, int > > v;
 
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
            father[i] = i;
            v.push_back({a[i], i});
        }
 
        build(n);
 
        sort(v.begin(), v.end());
 
        ll ans = 0LL;
    
        for(auto u: v){
            if(u.first >= p){
                break;
            }
 
            if(find(u.second) == u.second){
                if(u.second > 0){
                    int x = u.second - 1;
                    int g = __gcd(u.first, a[x]);
 
                    while(g == u.first && x >= 0){
                        merge(u.second, x);
                        x--;
                        ans += ll(u.first);
 
                        if(x >= 0){
                            g = __gcd(g, a[x]);
                        }
                    }
                }
 
                if(u.second < n - 1){
                    int x = u.second + 1;
                    int g = __gcd(u.first, a[x]);
 
                    while(g == u.first && x < n){
                        merge(u.second, x);
                        x++;
                        ans += ll(u.first);
 
                        if(x < n){
                            g = __gcd(g, a[x]);
                        }
                    }
                }
            }
        }
 
        for(int i = 1 ;i < n ; i++){
            if(find(i) != find(0)){
                ans += p;
                merge(i, 0);
            }
        }
 
        assert(ans > 0LL);
    
        printf("%lld\n", ans);
    }
 
    return 0;
}