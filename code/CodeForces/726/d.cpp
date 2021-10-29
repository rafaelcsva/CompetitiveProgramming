#include <bits/stdc++.h>

using namespace std;

const int N = int(1e3) + 10;
int dp[N];

bool solve(int a){
    if(dp[a] != -1){
        return dp[a];
    }

    dp[a] = 0;

    for(int i = 2 ; i * i <= a ; i++){
        if(a % i == 0){
            dp[a] |= !solve(a - i);
            dp[a] |= !solve(a - (a / i));
        }
    }

    return dp[a];
}

int main(){
    memset(dp, -1, sizeof dp);
    int t;

    // for(int i = 12 ; i < N ; i += 2){
    //     if(!solve(i)){
    //         printf("%d\n", i);
    //     }
    // }

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        if(n < N){
            int cnt = solve(n);

            if(cnt){
                printf("Alice\n");
            }else{
                printf("Bob\n");
            }
        }else{
            if(n & 1){
                printf("Bob\n");
                continue;
            }

            long long gold = 32LL;
            long long tn = n;

            while(gold < tn){
                gold *= 4LL;
            }

            if(gold != tn){
                printf("Alice\n");
            }else{
                printf("Bob\n");
            }
        }
    }

    return 0;
}