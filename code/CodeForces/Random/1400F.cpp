#include <bits/stdc++.h>

using namespace std;

const int K = 26;

string tmp;
vector< string > con;
vector< int > ddiv;
const int N = int(1e4);
int dp[N][1010];
int ans[N];
string s;

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
        int c = ch - '0';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        
        v = t[v].next[c];
        // printf("move!\n");
    }
    // printf("%lu %d eh leaf\n", s.length(), v);
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

int get_ans(int u){
    // printf("asdf: %d\n", u);
    if(ans[u] != -1){
        return ans[u];
    }

    if(t[u].leaf){
        // printf("%d eh leaf!\n", u);
        return ans[u] = 1;
    }

    if(u == 0){
        return 0;
    }

    return ans[u] = get_ans(get_link(u));
}

int go(int v, char ch) {
    int c = ch - '0';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

void gen(int val){
    // printf("val: %d\n", val);

    if(val == 0){
        bool ok = false;
        // cout << "tmp = " << tmp << endl;

        for(auto u: ddiv){
            for(int i = 0 ; i < tmp.size() ; i++){
                int sum = 0;

                for(int j = i ; j < tmp.size() ; j++){
                    sum += tmp[j] - '0';

                    if(sum == u){
                        ok = true;
                        break;
                    }else if(sum > u){
                        break;
                    }
                }

                if(ok) break;
            }
            if(ok) break;
        }

        if(!ok)
            con.push_back(tmp);

        return;
    }

    for(int i = 1 ; i <= min(val, 9) ; i++){
        tmp.push_back('0' + i);
        gen(val - i);
        tmp.pop_back();
    }
}

const int inf = int(1e7);

int solve(int u, int i){
    int &ans = dp[u][i];

    if(get_ans(u)){
        return ans = inf;
    }

    if(i == s.length()){
        return 0;
    }

    if(ans != -1){
        return ans;
    }
    // printf("a-> %d %d\n", u, get_ans(u));

    // printf("U: %d %d\n", u, i);

    return ans = min(solve(u, i + 1) + 1, solve(go(u, s[i]), i + 1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(ans, -1, sizeof ans);
    memset(dp, -1, sizeof dp);

    int x;

    cin >> s >> x;

    for(int i = 1 ; i < x ; i++){
        if(x % i == 0){
            ddiv.push_back(i);
        }
    }

    gen(x);

    for(int i = 0 ; i < con.size() ; i++){
        // cout << "L = " << con[i] << endl;
        add_string(con[i]);
    }

    cout << solve(0, 0) << "\n";
    // printf("%d\n", solve(0, 0));

    return 0;
}