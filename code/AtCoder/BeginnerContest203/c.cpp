#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair< ll, ll >  pll;

const int N = int(2e5) + 10;
pll p[N];

int main(){
    int n;
    ll k;

    scanf("%d %lld", &n, &k);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld %lld", &p[i].first, &p[i].second);
    }

    sort(p, p + n);

    ll curr = 0LL;

    for(int i = 0 ; i < n ; i++){
        if(p[i].first - curr > k){
            curr += k;
            k = 0LL;
            break;
        }

        k -= (p[i].first - curr);
        // printf("fiquei com %lld\n", k);
        k += p[i].second;
        curr = p[i].first;
    }

    // printf("to em %lld com %lld\n", curr, k);
    curr += k;

    printf("%lld\n", curr);

    return 0;
}