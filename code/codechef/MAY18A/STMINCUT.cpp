//09, 05, 2018, 20:45:13 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef pair<int, pii>pipii;
priority_queue<pipii>pq;
const int N = 1010;
int pai[N];
ll t[N][N];
ll w[N];
int n;

int find(int x){
    if(pai[x] == x){
        return x;
    }

    return pai[x] = find(pai[x]);
}

void join(int u, int v){
    int x = find(u), y = find(v);

    if(x != y){
        if(x > y){
            pai[x] = y;
        }else{
            pai[y] = x;
        }
    }
}

void corrige(ll &cost, int flag = 0){
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(t[i][j] != t[j][i]){
                cost += abs(t[i][j] - t[j][i]);

                if(t[i][j] > t[j][i]){
                    t[j][i] = t[i][j];    
                }else{
                    t[i][j] = t[j][i];
                }
            }

            if(flag)
                pq.push({t[i][j], {i, j}});
        }
    }
}

int main(){
    int T;

    cin >> T;

    while(T--){
        cin >> n;

        memset(w, -1, sizeof w);

        for(int i = 0 ; i < n ; i++){
            pai[i] = i;
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> t[i][j];
            }
        }

        ll cost = 0LL;

        corrige(cost, 1);

        while(!pq.empty()){
            pipii r = pq.top();
            pq.pop();

            ll weight = r.first;

            if(weight == 0){
                continue;
            }
            
            int u = r.second.first;
            int v = r.second.second;
            int x = find(u), y = find(v);
            cout << u << ' ' << v << endl;
            
            if(x != y){

                for(int i = 0 ; i < n ; i++){
                    int pesq = find(i);

                    if(pesq == x){
                        cout << u << ' ' << v << ' ' << t[u][v] << ' ' << weight << endl;
                        t[u][v] = weight;
                    }
                }

                join(u, v);
            }
        }

        corrige(cost);

        cout << cost << endl;
    }

    return 0;
}