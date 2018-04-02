#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 10, INF = (int) 1e9;
vector<int>r;
vector<int>q;
int used[N], dp[N];

int solve(int n){
    if(n == 0){
        return dp[n] = 0;
    }

    if(n < 0){
        return INF;
    }

    if(used[n]){
        return dp[n];
    }

    used[n] = 1;
    dp[n] = INF;

    for(int i = 0 ; i < r.size() && r[i] <= n ; i++){
        dp[n] = min(dp[n], 1 + solve(n - r[i]));
    }

    return dp[n];
}

void printDP(int n){
    if(n == 0){
        return;
    }

    for(int i = 0 ; i < r.size() ; i++){
        if(dp[n] == dp[n - r[i]] + 1){
            cout << r[i] << ' ';
            printDP(n - r[i]);
            break;
        }
    }
}

int main (){
    int n;
    
    for(int i = 0 ; i < (1 << 7) ; i++){
        int num = 0;
        int tmp = i;
        int pot = 1;

        while(tmp){
            num = num + (tmp % 2) * pot;
            pot *= 10;
            tmp /= 2;
        }
        
        r.push_back(num);
    }

    cin >> n;

    cout << solve(n) << '\n';
    printDP(n);
    cout << '\n';

    return 0;
}