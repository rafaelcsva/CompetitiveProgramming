#include <bits/stdc++.h>

using namespace std;

const int N = 100;
const double eps = 1e-9;

int used[N][N];
double dp[N][N];
double c, m, p, v;
int test = 1;

double solve(int i, int j){
    int &us = used[i][j];
    double &ans = dp[i][j];

    if(us == test){
        return ans;
    }

    ans = 0.0;
    us = test;
    double pc = c + ((j - 2 * i) * v) / 2.0;
    double pm = m + ((i - 2 * j) * v) / 2.0;
    double pp = p + (((i + j) * v) / 2.0);

    if(pc < eps){
        pm -= v / 2.0;
        pp -= v / 2.0;

        pc += v;
        pm += pc / 2.0;
        pp += pc / 2.0;

        double prob = 1.0;
        int day = 1;

        while(pm > eps){
            ans += prob * pp * day;
            day++;
            prob *= pm;
            pm -= v;
            pp += v;
        }

        ans += prob * day;
    }else if(pm < eps){
        pc -= v / 2.0;
        pp -= v / 2.0;

        pm += v;
        pc += pm / 2.0;
        pp += pm / 2.0;

        double prob = 1.0;
        int day = 1;

        while(pc > eps){
            ans += prob * pp * day;
            day++;
            prob *= pc;
            pc -= v;
            pp += v;
        }

        ans += prob * day;
        // printf("%d %d gives %d %lf %lf\n",i,j, day, prob, pc + day * v - v);
    }else{
        ans = 1.0 + pc * solve(i + 1, j) + pm * solve(i, j + 1);
    }
    // printf("%d %d gives %lf\n",i,j, ans);
    return ans;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        scanf("%lf %lf %lf %lf", &c, &m, &p, &v);

        printf("%.10lf\n", solve(0, 0));

        test++;
    }

    return 0;
}