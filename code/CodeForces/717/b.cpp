#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 2010;
ll a[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        ll sum = 0LL;

        for(int i = 0 ; i < n ; i++){ 
            scanf("%lld", &a[i]);
            sum ^= a[i];
        }

        ll sumr = 0;
        bool ok = false;
        int cnt = 0;

        for(int i = 0 ; i < n ; i ++){
            sumr ^= a[i];

            if(sumr == sum){
                sumr = 0;
                cnt++;
            }
        }

        if(sum == 0 || cnt > 1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}