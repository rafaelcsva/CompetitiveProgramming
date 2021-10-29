#include <bits/stdc++.h>

using namespace std;

double dp[5001][51][500];
bool vis[5001][51][500];
int m;
int r;
int n;
int t[52];
int d[52];
double p[52];

double solve(int i, int tim, int reset){
    if(reset == 500){
        return 0.0;
    }

    if(i == m && tim < r){
        // printf("cheguei com %d\n", tim);
        return tim;
    }

    bool &v = vis[i][tim][reset];
    auto &ans = dp[i][tim][reset];

    if(v){
        return ans;
    }

    v = true;

    if(tim + t[i + 1] - t[i] >= r){
        return ans = t[0] + solve(0, t[0], reset + 1);
    }

    return ans = p[i] * ((t[i + 1] - t[i]) + solve(i + 1, tim + t[i + 1] - t[i], reset))
        + (1.0 - p[i]) * (d[i] + solve(i, tim + d[i], reset));
}

int main(){
    scanf("%d %d %d", &n, &r, &m);

    for(int i = 0 ; i < m ; i++){
        scanf("%d %lf %d", &t[i], &p[i], &d[i]);
    }

    t[m] = n;

    printf("%lf\n", t[0] + solve(0, t[0], 0));

    return 0;
}