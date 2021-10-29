#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e6) + 10;
int markx[N];
int marky[N];
int x[N], y[N];
int xx[N], yy[N];
int cntx[N];
int cnty[N];
vector< int > conx[N], cony[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m, k;

        scanf("%d %d %d", &n, &m, &k);
    
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &x[i]);
            markx[x[i]] = 1;
        }

        for(int i = 0 ; i < m ; i++){
            scanf("%d", &y[i]);
            marky[y[i]] = 1;
        }

        for(int i = 0 ; i < k ; i++){
            int xi, yi;
            scanf("%d %d", &xi, &yi);

            xx[i] = xi;
            yy[i] = yi;
        
            if(markx[xi] && marky[yi]){
                continue;
            }

            if(markx[xi]){
                cony[xi].push_back(yi);
            }else{
                conx[yi].push_back(xi);
            }
        }

        for(int i = 0 ; i < n ; i++){
            sort(cony[x[i]].begin(), cony[x[i]].end());
        }

        for(int i = 0 ; i < m ; i++){
            sort(conx[y[i]].begin(), conx[y[i]].end());
        }

        ll ans = 0LL;

        for(int i = 0 ; i < m ; i++){
            int last = -1;
            int acc = 0;
            // printf("testando %d\n", y[i]);

            for(auto u: conx[y[i]]){
                int idx = upper_bound(x, x + n, u) - x - 1;

                if(idx != last && last != -1){
                    cntx[last] += acc;
                    acc = 0;
                }

                ans += ll(cntx[idx]);
                // printf("asdfas\n");
                // printf("+ %lld\n", ll(cntx[idx]));
                acc++;
                last = idx;
            }

            if(last != -1){
                cntx[last] += acc;
            }
        }

        for(int i = 0 ; i < n ; i++){
            int last = -1;
            int acc = 0;

            // printf("test on %d\n", x[i]);

            for(auto u: cony[x[i]]){
                // printf("test on %d\n", x[i]);
                int idx = upper_bound(y, y + m, u) - y - 1;

                if(idx != last && last != -1){
                    cnty[last] += acc;
                    acc = 0;
                }

                ans += ll(cnty[idx]);
                // printf("+ %lld\n", ll(cnty[idx]));
                acc++;
                last = idx;
            }

            if(last != -1){
                cnty[last] += acc;
            }
        }

        printf("%lld\n", ans);

        for(int i = 0 ; i < n ; i++){
            markx[x[i]] = marky[x[i]] = 0;
            cntx[i] = cnty[i] = 0;
            cony[x[i]].clear();
            conx[x[i]].clear();
        }

        for(int i = 0 ; i < m ; i++){
            markx[y[i]] = marky[y[i]] = 0;
            
            cntx[i] = cnty[i] = 0;
            cony[y[i]].clear();
            conx[y[i]].clear();
        }
    }

    return 0;
}