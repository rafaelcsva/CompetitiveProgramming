#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int cnt[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < n ; i++){
            int ai;
            scanf("%d", &ai);

            cnt[ai % m]++;
        }

        int ans = 0;

        for(int i = 0 ; i < m ; i++){
            if(!cnt[i]) continue;
            int o = (m - i) % m;

            ans++;
            if(cnt[i] > cnt[o]){
                cnt[i] -= (cnt[o] + 1);
                cnt[o] = 0;
            }else if(cnt[o] > cnt[i]){
                cnt[o] -= (cnt[i] + 1);
                cnt[i] = 0;
            }else{
                cnt[i] = cnt[o] = 0;
            }

            ans += cnt[i] + cnt[o];
            cnt[i] = cnt[o] = 0;
        }

        printf("%d\n", ans);
    }

    return 0;
}