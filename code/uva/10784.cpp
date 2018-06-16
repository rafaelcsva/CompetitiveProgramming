//11, 06, 2018, 21:19:58 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const ll INF = ll(1e9);

int main(){
    int test = 1;
    ll n;

    while(scanf("%lld", &n) != EOF){
        if(n == 0){
            break;
        }

        ll st = 3LL, en = INF;
        ll r = -1LL;

        while(st <= en){
            ll mid = (st + en) / 2LL;

            if(mid * (mid - 3LL) >= n * 2LL){
                r = mid;
                en = mid - 1LL;
            }else{
                st = mid + 1LL;
            }
        }

        cout << "Case " << test++ << ": " << r << endl;
    }    

    return 0;
}