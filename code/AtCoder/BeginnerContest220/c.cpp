#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5) + 10;
ll a[N];

int main(){
    int n;

    cin >> n;

    ll sum  =0LL;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        sum += a[i];
    }

    ll x;

    cin >> x;

    ll ans = (x / sum) * n;
    x %= sum;

    sum = 0LL;

    for(int i = 0 ; i < n ; i++){
        if(sum > x){
            break;
        }

        ans++;
        sum += a[i];
    }

    cout << ans << "\n";

    return 0;
}