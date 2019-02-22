//15, 12, 2018, 10:24:31 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5 + 10);
ll a[N];
map< ll, vector< ll > > mp;
map< ll, ll > cnt, deg;
vector< int > adj[N];
const ll M = 32;
bool taked[N];
int pairs;
queue< ll > q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cnt.clear();

    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &a[i]);

        cnt[a[i]]++;
    }

    // printf("%lu\n", cnt.size());
    // return 0;

    // printf("aqui\n");
    for(map< ll, ll >::iterator it = cnt.begin() ; it != cnt.end() ; it++){
        // printf("%lld\n", it->second);
        // break;
        for(ll j = 0 ; j < M ; j++){
            ll e = 1LL << j;

            if(e <= it->first){
                continue;
            }

            ll r = e - it->first;

            if(r != it->first && cnt.count(r) != 0){
                mp[it->first].push_back(r);
            }
        }

        if(mp[it->first].size() == 1){
            q.push(it->first);
        }

        deg[it->first] = mp[it->first].size();
    }

    while(!q.empty()){
        ll u = q.front();
        // printf("%lld\n", u);

        q.pop();

        if(cnt[u] == 0){
            continue;
        }

        for(int i = 0 ; i < mp[u].size() ; i++){
            ll v = mp[u][i];

            if(cnt[v]){
                ll mn = min(cnt[v], cnt[u]);

                cnt[v] -= mn;
                cnt[u] -= mn;
                pairs += mn;

                if(cnt[u] == 0){
                    deg[v]--;

                    if(deg[v] == 1 && cnt[v] != 0){
                        q.push(v);
                    }
                }
            }
        }
    }

    for(ll j = 0 ; j < M ; j++){
        ll e = 1LL << j;

        pairs += cnt[e] / 2;
    }

    printf("%d\n", pairs);

    return 0;
}