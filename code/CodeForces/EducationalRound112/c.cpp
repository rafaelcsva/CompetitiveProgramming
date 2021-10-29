#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int pref[N];
int suf[N];
int a[2][N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int j = 0 ; j < 2 ; j++){
            for(int i = 1 ; i <= n ; i++){
                scanf("%d", &a[j][i]);
                if(j == 1){
                    pref[i] = a[j][i] + pref[i - 1];
                }
            }
        }

        for(int i = n ; i >= 1 ; i--){
            suf[i] = suf[i + 1] + a[0][i];
        }

        int ans = int(2e9);
        
        for(int i = 1 ; i <= n ; i++){
            int tmp = max(pref[i - 1], suf[i + 1]);

            ans = min(ans, tmp);
        }

        printf("%d\n", ans);

        for(int i = 1 ; i <= n ; i++){
            suf[i] = pref[i] = 0;
        }
    }

    return 0;
}