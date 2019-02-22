//16, 11, 2018, 13:37:54 Rafaelcs cpp
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
        ll a, b, k;

        cin >> a >> b >> k;

        ll odd = (k / 2LL) + (k & 1LL);
        ll even = k / 2LL;

        cout << a * odd - even * b << endl;
    }

    return 0;
}