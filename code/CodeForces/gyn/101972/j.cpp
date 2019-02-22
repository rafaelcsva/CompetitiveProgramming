//15, 11, 2018, 17:28:55 Rafaelcs cpp
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
        ll n;

        cin >> n;

        ll tot = n + 1;

        ll odd = 1LL << (__builtin_popcountll(n));

        cout << tot - odd << endl;
    }

    return 0;
}