#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
vector< ll > x, y;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        cin >> n;

        for(int i = 0 ; i < n ; i++){
            ll xi, yi;

            cin >> xi >> yi;

            x.push_back(xi);
            y.push_back(yi);
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        ll ans = 1LL;
        if((n & 1) == 0){
            // cout << x[x.size() / 2] << " " << x[x.size() / 2 - 1] << " " << x[3] << endl;
            ans *= (x[x.size() / 2] - x[x.size() / 2 - 1] + 1LL);
            ans *= (y[y.size() / 2] - y[y.size() / 2 - 1] + 1LL);
        }

        cout << ans << endl;
        x.clear();
        y.clear();
    }
}