//01, 11, 2018, 18:15:55 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 17, M = 30;
pii p[N];
double dp[1 << N];
int used[1 << N];
char name[M];
int n;
int test = 1;
const double inf = 1e9, EPS = 1e-9;

double dist(int i, int j){
    return hypot(p[i].first - p[j].first, p[i].second - p[j].second);
}

double solve(int mask){
    if(mask == (1 << n) - 1){
        return 0;
    }

    if(used[mask] == test){
        return dp[mask];
    }

    used[mask] = test;
    dp[mask] = inf;

    bool ok = false;

    for(int i = 0 ; i < n ; i++){
        if(mask & (1 << i)){
            continue;
        }

        for(int j = 0 ; j < n ; j++){
            if(i == j)
                continue;

            if(mask & (1 << j)){
                continue;
            }

            double dis = dist(i, j);

            double d = dis + solve(mask | (1 << i) | (1 << j));

            if(dp[mask] - d > EPS){
                dp[mask] = d;
            }
        }
    }

    return dp[mask];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        scanf("%d", &n);

        if(n == 0)
            break;

        n *= 2;

        for(int i = 0 ; i < n ; i++){
            scanf("\n%s %d %d", name, &p[i].first, &p[i].second);
        }

        printf("Case %d: %.2lf\n", test, solve(0));

        test++;
    }
    
    return 0;
}