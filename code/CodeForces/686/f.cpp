#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int a[N];
vector< int > adj[N];
vector< int > con;
set< int > st;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
            con.push_back(a[i]);
        }

        sort(con.begin(), con.end());

        for(int i = 0 ; i < n ; i++){
            a[i] = lower_bound(con.begin(), con.end(), a[i]) - con.begin();
            adj[a[i]].push_back(i + 1);
        }

        sort(a, a + n, greater< int >());
        
        int l = n, r = 1;
        bool ok = false;

        for(int i = 0 ; i < n ; i++){
            int ai = a[i];
            
            if(adj[ai].size() >= 3){
                int len = int(adj[ai].size()) - 1;

                if(adj[ai][len] > r && adj[ai][0] < l){
                    int t = adj[ai][1];

                    l = min(l, t);
                    r = max(r, t);
                    ok = true;
                    break;
                }else{
                    l = min(l, *adj[ai].begin());
                    r = max(r, *adj[ai].rbegin());
                }
            }else{
                l = min(l, *adj[ai].begin());
                r = max(r, *adj[ai].rbegin());
            }
        }
        
        int x = l - 1;
        int y = (r - l) + 1;
        int z = n - (x + y);

        if(ok && x != 0 && z != 0){

            assert(l <= r);
            printf("YES\n");
            printf("%d %d %d\n", x, y, z);
        }else{
            printf("NO\n");
        }

        for(int i = 0 ; i < n ; i++){
            adj[a[i]].clear();
        }

        con.clear();
    }

    return 0;
}
