#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

struct state {
    int len, link;
    int cnt;
    map< char, int > next;
};

const int MAXLEN = int(4e5) + 10;
state st[MAXLEN * 2];
int sz, last;

void sa_init(){
    for(int i = 0 ; i < sz ; i++){
        st[i].len = 0;
        st[i].link = -1;
        st[i].cnt = 0;
        st[i].next.clear();
    }

    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
}

void sa_extend(char c){
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].cnt = 1;
    int p = last;
    while(p != -1 && !st[p].next.count(c)){
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if(p == -1){
        st[cur].link = 0;
    }else{
        int q = st[p].next[c];
        if(st[p].len + 1 == st[q].len){
            st[cur].link = q;
        }else{
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while(p != -1 && st[p].next[c] == q){
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int cont_occ(string &s, string &p){
    if(s.length() < p.length()){
        return 0;
    }
    if(s.length() == p.length()){
        return s == p;
    }

    sa_init();

    for(int i = 0 ; i < s.length() ; i++){
        sa_extend(s[i]);
    }
    // cout << "construido!\n" << endl;
    vector< pair< int, int > > osta;

    for(int i = 0 ; i < sz ; i++){
        osta.push_back({st[i].len, i});
    }

    sort(osta.begin(), osta.end());
    reverse(osta.begin(), osta.end());

    for(auto u: osta){
        if(st[u.second].link > 0){
            st[st[u.second].link].cnt += st[u.second].cnt;
        }
    }

    int curst = 0;

    for(int i = 0 ; i < p.length() ; i++){
        if(!st[curst].next.count(p[i])){
            return 0;
        }

        curst = st[curst].next[p[i]];
    }

    return st[curst].cnt;
}

const int N = 110;
ll ans[N], add[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int test = 1;

    while(cin >> n){
        string s0 = "0";
        string s1 = "1";

        string p;
        cin >> p;

        ans[0] = p == "0";
        ans[1] = p == "1";

        cout << "Case " << test++ << ": ";
    
        if(n <= 1){
            cout << ans[n] << "\n";
        }else{
            for(int i = 2 ; i <= min(n, 28) ; i++){
                string s = s1 + s0;
                // cout << s << endl;

                ans[i] = cont_occ(s, p);

                s0 = s1;
                s1 = s;
            }

            for(int i = 29 ; i <= n ; i++){
                ll add = ans[i - 2] - (ans[i - 3] + ans[i - 4]);
            
                ans[i] = ans[i - 1] + ans[i - 2] + add;
            }

            cout << ans[n] << "\n";
        }
    }

    return 0;
}