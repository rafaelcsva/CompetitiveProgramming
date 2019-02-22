#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e5 + 100;
char s[N], t[N];
ll dp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    ll k;

    scanf("%d %lld", &n, &k);

    scanf("\n%s %s", s, t);

    dp[0] = 1LL;

    for(int i = 1 ; i <= n ; i++){
        dp[i] = dp[i - 1] * 2LL;

        if(s[i - 1] == 'b'){
            dp[i]--;
        }

        if(t[i - 1] == 'a'){
            dp[i]--;
        }

        dp[i] = min(dp[i], k + 10LL);
    }

    ll sum = 0LL;

    for(int i = 1 ; i <= n ; i++){
        sum += min(dp[i], k);
    }

    printf("%lld\n", sum);

    return 0;
}