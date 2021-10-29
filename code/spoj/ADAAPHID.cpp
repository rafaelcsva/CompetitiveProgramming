#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

struct item {
    ll key, prior, ran;
    ll cnt;
    item * l, * r;
    item() { }
    item (ll key, ll prior, ll ran) : key(key), prior(prior), ran(ran), cnt(0LL), l(NULL), r(NULL) { }
};
typedef item * pitem;

ll cnt (pitem t) {
    return t ? t->cnt : 0LL;
}

void upd_cnt (pitem t) {
    if (t){
        t->cnt = t->ran + cnt(t->l) + cnt(t->r);
    }
}

void split (pitem t, ll key, pitem & l, pitem & r) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split (t->l, key, l, t->l),  r = t;
    else
        split (t->r, key, t->r, r),  l = t;
    upd_cnt(l);
    upd_cnt(r);
}

void insert (pitem & t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split (t, it->key, it->l, it->r), t = it;
    else
        insert (it->key < t->key ? t->l : t->r, it);
    upd_cnt(t);
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt(t);
}

void erase (pitem & t, ll key) {
    if (t->key == key) {
        pitem th = t;
        merge (t, t->l, t->r);
        delete th;
    }
    else
        erase (key < t->key ? t->l : t->r, key);
    upd_cnt(t);
}

pitem unite (pitem l, pitem r) {
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  swap (l, r);
    pitem lt, rt;
    split (r, l->key, lt, rt);
    l->l = unite (l->l, lt);
    l->r = unite (l->r, rt);
    upd_cnt(l);
    return l;
}

ll query(pitem t, ll x){
    if(t){
        // printf("path: %lld %lld %lld\n", t->key, t->prior, t->cnt);
        if(t->key > x){
            return query(t->l, x);
        }else{
            // printf("descendo para direita!\n");
            return t->cnt - cnt(t->r) + query(t->r, x);
        }
    }else{
        return 0LL;
    }
}

void print(pitem t){
    if(t){
        printf("path: %lld %lld %lld %lld\n", t->key, t->prior, t->cnt, t->ran);
        print(t->l);
        print(t->r);
    }
}

const int N = int(3e5) + 100;
pitem root = NULL;
ll l[N], r[N];

int main(){
    srand(time(NULL));
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%llu %llu", &l[i], &r[i]);
        if(i){
            l[i] ^= r[i - 1];
            r[i] ^= r[i - 1];
        }

        insert(root, new item(l[i], rand(), r[i]));
        r[i] = query(root, l[i]);
        assert(r[i] >= 0LL);
        assert(l[i] >= 0LL);
    }

    for(int i = 0 ; i < n ; i++){
        printf("%llu %llu\n", l[i], r[i]);
    }

    return 0;
}
