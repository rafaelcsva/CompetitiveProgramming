//05, 10, 2018, 10:54:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 18;
double dp[1 << N][N];
bool used[1 << N][N];
double p[N][N];
int n;

double solve(int mask, int cur){
    if((mask & 1) && cur != 0)
        return 0.0;

    if(mask == (1 << n) - 1){
        return cur == 0;
    }

    double &ans = dp[mask][cur];

    if(used[mask][cur]){
        return ans;
    }

    used[mask][cur] = true;

    int x = 0;

    if(__builtin_popcount(mask) == 1){
        x = cur + 1;
    }

    for(int i = x ; i < n ; i++){
        int e = 1 << i;

        if((mask & e) == 0){
            ans += solve(mask | e, i) * p[i][cur] + solve(mask | e, cur) * p[cur][i];
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%lf", &p[i][j]);
        }
    }

    double tot = 0.0;

    for(int i = 0 ; i < n ; i++){
        tot += solve(1 << i, i);
    }

    printf("%.7lf\n", tot);
    
    return 0;
}