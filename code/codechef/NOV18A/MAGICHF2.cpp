//02, 11, 2018, 19:32:31 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

ll solve(ll n, ll k){
    if(n == 2LL){
        return n;
    }

    if(k == 0LL || n == 1LL){
        return n;
    }

    if(n <= 4LL){
        if(n == 3LL){
            if(k == 1LL){
                return 2LL;
            }else{
                return 1LL;
            }
        }else{
            if(k <= 1LL){
                return 2LL;
            }else{
                return 1LL;
            }
        }
    }else{
        ll add = 0LL;

        if(n & 1LL){
            return solve(n / 2LL + 1LL, k - 1LL);
        }else{
            if((n / 2LL) & 1LL){
                n--;

                return solve(n / 2LL + 1LL, k - 1LL);
            }else{
                return solve(n / 2LL, k - 1LL);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        ll n, k;

        scanf("%lld %lld", &n, &k);

        ll r = solve(n, k);

        printf("%.7lf\n", double(1.0) / double(r));
    }

    return 0;
}