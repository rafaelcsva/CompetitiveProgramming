//16, 02, 2019, 10:09:12 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 100);
ll suf[N];
ll pref[N];
ll mx_suf[N];
ll mx_pref[N];
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    bool is_equal = true;
    bool is_evenodd = true;

    cin >> n;

    ll g = 0LL;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];

        g = __gcd(g, a[i]);
    }

    cout << g << endl;

    return 0;
}