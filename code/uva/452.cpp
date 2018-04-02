#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int adj[N][N];
string s;
int cor[N];
vector<int>top_sort;
int dis[N], p[N];

void dfs1(int x){
    cor[x] = 1;

    for(int i = 0 ; i < N ; i++){
        if(adj[x][i]){
            if(cor[i] == 0){
                dfs1(i);
            }
        }
    }

    top_sort.push_back(x);
}

int main (){
    int t;

    scanf("%d", &t);
    
    cin.ignore();
    cin.ignore();

    while(t--){
        memset(adj, 0, sizeof adj);
        memset(cor, 0, sizeof cor);
        memset(dis, 0, sizeof dis);
        memset(p, 0, sizeof p);

        while(getline(cin, s) && s.length()){
            int u = s[0] - 'A';
            int d = 0;
            int i = 2;

            while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
                d = d * 10 + s[i] - '0';
                i++;
            }

            p[u] = d;

            for(i = i + 1 ; i < s.length() ; i++){
                
                int v = s[i] - 'A';
                // cout << char(u + 'A') << ' ' << v << ' ' << ' ' << s[i] << endl;
                
                adj[v][u] = 1;
            }
        }
       
        for(int i = 0 ; i < N ; i++){
            if(cor[i] == 0 && p[i] != 0){
                // printf("%d %d\n", i, p[i]);
                dfs1(i);
            }
        }

        int r = 0;

        for(int i = top_sort.size() - 1 ; i >= 0 ; i--){
            int u = top_sort[i];
            // printf("%c ", char(u + 'A'));
            
            for(int k = 0 ; k < N ; k++){
                if(adj[u][k]){
                    dis[k] = max(dis[k], dis[u] + p[u]);
                }
            }
        }

        for(int i = top_sort.size() - 1 ; i >= 0 ; i--){
            int u = top_sort[i];

            r = max(r, dis[u] + p[u]);
        }
        // printf("\n");

        cout << r << endl;

        if(t != 0){
            cout << endl;
        }
        
        top_sort.clear();
    }

    return 0;
}