#include <bits/stdc++.h>
using namespace std;

const int N = 451;
char st[N];
int n, k;
int dp[2][N][N];
int test = 1;
const int inf = int(1e7) + 10;

bool can(int mid){
    //printf("tentando com %d\n", mid);
    int gt = 0;
    int r = inf;
    
    for(int i = 0 ; i < n ; i++){
        if(st[i] == '1'){
            gt++;
        }else{
            gt = 0;
        }
        
        int cur = i & 1;
        int other = !cur;
        
        for(int rest = 0 ; rest <= mid ; rest++) 
            for(int pref = 0 ; pref <= i ; pref++) dp[cur][rest][pref] = inf;
        
        int befans = inf;

        for(int rest = 0 ; rest <= mid ; rest++){
            int tmp = inf;

            for(int pref = (st[i] == '1') ; pref <= gt ; pref++){
                //printf("i: %d\n", i);
                if(i == 0){
                    if(st[i] == '1'){ 
                        dp[cur][rest][pref] = 1;

                        if(rest){
                            dp[cur][rest][0] = 0;
                        }
                    }else{
                        dp[cur][rest][pref] = 0;
                    }

                    break;
                }
                else if(st[i] == '0'){
                    if(i != 0){
                        dp[cur][rest][pref] = dp[other][rest][N - 1];
                    }
                    
                    break;
                }else{
                    if(rest){
                        if(dp[other][rest - 1][pref - 1] < dp[cur][rest][0]){
                            dp[cur][rest][0] = dp[other][rest - 1][pref - 1];
                        }

                        dp[cur][rest][pref] = pref +
                            dp[other][rest][pref - 1];
                    }else{
                        dp[cur][rest][pref] = pref + dp[other][rest][pref - 1];
                    }
                }
               // printf("dp = %d, (%d, %d) %d\n", dp[cur][rest][pref], i, rest, pref);
            }

            int best = inf;

            for(int tt = 0 ; tt <= gt ; tt++) best = min(best, dp[cur][rest][tt]);

            dp[cur][rest][N - 1] = best;
        }
    }
   // printf("----\n");
    int cur = (n - 1) & 1;
    
    for(int rest = 0 ; rest <= mid ; rest++){
        for(int pref = 0 ; pref <= gt ; pref++){
            /*if(dp[cur][rest][pref] == 0){
                printf("%d, %d, %d\n", mid, rest, pref);
            }*/
            r = min(r, dp[cur][rest][pref]);
        }
    }
    //printf("r: %d\n", r);
    return r <= k;
}

int main() {
    scanf("%d %d", &n, &k);
    
    scanf("\n%s", st);
    
    int lo = 0, hi = n; 
    int r = -1;
    
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        
        if(can(mid)){
            r = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    
    printf("%d\n", r);
    
	return 0;
}