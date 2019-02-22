//24, 10, 2018, 13:39:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353LL;
const int N = int(1e5 + 1);
ll dp[N][210][2];
const int D = 200;
bool used[N][210][2];
int a[N];
int n;

ll solve(int i, int last, bool flag){
    if(i == n){
        return !flag;
    }

    bool &us = used[i][last][flag];
    ll &ans = dp[i][last][flag];

    if(us){
        return ans;
    }

    us = true;

    if(a[i] != -1){
        if(flag && a[i] < last){
            return 0;
        }else{
            bool f;

            if(a[i] == last){
                f = false;
            }else{
                f = true;
            }

            return ans = solve(i + 1, a[i], f);
        }
    }

    if(i == 0){
        for(int d = 1 ; d <= D ; d++){
            ans += solve(i + 1, d, true);
            ans %= mod;
        }
    }else{
        int lim = 1;

        if(flag){
            lim = last;
        }
        
        for(int d = lim ; d <= D ; d++){
            bool f;

            if(d > last){
                f = true;
            }else{
                f = false;
            }

            ans += solve(i + 1, d, f);
            ans %= mod;
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }

    printf("%lld\n", solve(0, 0, 0));

    return 0;
}