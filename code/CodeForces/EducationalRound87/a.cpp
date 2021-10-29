#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        long long a, b, c, d;

        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

        if(b >= a){
            printf("%lld\n", b);
        }else{
            long long ans = b;
            a -= b;

            if(c <= d){
                printf("-1\n");
            }else{
                long long add = c - d;

                long long q = (a + add - 1LL) / add;

                ans += q * c;

                printf("%lld\n", ans);
            }
        }
    }

    return 0;
}