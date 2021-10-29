#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        ll sum = 0LL;
        bool ok = true;

        for(int i = 0 ; i < n ; i++){
            ll hi;

            scanf("%lld", &hi);

            if(sum + hi >= i){
                if(hi < i){
                    sum -= i - hi;
                }else{
                    sum += (hi - i);
                }
            }else{
                ok = false;
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