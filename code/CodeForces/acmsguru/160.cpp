#include <bits/stdc++.h>

using namespace std;

const int N = int(1e4) + 10;
const int M = 1010;
int a[N];
int dp[N][M];
int n, m;

int solve(int i, int j){
    if(i >= n){
        return j;
    }

    int &ans = dp[i][j];

    if(ans != -1){
        return ans;
    }

    // assert(false);
    ans = 0;

    ans = max(solve(i + 1, j), solve(i + 1, (j * a[i]) % m));

    return ans;
}

vector< int > v;

void get(int i, int j){
    if(i >= n){
        return;
    }

    int &ans = dp[i][j];

    if(ans == solve(i + 1, (j * a[i]) % m)){
        v.push_back(i);
        get(i + 1, (j * a[i]) % m);
    }else{
        get(i + 1, j);
    }
}

int main(){
    memset(dp, -1, sizeof dp);

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < n ; i++){
        int ai;

        scanf("%d", &a[i]);
    }

    printf("%d\n", solve(0, 1));

    get(0, 1);

    // printf("%lu\n", v.size());

    for(auto u: v){
        printf("%d ", u + 1);
    }

    printf("\n");

    return 0;
}