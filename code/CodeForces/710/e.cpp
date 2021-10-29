#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int q[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &q[i]);
        }

        vector< int > mn, mx;
        set< int > smn, smx;

        for(int i = 1 ; i <= n ; i++){
            smn.insert(i);
            smx.insert(i);
        }

        for(int i = 1 ; i <= n ; i++){
            if(q[i] != q[i - 1]){
                mn.push_back(q[i]);
                mx.push_back(q[i]);
                smn.erase(q[i]);
                smx.erase(q[i]);
            }else{
                mn.push_back(*smn.begin());
                smn.erase(smn.begin());

                auto e = prev(smx.lower_bound(q[i - 1]));
                mx.push_back(*e);
                smx.erase(e);
            }
        }

        for(auto u: mn){
            printf("%d ", u);
        }
        printf("\n");
        for(auto u: mx){
            printf("%d ", u);
        }
        printf("\n");
    }

    return 0;
}