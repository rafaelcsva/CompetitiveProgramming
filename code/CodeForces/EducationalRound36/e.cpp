#include <bits/stdc++.h>

using namespace std;

class Block {
public:
    int len;
    int tim;
    int up;
};

class Elem {
    public:
    int len;
    int tim = 0;
    int up = 2;
};

const int N = int(3e5);
const int SQ = 548;
Block b[SQ];
Elem a[N];
int l[N], r[N], k[N];
vector< int > v;
int gtim;

void update(Elem &e, int pos, int u){
    int block = pos / SQ;

    if(e.tim < b[block].tim){
        e.up = b[block].up;
    }

    e.tim = ++gtim;
    if(e.up != u){
        if(e.up & 1){
            b[block].len += e.len;
        }else{
            b[block].len -= e.len;
        }
        e.up = u;
    }
}

void update_block(int block, int u){
    b[block].u = u;
    b[block].tim = ++gtim;

    if(u == 1){
        sq[block].len = 0;
    }else{
        sq[block].len = sq[block].tlen;
    }
}

int query(int l, int r){
    int sum = 0;
    for(int i = l ; i <= r ; ){
        if(i % SQ == 0 && i + SQ - 1 <= r){
            sum += b[i / SQ].len;
            i += SQ;
        }else{
            sum += a[i].up == 2 ? a[i].len : 0;
            ++i;
        }
    }
}

int update(int l, int r, int u){
    int sum = 0;
    for(int i = l ; i <= r ; ){
        if(i % SQ == 0 && i + SQ - 1 <= r){
            update_block(i / SQ, u);
            sum += b[i / SQ].len;
            i += SQ;
        }else{
            sum += a[i].up == 2 ? a[i].len : 0;
            ++i;
        }
    }
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);

    for(int i = 0 ; i < q ; i++){
        scanf("%d %d %d", &l[i], &r[i], &k[i]);
        v.push_back(l[i]);
        v.push_back(r[i]);
    }

    v.push_back(n + 1);
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.resize(it - v.begin());

    for(int i = 0 ; i < int(v.size()) - 1 ; i++){
        a[i].len = v[i + 1] - v[i];
        b[i / SQ].len += a[i].len;
    }

    return 0;
}