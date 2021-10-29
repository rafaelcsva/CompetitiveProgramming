#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        ll e = 1LL;
        ll cnt = 0LL;

        for(int i = 0 ; i < n ; i++){
            int xi;

            scanf("%d", &xi);

            if(xi == 0LL){
                e <<= 1LL;
            }else if(xi == 1LL){
                cnt++;
            }
        }

        printf("%lld\n", cnt * e);
    }

    return 0;
}