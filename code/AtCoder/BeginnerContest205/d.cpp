#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5) + 10;
ll pref[N];
ll a[N];
const ll ge = ll(2e18);

int main(){
    int n, q;

    scanf("%d %d", &n, &q);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &a[i]);
    }

    a[++n] = ge;

    for(int i = 1 ; i <= n ; i++){
        pref[i] = (a[i] - a[i - 1] - 1) + pref[i - 1];
    }

    while(q--){
        ll ki;

        scanf("%lld", &ki);

        if(ki < a[1]){
            printf("%lld\n", ki);
        }else{
            int lo = 1, hi = n;
            int r = -1;

            while(lo <= hi){
                int mid = (lo + hi) >> 1;

                if(pref[mid] < ki){
                    lo = mid + 1;
                    r = mid;
                }else{
                    hi = mid - 1;
                }
            }

            assert(r != -1);

            printf("%lld\n", a[r] + (ki - pref[r]));
        }
    }

    return 0;
}