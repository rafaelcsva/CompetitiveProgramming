#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
map< string, int > mp;
int perm[N], mt[N];
string s[N], t[N];
int marked[N];
int sz[N];
int cor[N];
vector< int > adj[N];
vector< int > topological_order;
bool ok = true;

void dfs(int u){
    for(int a: adj[u]){
        if(!marked[a]){
            marked[a] = true;
            dfs(a);
        }
    }

    topological_order.push_back(u);
}

bool check(int u){
    cor[u] = 1;

    for(int a: adj[u]){
        if(cor[a] == 1){
            return false;
        }else if(cor[a] == 0){
            if(!check(a)){
                return false;
            }
        }
    }

    cor[u] = 2;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
        mp[s[i]] = i;
    }

    for(int i = 0 ; i < m ; i++){
        cin >> t[i] >> mt[i];
        mt[i]--;
        vector< int > tmp;

        for(int m = 0 ; m < (1 << k) ; m++){
            string mtmp = t[i];

            for(int d = 0 ; d < k ; d++){
                int e = 1 << d;
                if(m & e){
                    mtmp[d] = '_';
                }
            }
            
            if(mp.count(mtmp) != 0){
                // cout << mtmp <<" " << mp[mtmp] << " " << mt[i] << endl;
                tmp.push_back(mp[mtmp]);
            }
        }
        int fnd = -1;
        for(int d = 0 ; d < tmp.size() ; d++){
            // printf("d = %d %d %d\n", tmp[i], mt[i]);
            if(tmp[d] == mt[i]){
                fnd = 1;
                break;
            }
        }

        if(fnd == -1){
            printf("NO\n");
            return 0;
        }

        for(int d = 0 ; d < tmp.size() ; d++){
            if(tmp[d] == mt[i]){
                continue;
            }

            adj[mt[i]].push_back(tmp[d]);
            // printf("%d-> %d\n", mt[i], tmp[d]);
            sz[tmp[d]]++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(!cor[i] && !check(i)){
            printf("NO\n");
            return 0;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(sz[i] == 0){
            dfs(i);
        }
    }
    reverse(topological_order.begin(), topological_order.end());

    if(topological_order.size() != n || !ok){
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for(auto u: topological_order){
        printf("%d ", u + 1);
    }

    printf("\n");

    return 0;
}
