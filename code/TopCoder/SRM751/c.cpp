//21, 02, 2019, 23:48:01 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 100;
int color[N];
int deg[N];
int target[N];

void dfs(int u, vector< string > &a){
    int n = a.size();
    color[u] = 1;

    for(int i = 0 ; i < n ; i++){
        if(a[u][i] == '1'){
            if(deg[i] != target[i] && deg[u] != target[u]){
                deg[i]--;
                deg[u]--;
                a[u][i] = '0';
                a[i][u] = '0';
            }

            if(!color[i]){
                dfs(i, a);
            }
        }
    }
}

class HalfGraph{
    public:
    vector< string > compute(vector< string > a){
        int n = a.size();

        int tot_deg = 0;
        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cnt += (a[i][j] == '1');
            }
            tot_deg += cnt;
            deg[i] = cnt;   
            target[i] = cnt / 2;

            if(cnt & 1){
                return {};
            }

            cnt = 0;
        }

        if((tot_deg & 1) || ((tot_deg / 2) & 1)){
            return {};
        }

        for(int i = 0 ; i < n ; i++){
            if(!color[i]){
                dfs(i, a);
            }
        }

        return a;
    }
};
