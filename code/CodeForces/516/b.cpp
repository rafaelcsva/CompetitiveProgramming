//14, 10, 2018, 07:11:20 Rafaelcs cpp
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
        ll a;

        cin >> a;

        ll c = __builtin_popcountll(a);

        cout << (1LL << c) << endl;
    }

    return 0;
}