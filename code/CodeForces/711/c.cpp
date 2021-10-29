#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll mod = ll(1e9) + 7LL;

const int N = int(1e3) + 10, K = int(1e3) + 10;
ll cnt[N][K];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll n, k;

        scanf("%lld %lld", &n, &k);

        if(k == 1){
            printf("1\n");
        }else if(k == 2){
            printf("%lld\n",1 + n);
        }else{
            cnt[1][k] = 1;
            ll ans = 1LL;
    
            while(k){
                ll tmp = 0LL;
                for(int i = 1 ; i <= n ; i++){
                    cnt[i][k - 1] = tmp;
                    tmp += cnt[i][k];
                    ans += cnt[i][k];

                    // printf("1.+%lld\n", cnt[i][k]);
                    cnt[i][k] = 0LL;

                    if(ans >= mod){
                        ans -= mod;
                    }

                    if(tmp >= mod){
                        tmp -= mod;
                    }
                }        

                k--;
                tmp = 0;

                if(k){
                    for(int i = n ; i >= 1 ; i--){
                        cnt[i][k - 1] = tmp;
                        tmp += cnt[i][k];
                        ans += cnt[i][k];

                        // printf("2.+%lld\n", cnt[i][k]);
                    
                        cnt[i][k] = 0LL;

                        if(ans >= mod){
                            ans -= mod;
                        }

                        if(tmp >= mod){
                            tmp -= mod;
                        }
                    }
                    k--;
                }
                
            }   

            printf("%lld\n", ans);
        }
    }

    return 0;
}