#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 4;
int vis[1 << 17];
int vis1[17];
int vi[4] = {0, 0, -1, 1};
int vj[4] = {1, -1, 0, 0};
 
int dfs(int mask, int j){
    vis[j] = 1;
    int cnt = 1;
    int l = j / N;
    int c = j % N;
 
    for(int d = 0 ; d < 4 ; d++){
        int ll = l + vi[d];
        int cc = c + vj[d];
        int mx = ll * N + cc;
 
        if(ll >= 0 && ll < N && cc >= 0 && cc < N && (mask & (1 << mx)) && !vis[mx]){
            cnt += dfs(mask, mx);
        }
    }
 
    return cnt;
}
 
int dfs1(int mask, int j){
    if(vis1[j]){
        return vis1[j];
    }
 
    vis1[j] = 1;
    int cnt = 1;
    int l = j / N;
    int c = j % N;
 
    for(int d = 0 ; d < 4 ; d++){
        int ll = l + vi[d];
        int cc = c + vj[d];
        int mx = ll * N + cc;
 
        if(ll < 0 || ll >= N || cc < 0 || cc >= N){
            return vis1[j] = 2;
        }
 
        if(!(mask & (1 << mx))){
            if(dfs1(mask, mx) == 2){
                return vis1[j] = 2;
            }
        }
    }
 
    return vis1[j] = -1;
}
 
void print_mask(int mask){
    // printf("%d %d\n", __builtin_popcount(mask));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            int e = i * N + j;
 
            if((mask & (1 << e))){
                printf("1 ");
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("-----------\n");
}
 
int main(){
    int msk = 0;
    for(int i = 0 ; i < 16 ; i++){
        int x;
 
        scanf("%d", &x);
 
        msk |= x * (1 << i);
    }
 
    int ans = 0;
 
    for(int mask = 0; mask < (1 << 16) ; mask++){
        if((mask & msk) == msk){
            memset(vis, 0, sizeof vis);
            int root = -1;
    
            for(int j = 0 ; j < 16 ; j++){
                if(mask & (1 << j)){
                    root = j;
                    break;
                }
            }
 
            bool chkmsk = true;
 
            for(int i = 0 ; i < N ; i++){
                for(int j = 0 ; j < N ; j++){
                    int mx = i * N + j;
 
                    if(!(mask & (1 << mx))){
                        memset(vis1, 0, sizeof vis1);
                        chkmsk &= (dfs1(mask, mx) != -1);
                    }
                }
            }

            if(root != -1 && chkmsk){
                int ver = (dfs(mask, root) == __builtin_popcount(mask));
                ans += ver;
            }
        }
    }
    printf("%d\n", ans);
 
    return 0;
}