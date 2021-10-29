#include <bits/stdc++.h>

using namespace std;

typedef pair< pair< int, int >, pair< multiset< int >, int > > node;

const int N = int(1e5) + 10;
vector< node > v;
int a[N];
int op = 0;

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
        v.push_back({{i, i}, {{a[i]}, 1}});
        op++;
    }

    int k = 1;

    while(k <= n){
        int l = -1;

        for(int i = 0 ; i < v.size() ; i++){
            if(l >= n){
                int r = int(v.size()) - i;
                while(r){
                    // printf("aqui!!\n");
                    v.pop_back();
                    r--;
                    op++;
                }
                break;
            }else{
                int &st = v[i].first.first;
                int &en = v[i].first.second;

                auto &r = v[i].second.first;
                int &sz = v[i].second.second;

                if(l > en){
                    r.clear();
                    st = en = l;
                    r.insert(a[l]);
                    op++;
                    sz = 1;
                }else{
                    for(int d = st ; d < l ; d++){
                        op += log2(r.size()) * 2;
                        r.erase(r.find(a[d]));
                        op += log2(r.size());
                        if(r.count(a[d]) == 0){
                            sz--;
                        }
                    }
                    st = max(l, st);
                }

                en++;
                while(en < n){
                    op += log2(r.size()) * 2;
                    r.insert(a[en]);
                    if(r.count(a[en]) == 1){
                        sz++;
                    }

                    if(sz > k){
                        op += log2(r.size());
                        // printf("erase@ %lu %d!\n", r.size(), k);
                        r.erase(a[en]);
                        sz--;
                        // printf("erase@ %lu %d!\n", r.size(), k);
                        break;
                    }

                    en++;
                }

                // printf("en: %d %d %d (%d)\n", en, sz, k, l);
                l = en;
                en--;
            }
        }

        printf("%lu ", v.size());
        // break;
        k++;
    }
    printf("\n");
    printf("op: %d\n", op);

    return 0;
}