#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

struct state {
    int len, link;
    ll sz = 0LL;
    map< char, int > next, mo;
};

const int MAXLEN = 1000010;
state st[MAXLEN * 2];
int sz, last;
bool is_cloned[MAXLEN * 2];
int mark[MAXLEN * 2];

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(char c){
    int cur = sz++;
    st[cur].len = st[last].len + 1;
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

            is_cloned[clone] = true;
        
            while(p != -1 && st[p].next[c] == q){
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }

    last = cur;
}

void compute_sizes(){
    vector< pair< int, int > > ve;

    for(int i = 1 ; i < sz ; i++){
        ve.push_back({st[i].len, i});
    
        if(!is_cloned[i]){
            st[i].sz = 1LL;
        }else{
            st[i].sz = 0LL;
        }
    } 

    sort(ve.begin(), ve.end(), greater< pair< int, int > >());

    for(auto uu: ve){
        int u = uu.second;

        if(st[u].link > 0){
            st[st[u].link].sz += st[u].sz;
        }
    }
}

int go(int state, char c){
    if(st[state].next.count(c) != 0){
        return st[state].mo[c] = state;
    }

    if(state == 0){
        return st[state].next[c] = -1;
    }

    return st[state].mo[c] = go(st[state].link, c);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    sa_init();

    for(auto u: s){
        sa_extend(u);
    }

    compute_sizes();

    // for(int i = 0 ; i < sz ; i++){
    //     cout << "printing state s" << i << endl;

    //     for(auto u: st[i].next){
    //         cout << u.first << " -> " << u.second << endl;
    //     }

    //     cout << "link to " << st[i].link;

    //     cout << "\n----------\n\n";
    // }
    int q;

    cin >> q;
    int test = 1;

    while(q--){
        string qi;

        cin >> qi;

        qi = qi + qi;
        int m = (int)qi.length();

        ll ans = 0LL;

        int cur_state = 0;
        int cur_sz = 0;
        for(int i = 0 ; i < m - 1 ; i++){
            cur_state = go(cur_state, qi[i]);

            if(cur_state == -1){
                break;
            }

            cur_sz = min(cur_sz, st[cur_state].len) + 1;
            cur_state = st[cur_state].next[qi[i]];

            if(cur_state == -1){
                break;
            }

            // cout << cur_state << " has len = " << st[cur_state].len << endl;
            while(cur_sz >= m / 2 && st[cur_state].link != -1 && st[st[cur_state].link].len >= m / 2){
                cur_state = st[cur_state].link;
                cur_sz = st[cur_state].len;
            }
    
            if(cur_sz >= m / 2 && mark[cur_state] != test){
                // cout << "On state " << cur_state << " adds " << st[cur_state].sz << " " << qi.substr(0, i + 1) << " " << cur_sz << endl;
                mark[cur_state] = test;
                ans += st[cur_state].sz;
            }
        }

        cout << ans << "\n";
        test++;
    }

    return 0;
}