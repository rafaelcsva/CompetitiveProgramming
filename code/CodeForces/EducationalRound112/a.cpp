#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll pi;

        scanf("%lld", &pi);

        if(pi <= 6){
            printf("15\n");
        }else if(pi <= 8){
            printf("20\n");
        }else if(pi <= 10){
            printf("25\n");
        }else{
            ll tot = 25LL * pi;
            // printf("%lld\n", tot);

            tot /= 10LL;

            while(tot % 5LL){
                tot++;
            }

            printf("%lld\n", tot);
        }
    }

    return 0;
}