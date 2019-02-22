//15, 10, 2018, 17:17:39 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2010;
ll dp[N][N];
bool used[N][N];
const ll inf = 1e15;
int n;

struct Item{
    ll t, c;
};

Item item[N];

ll solve(int c, int r){
    if(r <= 0)
        return 0LL;

    if(c == n)
        return inf;

    ll &ans = dp[c][r];

    if(used[c][r]){
        return ans;
    }

    used[c][r] = true;

    ans = min(solve(c + 1, r - item[c].t - 1) + item[c].c, solve(c + 1, r));

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld %lld", &item[i].t, &item[i].c);
    }

    printf("%lld\n", solve(0, n));

    return 0;
}