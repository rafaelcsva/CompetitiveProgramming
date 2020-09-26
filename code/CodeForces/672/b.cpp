#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int a[N];
long long cnt[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);

            for(int d = 30 ; d >= 0 ; d--){
                int e = (1 << d);

                if(a[i] & e){
                    cnt[d]++;
                    break;
                }
            }
        }

        long long ans = 0LL;

        for(int d = 0 ; d <= 30 ; d++){
            ans += (cnt[d] * (cnt[d] - 1LL)) / 2LL;
        }

        printf("%lld\n", ans);
        memset(cnt, 0, sizeof cnt);
    }

    return 0;
}