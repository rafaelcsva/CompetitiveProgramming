#include <bits/stdc++.h>

using namespace std;

const int N = int(1e9) + 10;
vector< long long > oks;

int main(){
    for(long long i = 2 ; i * i < 2 * N ; i++){
        long long r = i * i;

        if((r + 1) % 2LL == 0LL){
            long long c = (r + 1LL) / 2LL;
            // long long b = a - 1;
            long long b = c - 1;
            // if(c == 5){
            //     printf("%lld %lld %lld\n", r, b, c);
            // }
            if(r + b * b == c * c){
                oks.push_back(c);
            }
        }
    }

    int t;

    scanf("%d", &t);

    sort(oks.begin(), oks.end());
    // printf("%lld\n", oks[0]);
    while(t--){
        long long q;

        scanf("%lld", &q);

        printf("%lu\n", upper_bound(oks.begin(), oks.end(), q) - oks.begin());
    }

    return 0;
}