#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int M = 1e4 + 10, N = 110;
double b, v, e, f;
int r;
double dp[M][N];
int used[M][N];
int test = 1;
int n;
int a[N];
int mark[M];
const double EPS = 1e-9;
const double inf = 1e9;

double solve(int pos, int lcheckpoint){
    if(pos == a[n]){
        return 0;
    }

    double &ans = dp[pos][lcheckpoint];

    if(used[pos][lcheckpoint] == test){
        return ans;
    }

    ans = inf;
    used[pos][lcheckpoint] = test;

    if(mark[pos]){
        ans = solve(pos + 1, mark[pos]) + 1.0 / double(v - f * r) + b;
    }

    int x = pos - a[lcheckpoint];
    double cost;

    if(x >= r){
        cost = 1.0 / double(v - e * (x - r));
    }else{
        cost = 1.0 / double(v - f * (r - x));
    }

    double r = solve(pos + 1, lcheckpoint) + cost;

    if(ans - r > EPS){
        ans = r;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(scanf("%d", &n) != EOF){
        if(n == 0)
            break;

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);
            mark[a[i]] = i;
        }

        scanf("%lf", &b);
        scanf("%d %lf %lf %lf", &r, &v, &e, &f);

        printf("%.4lf\n", solve(0, 0));

        test++;

        memset(mark, 0, sizeof mark);
    }

    return 0;   
}