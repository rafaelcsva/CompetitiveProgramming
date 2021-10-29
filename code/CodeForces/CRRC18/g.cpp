#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int cl[N];
string s;

const int K = 3;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector< Vertex > t(1);

void add_string(string const &s){
    int v = 0;

    for(char ch: s){
        int c = ch - '0';
        if(t[v].next[c] == -1){
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }

        v = t[v].next[c];
    }

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
    int c = ch - '0';
    if(t[v].go[c] == -1){
        if(t[v].next[c] != -1){
            t[v].go[c] = t[v].next[c];
        }else{
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
    }

    return t[v].go[c];
}

bool solve(int val, int i, int j){
    // printf("%d %d\n", i, j);
    if(s[i] == '(' && cl[i] == j){
        return solve(val, i + 1, j - 1);
    }

    int k = i;
    int lop = -1;

    while(k <= j){
        if(s[k] == '('){
            k = cl[k] + 1;
            continue;
        }

        if(s[k] == '+' || s[k] == '&' || s[k] == '|'){
            lop = k;
        }
        k++;
    }

    if(lop == -1){
        assert((s[i] >= '0' && s[i] <= '9') || s[i] == '-');
    
        if(s[i] == '-'){
            return !solve(val, i + 1, j);
        }else{
            int lp = s[i] - '0';

            return (val & (1 << lp)) != 0;
        }
    }else{
        auto lf = solve(val, i, lop - 1);
        auto rg = solve(val, lop + 1, j);
        // assert(false);

        if(s[lop] == '|'){
            // printf("ret %d\n", lf | rg);
            return lf | rg;
        }else if(s[lop] == '&'){
            // printf("ret %d\n", lf & rg);
            return lf & rg;
        }else if(s[lop] == '+'){
            // printf("ret %d\n", lf ^ rg);
            return lf ^ rg;
        }
    }
}

typedef long long   ll;

const ll mod = 1LL << 60LL;
int n;
int mx;
ll dp[1010][20 * 1010];

ll solve(int i, int v){
    // cout << i << " " << v << endl;
    if(i >= mx && !t[v].leaf){
        return 0LL;
    }
    if(i == n){
        return 1LL;
    }

    ll &ans = dp[i][v];

    if(ans != -1LL){
        return ans;
    }

    // printf("%d %d\n", i, v);
    ans = solve(i + 1, go(v, '0')) + solve(i + 1, go(v, '1'));

    if(ans >= mod){
        ans -= mod;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof dp);

    cin >> n;
    cin >> s;

    stack< int > st;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '('){
            st.push(i);
        }else if(s[i] == ')'){
            cl[st.top()] = i;
            st.pop();
        }

        if(s[i] >= '0' && s[i] <= '9'){
            mx = max(mx, s[i] - '0' + 1); 
        }
    }

    for(int e = 0 ; e < (1 << mx) ; e++){
        if(solve(e, 0, int(s.length()) - 1)){
            string s = "";
            for(int d = 0 ; d < mx ; d++){
                int g = 1 << d;

                if(e & g){
                    s.push_back('1');
                }else{
                    s.push_back('0');
                }
            }

            // cout << s << " " << e << "\n";
            // cout << s << "\n";
            add_string(s);
        }
    }

    cout << solve(0, 0) << "\n";

    return 0;
}