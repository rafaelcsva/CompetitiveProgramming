#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

const int N = 21;
int a, b;
ll dp[N * 60][N][2][2][2];
int add[60];
const ll mod = ll(1e6) + 3LL;

ll solve(int v, int pos, int g, int m, int d){
    if(t[v].leaf){
        return 0;
    }

    if(pos > b){
        return (g & m & d);
    }

    ll &ans = dp[v][pos][g][m][d];

    if(ans != -1LL){
        return ans;
    }

    ans = 0LL;

    if(g & m & d)
        ans = (a <= pos);

    printf("%d %d %d\n", g, m, d);

    for(char a = 'a' ; a <= 'z' ; a++){
        ans += solve(go(v, a), pos + 1, g, 1, d);

        if(ans >= mod){
            // ans -= mod;
        }

        ans += solve(go(v, a), pos + 1, 1, m, d);

        // if(ans >= mod) ans -= mod;

        if(add[a]){
            ans += solve(go(v, a), pos + 1, g, m, 1);

            if(ans >= mod){
                // ans -= mod;
            }
        }

        for(char d = '0' ;d <= '9' - add[a] ; d++){
            ans += solve(0, pos + 1, g, m, 1);

            if(ans >= mod){
                // ans -= mod;
            }
        }
    }

    // if(ans < 0){
    //     printf("%d %d %lld\n", v, pos, ans);
    //     exit(0);
    // }
    // if(ans)
    // printf("%lld\n", ans);

    return ans;
}   

int main(){
    add['o'] = add['i'] = add['e'] = add['s'] = add['t'] = 1;
    memset(dp, -1LL, sizeof dp);

    cin >> a >> b;

    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string s;

        cin >> s;
        add_string(s);
    }

    printf("%lld\n", solve(0, 0, 0, 0, 0));

    return 0;
}