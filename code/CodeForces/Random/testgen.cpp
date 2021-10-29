#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 60;
ll a[N];
const ll inf = ll(1e18);

int main(){
    srand(time(NULL));

    int n = 20;
    int k = 3;

    printf("%d %d\n", n, k);

    ll last = rand() % ll(sqrt(inf)) + 1LL;

    for(int i = 0 ; i < n ; i++){
        printf("%lld ", last);
        last <<= 1LL;
    }

    ll a = rand() % inf + 1LL;
    ll b = rand() % inf + 1LL;

    if(a > b){
        swap(a, b);
    }
    printf("\n");
    printf("%lld %lld\n", a, b);

    return 0;
}