#include <bits/stdc++.h>

using namespace std;

long long sum(long long a){
    long long ans = 0LL;

    while(a){
        ans += a % 10LL;
        a /= 10LL;
    }

    return ans;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        long long a;

        scanf("%lld", &a);


        // printf("%lld %lld\n", sum(a), __gcd(a, sum(a)));
        while(__gcd(a, sum(a)) == 1LL){
            a++;
        }

        printf("%lld\n", a);
    }
    return 0;
}