#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 10;
double dp[N];
int vis[N];

double solve(int qtd, int a, int b){
    if(qtd <= 0){
        return 0.0;
    }

    double sum = 0.0;

    int t = b - a + 1;

    if(vis[qtd]){
        return dp[qtd];
    }

    vis[qtd] = 1;

    double pref = 0.0;

    for(int j = max(a, 1) ; j <= b ; j++){
        // pref += solve(qtd - j, a, b);    
        sum += (1.0 + solve(qtd - j, a, b)) / double(t);
    }

    // if(a == 0){
    //     sum += 1.0 / t;
    //     sum /= (1.0 - 1.0 / double(t));
    // }

    // printf("para %d pref eh %lf\n", qtd, pref);

    return dp[qtd] = sum;
}

int main(){
    int n, a, b;

    scanf("%d %d %d", &n, &a, &b);

    // printf("%.6lf\n", solve(n, a, b));

    // return 0;
    if(a != 0){
        for(int i = 1 ; i < a ; i++){
            dp[i] = 1.0;
        }

        double pref = 0.0;

        for(int i = a ; i <= n ; i++){
            int t = b - a + 1;

            pref += dp[i - a];

            if(i - b - 1 >= 0){
                pref -= dp[i - b - 1];
            }

            double val  =1.0 + (pref / double(t));

            dp[i] = val;
        }
    }else{
        double pref = 0.0;

        for(int i = 1 ; i <= n ; i++){
            int t = b - a + 1;

            if(i){
                pref += dp[i - 1];
            }

            if(i - b - 1 >= 0){
                pref -= dp[i - b - 1];
            }

            dp[i] = ((double(t) + pref) / t) / (1.0 - double(1.0 / t));
        }
    }

    printf("%.7lf\n", dp[n]);

    return 0;
}