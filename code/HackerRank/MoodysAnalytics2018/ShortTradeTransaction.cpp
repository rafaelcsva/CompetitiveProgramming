//18, 08, 2018, 10:53:29 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 102;
int dp[N][N][N];
bool used[N][N][N];

int solve(int need, int market, int prev){
    if(need < 0){
        return 0;
    }

    if(market == 0 || prev == 0){
        return need == 0;
    }

    int &ans = dp[need][market][prev];

    if(used[need][market][prev]){
        return ans;
    }

    used[need][market][prev] = true;

    for(int i = 0 ; i < prev ; i++){
        ans += solve(need - i, market - 1, i);    
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;

    scanf("%d", &q);

    while(q--){
        int a, m;

        scanf("%d %d", &a, &m);

        printf("%d\n", solve(a, m, a + 1));
    }

    return 0;
}