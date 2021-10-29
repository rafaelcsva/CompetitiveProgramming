#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int w[N], v[N], x[N];
vector< pair< int, int > > con;

int main(){
    int n, m, q;

    scanf("%d %d %d", &n, &m, &q);

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d", &w[i], &v[i]);

        con.push_back({v[i], -w[i]});
    }

    sort(con.begin(), con.end());

    reverse(con.begin(), con.end());

    for(int i = 0 ; i < m ; i++){
        scanf("%d", &x[i]);
    }

    while(q--){
        int l, r;

        scanf("%d %d", &l, &r);
        l--, r--;

        multiset< int > mst;
        for(int i = 0 ; i < m ; i++){
            if(i == l){
                i = r;
                continue;
            }else{
                mst.insert(x[i]);
            }
        }

        int sum = 0;
        for(auto u: con){
            int w = -u.second;

            auto v = mst.lower_bound(w);

            if(v != mst.end()){
                mst.erase(v);
                sum += u.first;
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}