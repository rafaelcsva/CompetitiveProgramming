#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;
        ll k;

        scanf("%d %lld", &n, &k);
    
        k--;
        int x = 0;
        ll r = 1LL;

        while(r - 1LL < k){
            r = (r << 1LL);
            x++;
        }

        // printf("%d %d %lld\n", x, n, r);

        if(x > n - 1){
            printf("-1\n");
        }else{
            vector< int > ve;

            r = (r - 1LL) - k;

            int k = 1;

            // printf("a: %lld\n", r);

            for(int st = n - 2 ; st >= 0 ; st--){
                if(st < x){
                    ll e = 1LL << st;

                    if(e & r){
                        ve.push_back(k);
                    }
                }else{
                    ve.push_back(k);
                }

                k++;
            }

            ve.push_back(n);

            vector< int > d;

            int last = 0;

            for(auto u: ve){
                d.push_back(u);

                int tu = u;
                while(--tu > last){
                    d.push_back(tu);
                }

                last = u;
            }

            for(auto u: d){
                printf("%d ", u);
            }
            printf("\n");
        }
    }

    return 0;
}