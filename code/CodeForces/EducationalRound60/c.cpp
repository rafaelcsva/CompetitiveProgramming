//18, 02, 2019, 14:04:16 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const ll MAX_IT = int(1e6);
int n;
ll x1, yy1, x2, y2;
char comm[MAX_IT];

ll walk(ll x, ll y, ll add){
    for(ll i = 0 ; i < n ; i++){
        if(comm[i] == 'U'){
            y++;
        }else if(comm[i] == 'D'){
            y--;
        }else if(comm[i] == 'L'){
            x--;
        }else{
            x++;
        }

        ll dist = abs(x - x2) + abs(y - y2);

        if(dist <= (i + 1LL + add)){
            return i + 1LL;
        }
    }

    assert(false);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x1 >> yy1;
    cin >> x2 >> y2;

    ll sald_hor = 0LL, sald_ver = 0LL;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> comm[i];

        if(comm[i] == 'U'){
            sald_ver++;
        }else if(comm[i] == 'D'){
            sald_ver--;
        }else if(comm[i] == 'L'){
            sald_hor--;
        }else{
            sald_hor++;
        }
    }

    ll day = -1LL;
    ll pass = 0LL;
    ll wx1 = x1, wy2 = yy1;

    ll lo = 0LL, hi = ll(2e9);
    ll r = -1LL;

    while(lo <= hi){
        ll mid = (lo + hi) >> 1LL;
        ll tmpx = wx1 + sald_hor * mid, tmpy = wy2 + sald_ver * mid;
        ll dist = abs(tmpx - x2) + abs(tmpy - y2);
        ll pass = mid * n;

        if(dist <= pass){
            r = mid;
            hi = mid - 1LL;
        }else{
            lo = mid + 1LL;
        }
    }

    if(r == -1LL){
        cout << -1 << endl;
    }else{
        // cout << r << endl;
        cout << (r - 1LL) * n + walk(x1 + sald_hor * (r - 1LL), yy1 + sald_ver * (r - 1LL), (r - 1LL) * n) << endl;
    }

    return 0;
}