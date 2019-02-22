//21, 11, 2018, 18:08:36 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 110;
pii dp[N][N][2];
int used[N][N][2];
int a[N];
int test = 1;
const int inf = int(1e9);

pii solve(int i, int j, int player){
    // printf("%d, %d\n", j, i);
    if(j < i){
        // printf("%d, %d\n", j, i);
        return {0, 0};
    }

    pii &ans = dp[i][j][player];

    if(used[i][j][player] == test){
        return ans;
    }

    used[i][j][player] = test;
    ans = {-inf, -inf};

    int sum = 0;

    for(int k = i ; k <= j ; k++){
        sum += a[k];

        // printf("1: %d, %d\n", k + 1, j);
        pii v = solve(k + 1, j, !player);

        if(player){
            if(v.first + sum > ans.first){
                ans = {v.first + sum, v.second};
            }
        }else{
            if(v.second + sum > ans.second){
                ans = {v.first, v.second + sum};
            }
        }
    }

    sum = 0;

    for(int k = j ; k >= i ; k--){
        sum += a[k];

        pii v = solve(i, k - 1, !player);

        if(player){
            if(v.first + sum > ans.first){
                ans = {v.first + sum, v.second};
            }
        }else{
            if(v.second + sum > ans.second){
                ans = {v.first, v.second + sum};
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while(scanf("%d", &n) != EOF){
        if(n == 0)
            break;
            
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
        }

        pii r = solve(0, n - 1, 0);

        printf("%d\n", r.second - r.first);

        test++;
    }   

    return 0;
}