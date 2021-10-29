#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        long long n, k;

        scanf("%lld %lld", &n, &k);

        int pos = 0;

        if(n & 1){
            long long mt = n / 2;
            k--;

            long long d = (k / mt) * (mt + 1);
            d += (k % mt);

            printf("%lld\n", d % n + 1);
        }else{
            printf("%lld\n", (k - 1) % n + 1);
        }
    }

    return 0;
}