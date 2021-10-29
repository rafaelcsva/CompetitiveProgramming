#include <bits/stdc++.h>

using namespace std;

struct state {
    int len, link;
    int cnt = 0;
    map< int, int > next;
};

const int MAXLEN = int(1e7 + 3e6);
state st[MAXLEN * 2];
const int N = int(5e5) + 10;
int pos[N];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(int c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    pos[st[cur].len] = cur;
    st[cur].cnt = 1;

    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int mark[30];
int mark1[30];
int p[N];

int main(){
    memset(mark, -1, sizeof mark);
    memset(mark1, -1, sizeof mark1);

    string s;
    int n;

    cin >> s >> n;

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &p[i]);
    }

    for(int i = n - 1 ; i >= 0 ; i--){
        int pi = p[i];

        if(mark1[p[i]] != -1){
            p[i] = mark1[p[i]] - i;
        }else{
            p[i] = -1;
        }

        mark1[pi] = i;
    }

    printf("P: ");
    for(int i = 0 ; i < n ; i++){
        printf("%d ", p[i]);
    }
    printf("\n");

    sa_init();

    vector< int > vs;

    for(int i = 0 ; i < s.length() ; i++){
        int xi = s[i] - 'a';

        if(mark[xi] != -1){
            last = pos[mark[xi]];
            vs[mark[xi]] = i - mark[xi];

            for(int j = mark[xi] ; j < i ; j++){
                sa_extend(vs[j]);
            }
        }
        sa_extend(-1);
        mark[xi] = i;
        vs.push_back(-1);
        for(auto u: vs){
            printf("%d ", u);
        }
        printf("\n");
    }

    vector< pair< int, int > > ostates;

    for(int i = 0 ; i < sz ; i++){
        ostates.push_back({st[i].len, i});
    }

    sort(ostates.begin(), ostates.end(), greater< pair< int, int > >());

    for(auto u: ostates){
        if(st[u.second].link > 0){
            st[st[u.second].link].cnt += st[u.second].cnt;
        }
    }

    int cur = 0;

    for(int i = 0 ;i < n ; i++){
        if(st[cur].next.count(p[i]) == 0){
            printf("0\n");
            return 0;
        }
        cur = st[cur].next[p[i]];
    }

    printf("%d\n", st[cur].cnt);

    return 0;
}