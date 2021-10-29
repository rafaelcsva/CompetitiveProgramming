#include <bits/stdc++.h>

using namespace std;

int ans[10];
const int N = 2010;
char tab[N][N];
int mnc[10], mxc[10];
int mnr[10], mxr[10];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        memset(ans, 0, sizeof ans);

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                scanf("\n%c", &tab[i][j]);
            }
        }
        for(int d = 0 ; d < 10 ; d++){
            mnr[d] = n + 1;
            mxr[d] = -1;
            mnc[d] = n + 1;
            mxc[d] = -1;
        }

        for(int i = n; i >= 1 ; i--){
            for(int j = n ; j >= 1 ; j--){
                int d = tab[i][j] - '0';
                mnc[d] = min(mnc[d], j);
                mxc[d] = max(mxc[d], j);
                mnr[d] = min(mnr[d], i);
                mxr[d] = max(mxr[d], i);
            }
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                int d = tab[i][j] - '0';
                int lc = max(n - i, i - 1) * max(abs(j - mnc[d]), abs(j - mxc[d]));
                int lr = max(n - j, j - 1) * max(abs(i - mnr[d]), abs(i - mxr[d]));

                ans[d] = max(ans[d], max(lc, lr));
                // if(d == 0 && max(lc, lr) == 6){
                //     printf("%d %d (%d, %d), %d\n", i, j, lc, lr, mnr[d]);
                // }
            }
        }

        for(int i = 0 ; i < 10 ; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
    }

    return 0;
}