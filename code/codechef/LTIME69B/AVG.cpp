//23, 02, 2019, 11:08:15 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        ll n, k, v;
        ll sum = 0LL;

        cin >> n >> k >> v;
        for(int i = 0 ; i < n ; i++){
            ll ai;

            cin >> ai;

            sum += ai;
        }

        ll res = v * (k + n) - sum;

        if(res <= 0LL || (res % k)){
            cout << -1LL << endl;
        }else{
            cout << (res / k) << endl;
        }
    }

    return 0;
}