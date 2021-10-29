#include <bits/stdc++.h>
 
using namespace std;
 
const int N = int(3e5) + 100;
int x[N];
int cost[N];
 
int test(int i, int n){
    vector< int > v;
 
    for(int j = 0 ; j < n ; j++){
        int e = (j - i + n) % n;
    
        v.push_back(e);
    }
 
    int cost = 0;
    for(int i = 0 ; i < v.size() ; i++){
        while(x[v[i]] != i){
            swap(v[i], v[x[v[i]]]);
            cost++;
        }
    }
 
    return cost;
}
 
int main(){
    int t;
 
    scanf("%d", &t);
 
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
 
        for(int i = 0 ; i < n ; i++){
            int pi;
 
            scanf("%d", &pi);
            pi--;
 
            x[pi] = i;
            cost[i] = n;
        }
 
        for(int i = 0 ; i < n ; i++){
            int o = -1;
 
            if(x[i] < i){
                o = n - i + x[i];
            }else{
                o = x[i] - i;
            }
 
            // printf("%d matches on %d\n", i + 1, o);
            cost[o]--;
        }
 
        vector< int > ans;
 
        for(int i = 0 ; i < n ; i++){
            // if(i == 3){
            //     printf("%d\n", cost[i]);
            // }
            if((cost[i] + 1) / 2 <= m){
                // printf("test %d\n", i);
                if(test(i, n) <= m){
                    ans.push_back(i);
                }
            }
        }
 
        printf("%lu", ans.size());
 
        for(auto u: ans){
            printf(" %d", u);
        }
        printf("\n");
    }
 
    return 0;
}