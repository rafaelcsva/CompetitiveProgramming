#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5) + 10;
ll a[N];

ll gg(ll a, ll b){
    return (a * b) / __gcd(a, b);
}

ll ans[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);
        }

        if((n & 1) == 0){
            for(int i = 0 ; i < n ; i += 2){
                ll a0 = abs(a[i]);
                ll a1 = abs(a[i + 1]);
                ll e = gg(a0, a1);

                ll r0 = e / a0;
                ll r1 = e / a1;

                ans[i] = r0;
                ans[i + 1] = -r1;

                if(a[i] < 0){
                    ans[i] *= -1;
                }

                if(a[i + 1] < 0){
                    ans[i + 1] *= -1;
                }
            }
        }else{
            for(int i = 0 ; i < n - 3 ; i += 2){
                ll a0 = abs(a[i]);
                ll a1 = abs(a[i + 1]);
                ll e = gg(a0, a1);

                ll r0 = e / a0;
                ll r1 = e / a1;

                ans[i] = r0;
                ans[i + 1] = -r1;

                if(a[i] < 0){
                    ans[i] *= -1;
                }

                if(a[i + 1] < 0){
                    ans[i + 1] *= -1;
                }
            }

            ll a0 = abs(a[n - 3]);
            ll a1 = abs(a[n - 2]) + abs(a[n - 1]);
            ll e = gg(a0, a1);

            ll r0 = e / a0;
            ll r1 = e / a1;

            ans[n - 3] = r0;
            ans[n - 2] = -r1;
            ans[n - 1] = -r1;

            if(a[n - 3] < 0){
                ans[n - 3] *= -1;
            }

            if(a[n - 2] < 0){
                ans[n - 2] *= -1;
            }
            
            if(a[n - 1] < 0){
                ans[n - 1] *= -1;
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }

    return 0;
}