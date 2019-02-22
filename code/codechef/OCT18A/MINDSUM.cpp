//06, 10, 2018, 18:36:52 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<ll, ll> pll;
map< ll, ll > dis;
queue< pll >q;
const int mx = 20;

ll digit_sum(ll n){
    ll s = 0LL;

    while(n){
        s += n % 10LL;
        n /= 10LL;
    }

    return s;
}

void bfs(ll n, ll d){
    dis.clear();

    dis[n] = 0LL;

    q.push({n, 0});

    while(!q.empty()){
        pll u = q.front();
        q.pop();

        if(u.second >= mx){
            continue;
        }

        ll v = digit_sum(u.first);

        if(dis.count(v) == 0){
            dis[v] = u.second + 1LL;
            q.push({v, dis[v]});
        }

        v = u.first + d;

        if(dis.count(v) == 0){
            dis[v] = u.second + 1LL;
            q.push({v, dis[v]});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        ll n, d;

        scanf("%lld %lld", &n, &d);

        bfs(n, d);

        ll besti = -1LL;

        for(ll i = 1LL ; i <= 9LL ; i++){
            if(dis.count(i) != 0){
                besti = i;
                break;
            }
        }

        printf("%lld %lld\n", besti, dis[besti]);
    }

    return 0;
}