//14, 07, 2018, 09:16:22 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;
int n;
const int N = 110;
int dp[N], used[N];
int a[N];

int solve(int i){
    if(i >= n - 1){
        return 0;
    }

    if(used[i]){
        return dp[i];
    }

    used[i] = 1;

    if(a[i] == a[i + 1]){
        return dp[i] = min(1 + solve(i + 1), 1 + solve(i + 2));
    }else{
        return dp[i] = solve(i + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    cout << solve(0) << endl;

    return 0;
}