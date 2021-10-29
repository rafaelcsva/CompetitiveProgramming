#include <bits/stdc++.h>

using namespace std;

const int N = 210;
int dp[N][N][N][2][2][2];
int n;
vector< int > v1, v2;
int a[N];

int solve(int i, int s1, int s2, int f1, int f2, int f3){
    int &ans = dp[i][s1][s2][f1][f2][f3];

    if(s1 == s2 && f1 && f2 && f3){
        // printf("deu!\n");
        return ans = 1;
    }
    if(i == n){
        return ans = 0;
    }

    if(ans != -1){
        return ans;
    }

    ans = 0;

    ans |= solve(i + 1, (s1 + a[i]) % 200, s2, 1, f2, 1);
    ans |= solve(i + 1, s1, s2, f1, f2, f3);
    ans |= solve(i + 1, s1, (s2 + a[i]) % 200, f1, 1, 1);
    ans |= solve(i + 1, (s1 + a[i]) % 200, (s2 + a[i]) % 200, 1, 1, f3);

    return ans;
}

void get_ans(int i, int s1, int s2, int f1, int f2, int f3){
    int &ans = dp[i][s1][s2][f1][f2][f3];

    if(s1 == s2 && f1 && f2){
        return;
    }
    if(i == n){
        // printf("deu errado!\n");
        return;
    }

    // printf("ans = %d\n", ans);

    if(ans == solve(i + 1, (s1 + a[i]) % 200, s2, 1, f2, 1)){
        v1.push_back(i + 1);
        get_ans(i + 1, (s1 + a[i]) % 200, s2, 1, f2, 1);
    }else if(ans == solve(i + 1, s1, s2, f1, f2, f3)){
        get_ans(i + 1, s1, s2, f1, f2, f3);
    }else if(ans == solve(i + 1, s1, (s2 + a[i]) % 200, f1, 1, 1)){
        v2.push_back(i + 1);
        get_ans(i + 1, s1, (s2 + a[i]) % 200, f1, 1, 1);
    }else{
        v1.push_back(i + 1);
        v2.push_back(i + 1);
        get_ans(i + 1, (s1 + a[i]) % 200, (s2 + a[i]) % 200, 1, 1, f3);
    }

    return;
}

int main(){
    memset(dp, -1, sizeof dp);

    scanf("%d", &n);

    int sum = 0;

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);

        a[i] %= 200;
        sum += a[i];
        sum %= 200;
    }

    if(solve(0, 0, 0, 0, 0, 0)){
        // printf("aqui!\n");
        get_ans(0, 0, 0, 0, 0, 0);
        printf("Yes\n");
        printf("%lu", v1.size());
        for(auto u: v1){
            printf(" %d", u);
        }
        printf("\n");
        printf("%lu", v2.size());
        for(auto u: v2){
            printf(" %d", u);
        }
        printf("\n");
    }else{
        printf("No\n");
    }


    return 0;
}