#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6);
int x[N];
int cc[N + 10];
map< int, int > cnt;
map< int, bool > ver;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        bool frag = false;

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &x[i]);
            cnt[x[i]]++;

            frag |= (cnt[x[i]] >= n / 2);
        }

        cnt.clear();
        if(frag){
            printf("-1\n");
            continue;
        }

        int ans = 0;

        for(int d = 0 ; d < n ; d++){
            for(int e = d + 1 ; e < n; e++){
                if(x[d] != x[e]){
                    int ex = abs(x[d] - x[e]);
                    for(int i = 1 ; i * i <= ex ; i++){
                        ver[i] = ver[ex / i] = true;
                    }
                }
            }
        }

        for(auto u: ver){
            int i = u.first;
            int tmp = 0;
            int cnt = 0;

            // printf("test %d\n", i);
            for(int j = 0 ; j < n ; j++){
                int xj = ((x[j] % i) + i) % i;
                
                cc[xj]++;
                cnt = max(cnt, cc[xj]);
            }

            if(cnt >= n / 2){
                ans = max(ans, i);
            }

            for(int j = 0 ; j < n ; j++){
                int xj = ((x[j] % i) + i) % i;

                cc[xj]--;
            }
        }
        ver.clear();

        if(ans > N){
            ans = -1;
        }
        printf("%d\n", ans);
    }

    return 0;
}
