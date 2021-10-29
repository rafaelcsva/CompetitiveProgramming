#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int mark[N];
int sol[N];
int v[N];
int n;

int vis(int i, int d){
    int mx = d;
    int ans = 1;
    for(int j = i - 1 ; j >= 0 ; j--){
        if(sol[j] > mx){
            ans++;
            mx = sol[j];
        }
    }

    return ans;
}

int solve(int i){
    if(i == n){
        return 1;
    }

    int ans = 0;

    for(int d = 0 ; d < n ; d++){
        if(!mark[d]){
            if(vis(i, d) == v[i]){
                mark[d] = 1;
                sol[i] = d;
                ans += solve(i + 1);
                mark[d] = 0;
                sol[i] = 0;
            }
        }
    }

    return ans;
}

int main(){
    int t;
    int test = 1;

    scanf("%d", &t);

    while(t--){

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &v[i]);
        }

        printf("Case #%d: %d\n", test++, solve(0));
    }

    return 0;
}