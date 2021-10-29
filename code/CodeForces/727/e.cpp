#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
bool dp[N][2];
int last[2];
int l[2], r[2];
int tmpl[2], tmpr[2];
int a[N][2], b[N][2];
int k[N];

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &k[i]);
        scanf("%d %d", &a[i][0], &b[i][0]);
        scanf("%d %d", &a[i][1], &b[i][1]);
    }

    dp[n + 1][0] = dp[n + 1][1] = true;
    r[0] = r[1] = m;

    for(int i = n ; i >= 0 ; i--){
        for(int d = 0 ; d < 2 ; d++){
            if(k[i] >= a[i][d] && k[i] <= b[i][d] && k[i] >= l[d] && k[i] <= r[d]){
                dp[i][d] = true;
            }
        }
        for(int d = 0 ; d < 2 ; d++){
            if(k[i] >= a[i][d] && k[i] <= b[i][d] && k[i] >= l[d] && k[i] <= r[d]){
                tmpl[!d] = a[i][!d];
                tmpr[!d] = b[i][!d]; 
            }else{
                if(k[i] >= a[i][d] && k[i] <= b[i][d]){
                    tmpl[!d] = max(l[!d], a[i][!d]);
                    tmpr[!d] = min(r[!d], b[i][!d]);
                }else{
                    tmpl[!d] = -1;
                    tmpr[!d] = -1;
                }
            }
        }
        for(int d = 0 ; d < 2 ; d++){
            l[d] = tmpl[d];
            r[d] = tmpr[d];
        }
    }

    if(!dp[0][0] && !dp[0][1]){
        printf("No\n");
    }else{
        printf("Yes\n");
        int st = 0;

        if(!dp[0][0]){
            st = 1;
        }
        // printf("st: %d\n", st);

        for(int i = 1 ; i <= n ; i++){
            printf("%d ", !st);
            if(dp[i][!st]){
                st = !st;
            }
        }

        printf("\n");
    }

    return 0;
}