#include <bits/stdc++.h>

using namespace std;

int compute(int n, int k){
    int ans = 0;

    while(n){
        ans += n % k;
        n /= k;
    }

    return ans;
}

int main(){
    int q;

    scanf("%d", &q);

    while(q--){
        int n, l, r;

        scanf("%d %d %d", &n, &l, &r);

        int mn = int(1e9);

        int last = -1;
        int diff = -1;
        int cnt = 0;

        for(int k = l ; k <= r ; k++){
            mn = min(mn, compute(n, k));
            // int res = compute(n, k);

            // if(res > last){
            //     printf("%d %d %d | %d\n", cnt, diff, k - 1, last);
            //     cnt = 0;
            // }

            // diff = last - res;
            // last = res;
            // cnt++;
        }

        printf("%d\n", mn);
        for(int k = l ; k <= r ; k++){
            if(compute(n, k) == mn){
                printf("%d ", k);
            }
        }
        printf("\n");

        // printf("divisors:\n");
        // for(int i = 2 ; i * i <= n ; i++){
        //     if(n % i == 0){
        //         printf("%d\n", i);
        //         printf("%d\n", n / i);
        //     }
        // }
    }

    return 0;
}
