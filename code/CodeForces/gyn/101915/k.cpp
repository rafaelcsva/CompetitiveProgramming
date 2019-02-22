//28, 11, 2018, 09:04:54 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 55;
ll dp[N][N];
int used[N][N];
int test;
string s;
const ll mod = 1e9 + 7;
int n;

ll solve(int i, int j){
    ll &ans = dp[i][j];

    if(i >= j){
        return 1LL;
    }

    if(used[i][j] == test){
        return ans;
    }

    used[i][j] = test;
    ans = 1LL;

    int sum = 0;

    for(int k = i ; k < j ; k++){
        sum += s[k];
        int sum2 = 0;

        for(int t = j ; t > k ; t--){
            sum2 += s[t];

            if(sum == sum2){
                // printf("%d->%d | %d->%d (%d)\n", i, k, j, t, sum);
                ans += solve(k + 1, t - 1);
                ans %= mod;
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    for(test = 1 ; test <= t ; test++){
        cin >> s;

        n = s.length();

        for(int i = 0 ; i < n ; i++){
            s[i] -= '0';
        }

        cout << solve(0, n - 1) << endl;
    }

    return 0;
}