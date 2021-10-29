#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 210;
ll cnt[N];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    ll ans = 0LL;

    for(int i = 0 ; i < n ; i++){
        int ai;

        cin >> ai;
        ai %= 200;
        ans += cnt[ai];

        cnt[ai]++;
    }

    cout << ans << endl;

    return 0;
}