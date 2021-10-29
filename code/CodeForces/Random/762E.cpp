#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

typedef long long       ll;
typedef pair< int, int >    pii;
const int N = int(1e5) + 10;
int x[N], r[N], f[N];
int ind[N];
priority_queue< pii > pq;
ordered_set sts[N];
ll cnt = 0LL;

bool compar(int i, int j){
    return x[i] < x[j];
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d %d", &x[i], &r[i], &f[i]);
        ind[i] = i;
    }

    sort(ind, ind + n, compar);

    for(int ii = 0 ; ii < n ; ii++){
        int i = ind[ii];
        while(!pq.empty()){
            auto u = pq.top();
            if(-u.first >= x[i]){
                break;
            }
            pq.pop();
            // printf("sai %d\n", u.second);
            sts[f[u.second]].erase(x[u.second]);
        }

        for(int d = -k ; d <= k ; d++){
            int fi = f[i] + d;

            if(fi >= 1){
                cnt += sts[fi].size() - sts[fi].order_of_key(x[i] - r[i]); 
            }
        }

        // printf("%d adds %lld %lu %lu\n", i, tmp, sts[4].size(), pq.size() ? -pq.top().first : 0);

        sts[f[i]].insert(x[i]);
        pq.push({-(x[i] + r[i]), i});
    }

    printf("%lld\n", cnt);

    return 0;
}
