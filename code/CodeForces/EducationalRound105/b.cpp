#include <bits/stdc++.h>

using namespace std;
int sz;
int n;
int a[4];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int u, r, d, l;

        scanf("%d %d %d %d %d", &n, &a[0], &a[1], &a[2], &a[3]);

        bool ok = true;
        for(int i = 0 ; i < 4 ; i++) {
            int p = (i - 1 + 4) % 4;
            int nxt = (i + 1) % 4;
            int frnt = (i + 2) % 4;
        
            if(a[i] == 0){
                if(a[nxt] == n || a[p] == n){
                    ok = false;
                }else if(a[nxt] == n - 1 && a[p] == n - 1 && a[frnt] < 2){
                    ok = false;
                }else if((a[nxt] == n - 1 || a[p] == n - 1) && a[frnt] < 1){
                    ok = false;
                }
            }else if(a[i] == 1){
                if(a[nxt] == n && a[p] == n){
                    ok = false;
                }else if(a[nxt] >= n - 1 && a[p] >= n - 1 && a[frnt] < 1){
                    ok = false;
                }else if(a[nxt] + a[p] == 2 * n - 1 && a[frnt] < 2){
                    ok = false;
                }
            }
        }

        if(ok){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}