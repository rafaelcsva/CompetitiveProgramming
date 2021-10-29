#include <bits/stdc++.h>

using namespace std;

struct state{
    int len, link;
    int cnt = 0;
    int firstpos;
    map< char, int > next;
};
typedef pair< int, int >    pii;
const int MAXLEN = 300010;
state st[MAXLEN * 2];
pii dp[MAXLEN * 2];
int sz, last;

void sa_init(){
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(char c){
    int cur = sz++;
    st[cur].len = st[last].len + 1; 
    st[cur].cnt = 1;
    st[cur].firstpos = st[cur].len - 1;

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
            st[clone].firstpos = st[q].firstpos;
        }
    }
    last = cur;
}

pii solve(int state){
    auto &ans = dp[state];

    if(ans.first != -1){
        return ans;
    }

    if(st[state].cnt == 1){
        return {0, st[state].firstpos};
    }

    ans = {int(1e9), int(1e9)};

    for(auto u: st[state].next){
        auto v = solve(u.second);
        v.first++;

        ans = min(ans, v);
    
        // if(v.second == 0){
        //     cout << "transicionei com " << state << " -> " << char(u.first) << "\n";
        //     break;
        // }
    }

    return ans;
}

int main(){
    for(int i = 0 ; i < 2 * MAXLEN ; i++){
        dp[i] = {-1, -1};
    }

    string s;

    cin >> s;

    sa_init();

    for(auto c: s){
        sa_extend(c);
    }

    vector< pair< int, int > > v;

    for(int i = 0 ; i < sz; i++){
        v.push_back({st[i].len, i});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for(auto u: v){
        if(st[u.second].link > 0){
            st[st[u.second].link].cnt += st[u.second].cnt;
        }
    }

    auto r = solve(0);

    // assert(r.first > 0);

    // cout << r.first << " " << r.second << " " << sz << "\n";

    cout << s.substr(r.second - r.first + 1, r.first) << "\n";

    return 0;
}