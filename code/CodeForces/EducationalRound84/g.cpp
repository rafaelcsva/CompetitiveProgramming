#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long   ll;
 
const int K = 26;
struct Vertex {
    int nnext[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    ll cost = 0LL;
    bool calc_cost = false;
 
    Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
        fill(begin(nnext), end(nnext), -1);
        fill(begin(go), end(go), -1);
    }
};
 
vector< Vertex > t(1);
 
void add_string(string const &s, ll ci){
    int v = 0;
    // cout << "adding " << s << "\n";
    // cout << v << " - ";
    for(char ch: s){
        int c = ch - 'a';
        if(t[v].nnext[c] == -1){
            t[v].nnext[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].nnext[c];
        // cout << v << " - ";
    }
    // cout << "\n";
    t[v].cost += ci;
    t[v].leaf = true;
}
 
int go(int v, char ch);
 
int get_link(int v){
    if(t[v].link == -1){
        if(v == 0 || t[v].p == 0){
            t[v].link = 0;
        }else{
            t[v].link = go(get_link(t[v].p), t[v].pch);
        }
    }
    return t[v].link;
}
 
int go(int v, char ch){
    int c = ch - 'a';
    // cout << v << " w " << ch << " " << t[v].nnext[c] << endl;
    if(t[v].go[c] == -1){
        if(t[v].nnext[c] != -1){
            t[v].go[c] = t[v].nnext[c];
        }else{
            // cout << v << " -> " << get_link(v) << "\n"; 
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
    }
 
    return t[v].go[c];
}
 
ll get_cost(int v){
    if(v == 0){
        return 0LL;
    }
 
    if(t[v].calc_cost){
        return t[v].cost;
    }
 
    // cout << v << " " << t[v].cost << " --- \n";
    t[v].cost += get_cost(get_link(v));
    t[v].calc_cost = true;
 
    return t[v].cost;
}
 
const int N = int(2e3) + 10;
const int M = 1 << 14;
ll a[N];
string s[N];
ll c[N];
ll dp[N][M];
bool used[N][M];
string tt;
ll precost[N][14];
int nnext[N][14];
int nnextst[N][14];
bool usbe[N][14];

ll solve(int p, int state, int mask){
    if(p == tt.length()){
        return 0LL;
    }

    if(tt[p] != '?'){
        int u = go(state, tt[p]);

        return get_cost(u) + solve(p + 1, u, mask);
    }

    ll &ans = dp[state][mask];
    bool &us = used[state][mask];

    if(us){
        return ans;
    }

    us = true;

    ans = -ll(1e18);

    for(char a = 'a' ; a <= 'n' ; a++){
        int pp = a - 'a';

        if((mask & (1 << pp)) == 0){
            // cout << "go " << state << " with " << a << endl;
            int me = mask;
            me |= (1 << pp);

            int u = go(state, a);
            int d = __builtin_popcount(mask) + 1;
            if(usbe[u][d]){
                ans = max(ans, precost[u][d] + solve(nnext[u][d], nnextst[u][d], me));
                continue;
            }

            int tmpu = u;

            usbe[u][d] = true;
            // cout << u << "\n";

            ll tot = get_cost(u);
            int j;

            for(j = p + 1 ; j < tt.length() && tt[j] != '?' ; j++){
                u = go(u, tt[j]);
                tot += get_cost(u);
            }

            precost[tmpu][d] = tot;
            nnext[tmpu][d] = j;
            nnextst[tmpu][d] = u;

            tot += solve(j, u, me);
            ans = max(ans, tot);
        }
    }
    return ans;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
 
    cin >> n;
 
    for(int i = 0 ; i < n ; i++){
        cin >> s[i] >> c[i];
        add_string(s[i], c[i]);
    }
 
    cin >> tt;
 
    cout << solve(0, 0, 0) << "\n";
 
    return 0;
}