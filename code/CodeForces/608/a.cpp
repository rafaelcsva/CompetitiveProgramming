#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int vis[N];

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        int n, m;

        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < n ; i++){
            int ai;

            scanf("%d", &ai);
            vis[ai] = test;
        }

        int ans = 0;

        for(int i = 0 ; i < m ; i++){
            int bi;

            scanf("%d", &bi);
            if(vis[bi] == test){
                ans++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}