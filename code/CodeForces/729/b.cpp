#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int D = 40;

bool can(ll x, ll da, ll a, ll b){
    if(x % b){
        return false;
    }else{
        return true;
    }
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll n, a, b;

        scanf("%lld %lld %lld", &n, &a, &b);

        bool frag = false;

        for(ll da = 1LL ; da <= n ; da *= a){
            if(can(n - da, da, a, b)){
                frag = true;
                break;
            }

            if(a == 1){
                break;
            }
        }
        if(frag){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

    return 0;
}