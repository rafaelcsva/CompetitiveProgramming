#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
ll d[N];

map< pair< ll, ll >, vector< ll > > con1;

int mod(int a, int b){
    if(b == 0){
        return a;
    }

    return a % abs(b);
}

ll divide(ll a, ll b){
    if(b < 0LL){
        a *= -1LL;
        b *= -1LL;
    }

    if(a < 0LL){
        a -= (b - 1LL);
    }

    return a / b;
}
ll x, y;

ll get_qi(pair< ll, ll > u){
    ll qi;

    if(x){
        qi = divide(u.first, x);
    }else{
        qi = divide(u.second, y);
    }

    return qi;
}

int main(){
    string s;

    set< pair< ll, ll > > cells;

    ll x0 = 0LL;

    ll k;

    cin >> s >> k;

    cells.insert(make_pair(x, y));

    for(auto u: s){
        if(u == 'U'){
            y++;
        }else if(u == 'D'){
            y--;
        }else if(u == 'L'){
            x--;
        }else{
            x++;
        }

        cells.insert(make_pair(x, y));
    }

    if(x == 0 && y == 0){
        // assert(false);
        cout << cells.size() << "\n";
        return 0;
    }

    for(auto u: cells){
        auto qi = get_qi(u);        

        auto e = make_pair(u.first - x * qi, u.second - y * qi);
        // cout << u.first << "," << u.second << " belongs to " << e.first << ", " << e.second << "\n";
        con1[e].push_back(qi);
    }

    for(auto &u: con1){
        sort(u.second.begin(), u.second.end());
    }

    ll ans = 0LL;

    for(auto u: cells){
        ll tans = ll(1e18) + 10LL;

        ll qi = get_qi(u);

        auto e = make_pair(u.first - x * qi, u.second - y * qi);

        auto d = lower_bound(con1[e].begin(), con1[e].end(), qi) - con1[e].begin();

        if(d + 1 < con1[e].size()){
            tans = abs(con1[e][d + 1] - con1[e][d]);
        }
    
        // printf("%d, %d gives %d %lu\n", u.first, u.second, tans, con1[e].size());
        ans += min(tans, k);
    }

    cout << ans << "\n";

    return 0;
}
