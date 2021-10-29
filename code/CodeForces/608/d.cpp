#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll k;
        scanf("%lld", &k);

        if(k & 1LL){
            printf("-1\n");
        }else{
            vector< int > ans;
            k -= 2LL;
            ll r = 2LL;

            ans.push_back(1);

            while(k){
                if(r * 2LL <= k){
                    ans.push_back(0);
                    r *= 2LL;
                    // printf("rem %lld\n", r);
                    k -= r;
                }else{
                    ans.push_back(1);
                    r = 2LL;
                    k -= r;
                }
            }

            printf("%lu\n", ans.size());

            for(auto u: ans){
                printf("%d ", u);
            }
            printf("\n");
        }
    }

    return 0;
}