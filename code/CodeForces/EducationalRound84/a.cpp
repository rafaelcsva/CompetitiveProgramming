#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll n, k;

        scanf("%lld %lld", &n, &k);

        if((n & 1LL) != (k & 1LL)){
            printf("NO\n");
        }else{
            ll mtot = ((1LL + 1LL + (k - 1LL) * 2LL) * k) / 2LL;
        
            if(mtot <= n){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }   

    return 0; 
}