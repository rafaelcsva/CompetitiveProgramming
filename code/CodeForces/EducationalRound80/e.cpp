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

using namespace std;

const int N = int(3e5);
int tm[N];
int mn[N];
int mx[N];
int cur[N];

ordered_set tims;

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1 ; i <= n ; i++){
        cur[i] = i;
        tims.insert(i);
        mn[i] = mx[i] = i;
    }

    int ctim = 1;

    for(int i = 0 ; i < m ; i++){
        int xi;

        scanf("%d", &xi);

        int o = tims.order_of_key(cur[xi]);

        mx[xi] = max(mx[xi], o + 1);

        tims.erase(cur[xi]);
    
        mn[xi] = 1;

        cur[xi] = -(ctim++);
        tims.insert(cur[xi]);
    }

    for(int i = 1 ; i <= n ; i++){
        int xi = i;

        int o = tims.order_of_key(cur[xi]);

        mx[xi] = max(mx[xi], o + 1);
        printf("%d %d\n", mn[xi], mx[xi]);
    }


    return 0;
}