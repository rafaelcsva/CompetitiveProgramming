//01, 06, 2018, 20:28:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<int, pipii> wtf;
typedef long double ld;
typedef long long ll;
map<pipii, int>dis;//cor e vertice
map<pipii, bool>vis;
priority_queue<wtf>pq;
int n, m;
const int N = int(2e3 + 10);
int vi[] = {0, 0, -1, 1}, vj[] = {1, -1, 0, 0};
int tab[N][N];
int it = 0;

bool ok(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

int dijkstra(){
    vis[{-1, {0, 0}}] = true;
    dis[{-1, {0, 0}}] = 1;
    pq.push({1, {-1, {0, 0}}});
    int ans = 1;

    while(!pq.empty()){
        wtf r = pq.top();
        pq.pop();
       
        pii u = r.second.second;
        int color = r.second.first;
        
        cout << u.first << ' ' << u.second << ' ' << color << " " << r.first << endl;
        ans = max(ans, r.first);

        for(int i = 0 ; i < 4 ; i++){
            int ti = u.first + vi[i], tj = u.second + vj[i];

            if(ok(ti, tj)){
                if(tab[ti][tj] == tab[u.first][u.second]){//se ele tem a mesma cor que u
                    pipii v = {color, {ti, tj}};

                    if(!vis[v]){
                        vis[v] = true;
                        dis[v] = dis[r.second] + 1;
                        pq.push({dis[v], v});
                    }

                }else if(tab[ti][tj] == color || color == -1){//se a segunda cor é igual a esse vértice
                    pipii v = {tab[u.first][u.second], {ti, tj}};//coloco um vértice adicionando a outra cor (u) no estado
                    
                    if(!vis[v]){
                        vis[v] = true;
                        dis[v] = dis[r.second] + 1;
                        pq.push({dis[v], v});
                    }
                }

                pipii v = {-1, {ti, tj}};

                if(!vis[v]){
                    vis[v] = true;
                    dis[v] = 1;
                    pq.push({dis[v], v});
                }
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> tab[i][j];
        }
    }
    
    cout << "here" << endl;
    cout << dijkstra() << endl;
    
    return 0;
}