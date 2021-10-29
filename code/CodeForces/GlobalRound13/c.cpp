#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 5010;
ll a[N];
ll ret[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%lld", &a[i]);
            ret[i] = 0LL;
        }

        ll sum = 0LL;

        for(int i = 1 ; i <= n ; i++){
            if(a[i] > 1){
                printf("%lld %d\n", a[i],i);
                ll ret = max(a[i] + i - n - (i == n), 0LL);
                sum += ret;
                a[i] -= ret;

                while(a[i] != 1){
                    sum++;
                    int j = i;

                    while(j <= n){
                        int tj = j;
                        j += a[j];
                        a[tj] = max(a[tj] - 1LL, 1LL);
                        // printf("reduzindo %d\n", tj);
                    }
                }
            }
        }

        printf("%lld\n", sum);
    }

    return 0;
}