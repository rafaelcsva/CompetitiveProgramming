//01, 04, 2019, 18:19:32 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        ll n;

        cin >> n;

        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }

        ll res = 0LL;

        for(ll j = 0LL ; j <= 30LL ; j++){
            ll b = (1LL << j);

            ll carry = 0LL;
            ll tot = 0LL;

            for(int k = 0 ; k < n ; k++){
                if(a[k] & b){
                    tot += ((carry + 1LL) * (carry)) >> 1LL;
                    carry = 0LL;
                }else{
                    carry++;
                }
            }

            if(carry){
                tot += ((carry + 1LL) * (carry)) >> 1LL;
            }
            cout << ((((1LL + n) * n) >> 1LL) - tot) << " in " << b << " " << tot << endl;
            res += ((((1LL + n) * n) >> 1LL) - tot)  * b;
        }

        cout << res << endl;
    }

    return 0;
}