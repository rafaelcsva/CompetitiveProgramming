#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        long long a, b;

        scanf("%lld %lld", &a, &b);

        if(a == b){
            printf("0 0\n");
        }else{
            if(a > b){
                swap(a, b);
            }

            long long d = b - a;

            long long ans = min(b % d, (d - (b % d)) % d);

            printf("%lld %lld\n", d, ans);
        }
    }

    return 0;
}