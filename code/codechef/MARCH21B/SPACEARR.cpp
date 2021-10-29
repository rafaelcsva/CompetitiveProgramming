#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
ll a[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);
        }

        sort(a, a + n);

        bool ok = true;
        ll sum = 0LL;

        for(int i = 1 ; i <= n ; i++){
            if(i < a[i - 1]){
                ok = false;
                break;
            } else {
                // printf("%lld\n", (ll(i) - a[i - 1]));
                sum ^= (ll(i) - a[i - 1]);
            }
        }

        if((sum & 1) && ok){
            printf("First\n");
        }else{
            printf("Second\n");
        }
    }

    return 0;
}