#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    cin >> t;

    while(t--){
        ll a, b;

        cin >> a >> b;
    
        if(b == 1LL){
            printf("NO\n");
        }else{
            if(b == 2LL){
                printf("YES\n%lld %lld %lld\n", a * 3LL, a * (b - 1LL), a * (b + 2LL));
            }else{
                printf("YES\n%lld %lld %lld\n", a, a * (b - 1LL), a * b);
            }
        }
    }    

    return 0;
}