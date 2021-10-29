#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int a[N];
vector< pair< int, int > > p;
const int inf = int(1e9) + 10;
int r[N], c[N];

int solve(int dr, int dc){
    if(dc > dr){
        return inf;
    }

    return (dr - dc + 1) / 2;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &r[i]);
        }

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &c[i]);
        }

        p.clear();
        for(int i = 0 ; i < n ; i++){
            p.push_back({r[i], c[i]});
        }

        sort(p.begin(), p.end());

        pair< int, int > cur = {1, 1};
        int ans = 0;

        for(auto u: p){
            bool even = (cur.first + cur.second) % 2 == 0;
            int dr = u.first - cur.first;
            int dc = u.second - cur.second;
            
            if(dr == dc){
                if(even) {
                    ans += dr;
                }
            }else{
                if(even){
                    ans += solve(dr - 1, dc);
                }else{
                    ans += solve(dr, dc);
                }
            }

            cur = u;
        }

        printf("%d\n", ans);
    }

    return 0;
}