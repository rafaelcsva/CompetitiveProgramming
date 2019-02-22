//09, 02, 2019, 10:14:31 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll k, a, b;

    cin >> k >> a >> b;

    if(b <= a + 2LL || (a - 1LL) >= k){
        cout << 1LL + k << endl;
    }else{
        k -= (a - 1LL);
        ll have = a;
        ll add = 0LL;
        // cout << k << endl;

        if(k & 1LL){
            k--;
            add = 1LL;
        }
        // cout << add << endl;

        cout << (k / 2LL) * (b - a) + add + a << endl;
    }

    return 0;
}