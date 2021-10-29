#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int a[N];
int t[N];
int pref[N], suf[N], acc[N];

int main(){
    int n, k;

    scanf("%d %d", &n, &k);
    
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &t[i]);

        pref[i] = t[i] * a[i] + pref[i - 1];
        acc[i] = a[i] + acc[i - 1];
    }

    for(int i = n ; i >= 1 ; i--){
        suf[i] = t[i] * a[i] + suf[i + 1];
    }

    int ans = 0;

    for(int i = 1 ; i <= n - k + 1 ; i++){
        ans = max(ans, pref[i - 1] + suf[i + k] + acc[i + k - 1] - acc[i - 1]);

        // if(i == 3){
        //     printf("%d %d\n", pref[i - 1], suf[i + k]);
        // }
    }

    printf("%d\n", ans);

    return 0;
}