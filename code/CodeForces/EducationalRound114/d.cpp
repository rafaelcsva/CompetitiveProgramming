#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

typedef pair< vector< int >, int >  pvi;
typedef pair< int, pvi >    pii;

const int N = 11;
const int D = 5;
vector< ll > con[N];
map< vector< int >, bool > mark;

int main(){
    int n;

    scanf("%d", &n);

    ll sum = 0LL;
    vector< int > init;

    for(int i = 0 ; i < n ; i++){
        int ci;

        scanf("%d", &ci);

        for(int j = 0 ; j < ci ; j++){
            ll xi;

            scanf("%lld", &xi);

            con[i].push_back(xi);
        }

        init.push_back(ci - 1);

        sum += con[i][int(con[i].size()) - 1];
    }

    int m;

    scanf("%d", &m);

    for(int i = 0 ; i < m ; i++){
        vector< int > v;

        for(int j = 0 ; j < n ; j++){
            int bi;

            scanf("%d", &bi);

            v.push_back(bi - 1);
        }

        mark[v] = true;
    }
    
    priority_queue< pii > pq;
    vector< int > ans;

    pq.push({sum, {init, 0}});

    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();

        if(mark.count(u.second.first) == 0){
            // printf("aqui\n");
            ans = u.second.first;
            break;
        }

        for(int i = u.second.second; i < n ; i++){
            if(u.second.first[i] == 0){
                continue;
            }

            u.second.first[i]--;
            ll tsum = (u.first - con[i][u.second.first[i] + 1] + con[i][u.second.first[i]]);
            pq.push({tsum, {u.second.first, i}});
            u.second.first[i]++;
        }
    }

    for(auto u: ans){
        printf("%d ", u + 1);
    }

    printf("\n");

    return 0;
}
