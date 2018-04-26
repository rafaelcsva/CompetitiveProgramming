#include <bits/stdc++.h>

using namespace std;

typedef vector<int>     vi;
typedef map<vi, int>   mvii;
typedef pair<int, vi > pimp;
mvii dis;
priority_queue<pimp>pq;
vi u, v;
int mod = 20437;

bool isEqual(vi &a, vi &b){
    for(int i = 0 ; i < 8 ; i++){
        if(a[i] != b[i])
            return false;
    }

    return true;
}

int djikstra(){
    pq.push({0, u});
    dis[u] = 1;//  podia ser 0 mas, como os vértices serão "descobertos", 
                // para diferenciar inicio com 1 o valor do vértice que representa o estado inicial dos containers,
                // depois retiro essa diferença na resposta final

    while(!pq.empty()){
        vi a = pq.top().second;
        vi b = a;

        if(isEqual(a, v)){
            return dis[a];
        }

        pq.pop();
  
        for(int i = 0 ; i < 3 ; i++){
            int c = b[i] + b[i + 1];
            swap(b[i], b[i + 1]);
            //cout << "c = " << b[i] << " + " << b[i + 1] << endl;

            if(dis[b] == 0 || dis[b] > dis[a] + c){
                dis[b] = dis[a] + c;
                pq.push({-dis[b], b});
            }

            swap(b[i], b[i + 1]);
            
        }

        for(int i = 4 ; i < 7 ; i++){
            int c = b[i] + b[i + 1];
            swap(b[i], b[i + 1]);

            if(dis[b] == 0 || dis[b] > dis[a] + c){
                dis[b] = dis[a] + c;
                pq.push({-dis[b], b});
            }

            swap(b[i], b[i + 1]);
        }

        for(int i = 0 ; i < 4 ; i++){
            int c = b[i] + b[i + 4];
            swap(b[i], b[i + 4]);

            if(dis[b] == 0 || dis[b] > dis[a] + c){
                dis[b] = c + dis[a];
                pq.push({-dis[b], b});
            }

            swap(b[i], b[i + 4]);
        }
    }

    return dis[v];
}

int main (){
    for(int i = 0 ; i < 8 ; i++){
        int x;

        cin >> x;

        u.push_back(x);
    }

    for(int i = 0 ; i < 8 ; i++){
        int x;

        cin >> x;

        v.push_back(x);
    }

    cout << djikstra() - 1 << endl;//retiro 1 pois inicio o valor da distância para o vértice inicial com 1

    return 0;
}