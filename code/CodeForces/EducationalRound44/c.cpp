#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5) + 10;
ll a[N];
int n, k, l;

int main(){
    scanf("%d %d %d", &n, &k, &l);

    for(int i = 0 ; i < n * k ; i++){
        scanf("%lld", &a[i]);
    }

    sort(a, a + n * k);

    int pos = upper_bound(a, a + n * k, a[0] + l) - a;

    pos--;

    int taked = 0;

    taked = 1;
    ll ans = a[0];
    int sz = 1;
    // printf("pos = %d\n", pos);
    for(int i = 1 ; i <= pos ; i++){
        if(pos - i + taked >= n && sz < k){
            // printf("%d, %d, %d = %d\n", pos, taked, i, pos - i + taked);
            sz++;
            continue;
        }
        // printf("new on %d\n", i);
        sz = 1;
        taked++;
        ans += a[i];
    }

    if(taked == n){
        printf("%lld\n", ans);
    }else{
        printf("0\n");
    }


    return 0;
}