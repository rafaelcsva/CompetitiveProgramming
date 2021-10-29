#include <bits/stdc++.h>
 
using namespace std;
 
struct item {
    int key, prior;
    bool rev;
    int cnt;
    item * l, * r;
    item() { }
    item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL), rev(false),
    cnt(0) { }
};
typedef item * pitem;
 
typedef struct item * pitem;
 
int cnt (pitem it) {
    return it ? it->cnt : 0;
}
 
void upd_cnt (pitem it) {
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
}
 
void push (pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}
 
void erase (pitem & t, int pos, int add = 0) {
    push (t);
    int cur_key = cnt(t->l) + add;
 
    if (cur_key == pos) {
        pitem th = t;
        merge (t, t->l, t->r);
        delete th;
    }
    else{
        if(pos < cur_key){
            erase(t->l, pos, add);
        }else{
            erase(t->r, pos, cur_key + 1);
        }
    }
}
 
pitem search_item(pitem &t, int pos, int add = 0){
    push (t);
    if(!t){
        return NULL;
    }
 
    int cur_key = cnt(t->l);
    // printf("%d %d\n", cur_key + add, pos);
    assert(t != NULL);
 
    if (cur_key + add == pos) {
        return t;
    }
    else{
        if(pos < cur_key + add){
            return search_item(t->l, pos, add);
        }else{
            return search_item(t->r, pos, add + cur_key + 1);
        }
    }
}
 
void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}
 
void reverse (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}
 
void insert (pitem &t, pitem new_item, int pos) {
    push (t);
    pitem t1, t2;
    split(t, t1, t2, pos);
    merge(t1, t1, new_item);
    merge(t, t1, t2);
}
 
const int N = int(2e5) + 10;
int a[N];
pitem root = NULL;
bool mark[N];
 
void output (pitem t, int idx = 0) {
    if (!t)  return;
 
    push (t);
    int cur_key = cnt(t->l);
 
    output (t->l, idx);
 
    a[cur_key + idx] = t->key;
    // printf ("%d(%d) ", t->key, cur_key + idx);
 
    output (t->r, idx + cur_key + 1);
}
 
int main(){
    srand(time(NULL));
    int n, q, m;
 
    scanf("%d %d %d", &n, &q, &m);
 
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
        insert(root, new item(a[i], rand()<<15+rand()), i);
    }
    output(root);
    for(int i = 0 ; i < q ; i++){
        int t, l, r;
 
        scanf("%d %d %d", &t, &l, &r);
        l--, r--;
 
        if(t == 2){
            reverse(root, l, r);
        }else{
            vector< int > inds;
            for(int i = 0 ; i < n ; i++){
                auto r = search_item(root, i);
                if(r == NULL){
                    inds.push_back(i);
                }
            }
            if(inds.size()){
                for(auto u: inds){
                    printf("-> %d ", u);
                }
 
                assert(false);
            }
            auto el = search_item(root, r);
            // printf("%d\n", el->key);
            // fflush(stdout);
            insert(root, new item(el->key, rand()<<15+rand()), l);
            // printf("inseri!\n");
            // fflush(stdout);
            erase(root, r + 1);
        }
 
        assert(root != NULL);
        // output(root);
    }
 
    output(root);
    for(int i = 0 ; i < m ; i++){
        int bi;
 
        scanf("%d", &bi);
        bi--;
        printf("%d ", a[bi]);
    }
    printf("\n");
 
    return 0;
}