//21, 11, 2018, 16:51:58 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector< pii > reds, blues;
const int N = 1010;
int p, k;
int vis[N];
int match[N];

int aug(int u, int mid){
    if(vis[u]){
        return 0;
    }

    vis[u] = 1;

    for(int i = 0 ; i < blues.size() ; i++){
        int dx = abs(blues[i].first - reds[u].first);
        int dy = abs(blues[i].second - reds[u].second);
        int d = dx * dx + dy * dy;
        
        if(d <= mid * mid){
            if(match[i] == -1 || aug(match[i], mid)){
                match[i] = u;
                return 1;
            }
        }
    }

    return 0;
}

int mcbm(int mid){
    memset(match, -1, sizeof match);

    int mx = 0;

    for(int i = 0 ; i < reds.size() ; i++){
        if(aug(i, mid)){
            mx++;  
        }

        memset(vis, 0, sizeof vis);
    }

    return mx;
}

bool can(int mid){
    int r = mcbm(mid);

    return r >= k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        cin >> p >> k;

        for(int i = 0 ; i < p ; i++){
            int x, y;
            string s;

            cin >> x >> y >> s;

            if(s == "red"){
                reds.push_back({x, y});
            }else{
                blues.push_back({x, y});
            }
        }

        int lo = 1, hi = int(1e4);
        int r = -1;

        while(lo <= hi){
            int mid = (lo + hi) / 2;

            if(can(mid)){
                r = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }

        if(r == -1){
            printf("Impossible\n");
        }else{
            printf("%d\n", r);
        }

        reds.clear();
        blues.clear();
    }
    
    return 0;
}