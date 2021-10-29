#include <bits/stdc++.h>

using namespace std;

#define x       first
#define y       second

typedef long long   ll;

ll dist(pair< ll, ll > p1, pair< ll, ll > p2, pair< ll, ll > p3){
    ll dx = abs(p1.x - p2.x) + abs(p2.x - p3.x) + abs(p3.x - p1.x);
    ll dy = abs(p1.y - p2.y) + abs(p2.y - p3.y) + abs(p3.y - p1.y);

    return dx + dy;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll n, m, i, j;

        scanf("%lld %lld %lld %lld", &n, &m, &i, &j);

        ll vx[2] = {1LL, n};
        ll vy[2] = {1LL, m};
        pair< ll, ll > p1, p2;
        ll ans = -1LL;

        for(int i1 = 0 ; i1 < 2 ; i1++){
            for(int i2 = 0 ; i2 < 2 ; i2++){
                for(int j1 = 0 ; j1 < 2 ; j1++){
                    for(int j2 = 0 ; j2 < 2 ; j2++){
                        pair< ll, ll > x1 = {vx[i1], vy[j1]};
                        pair< ll, ll > x2 = {vx[i2], vy[i2]};

                        ll tans = min(dist({i, j}, x1, x2), dist({i, j}, x2, x1));

                        if(tans > ans){
                            ans = tans;
                            p1 = x1;
                            p2 = x2;
                        }
                    }
                }
            }
        }

        printf("%lld %lld %lld %lld\n", p1.first, p1.second, p2.first, p2.second);
    }

    return 0;
}