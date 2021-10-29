#include <bits/stdc++.h>

using namespace std;

struct state {
    int len, link, firstpos;
    map< char, int > next;
};

const int MAXLEN = 100100;
state st[MAXLEN * 2], st1[MAXLEN * 2];
int sz, last;

void sa_init(state st[]) {
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
}

void sa_extend(char c, state st[]){
    int cur = sz++;
    st[cur].len = st[last].len + 1;
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
            st[clone].firstpos = st[q].firstpos;
            while(p != -1 && st[p].next[c] == q){
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    int n;

    cin >> n;

    sa_init(st);

    for(int i = 0 ; i < s.length() ; i++){
        sa_extend(s[i], st);
    }

    reverse(s.begin(), s.end());

    sa_init(st1);
    for(int i = 0 ; i < s.length() ; i++){
        sa_extend(s[i], st1);
    }

    reverse(s.begin(), s.end());

    int cnt = 0;
    int len = int(s.length());
    for(int d = 0 ; d < n ; d++){
        string si;

        cin >> si;
        int m = int(si.length());
        if(m == 1) continue;

        stack< int > stk;

        int f1 = 0;
        int i;

        for(i = 0 ; i < m ; i++){
            if(st[f1].next.count(si[i]) == 0){
                // cout << "fim em " << i << endl;
                break;
            }

            f1 = st[f1].next[si[i]];
            // cout << "f " << st[f1].firstpos << " " << f1 << endl;
            stk.push(st[f1].firstpos);
        }

        int last = 0;
        int f2 = 0;
        int mpos = len + 1;
        bool ver = true;

        for(int k = m - 1 ; k >= i ; k--){
            if(st1[f2].next.count(si[k]) == 0){
                // cout << "nao tem " << f2 <<" " << si[k] << endl;
                ver = false;
                break;
            }

            f2 = st1[f2].next[si[k]];
            mpos = len - st1[f2].firstpos - 1;
            // cout << mpos << " " << st1[f2].firstpos << " " << si[k] << endl;
        }

        if(!ver){
            continue;
        }

        while(mpos <= stk.top()){
            stk.pop();

            i--;
            if(st1[f2].next.count(si[i]) == 0){
                ver = false;
                break;
            }

            f2 = st1[f2].next[si[i]];
            mpos = len - st1[f2].firstpos - 1;
        }

        // cout << si << " " << mpos << " " << stk.top() << endl;
        if(ver){
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
