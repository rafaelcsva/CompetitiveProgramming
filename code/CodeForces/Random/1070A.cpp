//24, 10, 2018, 10:54:46 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef pair< int, pii >    pipii;
const int N = 1010, S = 1010;
int dis[N][S];
int n, s;
int father_t[N][S];
vector< int > num;
pii father[N][S];
const int inf = 1e9;
const int D = 10;
queue< pii > pq;

void bfs(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < S ; j++){
            dis[i][j] = inf;
        }
    }

    // printf("n: %d\n", n);

    for(int d = 1 ; d < D ; d++){
        pq.push({d % n, d});
        dis[d % n][d] = 0;
    }

    vector< pipii > layer_tmp;

    while(!pq.empty()){
        pii u = pq.front();
        pq.pop();

        for(int d = 0 ; d < D ; d++){
            int nxt = (u.first * 10 + d) % n;
            int sum = (u.second + d);

            if(sum >= S){
                break;
            }
            // if(sum == s){
            //         printf("sum: %d %d\n", u.first, d);
            //     }
            if(dis[nxt][sum] > dis[u.first][u.second] + 1){
                father[nxt][sum] = {u.first, u.second};
                father_t[nxt][sum] = d;

                dis[nxt][sum] = dis[u.first][u.second] + 1;

                pq.push({nxt, sum});
            }
        }

        // if(pq.empty()){
        //     sort(layer_tmp.begin(), layer_tmp.end());

        //     for(int i = 0 ; i < layer_tmp.size() ; i++){
        //         pii u = layer_tmp[i].second;

        //         pq.push({u.first, u.second});
        //     }

        //     layer_tmp.clear();
        // }
    }
}

void print(){
    if(dis[0][s] != inf){
        pii cur = {0, s};

        for(int sz = dis[0][s] ; sz > 0 ; sz--){
            num.push_back(father_t[cur.first][cur.second]);

            cur = father[cur.first][cur.second];
        }

        num.push_back(cur.second);

        reverse(num.begin(), num.end());

        for(int i = 0 ; i < num.size() ; i++){
            printf("%d", num[i]);
        }

        printf("\n");

        num.clear();
    }else{
        printf("-1\n");
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        s = n;

        bfs();
        print();
    }

    return 0;
}