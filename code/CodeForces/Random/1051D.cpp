//20, 09, 2018, 19:03:23 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
ll dp[N][2 * N + 10][10];
bool used[N][2 * N + 10][10];
const ll mod = 998244353LL;
int n, k;
const int P = 2;

ll solve(int pos, int rest, int mask){
    if(rest < 0){
        return 0;
    }

    if(pos == n){
        return rest == 0;
    }

    ll &ans = dp[pos][rest][mask];

    if(used[pos][rest][mask]){
        return ans;
    }

    used[pos][rest][mask] = true;

    for(int i = 0 ; i < (1 << P) ; i++){
        if(pos == 0){
            bool a = i & 1;
            bool b = i & 2;
            
            if(a != b){
                ans += solve(pos + 1, rest - 2, i);
            }else{
                ans += solve(pos + 1, rest - 1, i);
            }
            
            ans %= mod;
        }else{
            bool ver1 = false, ver2 = false;

            if((i & 1) != (mask & 1)){
                ver1 = true;
            }

            if((i & 2) != (mask & 2)){
                ver2 = true;
            }

            bool a = i & 1;
            bool b = i & 2;

            if(!ver1 && ver2 || ver1 && !ver2){
                if(a != b){
                    ans += solve(pos + 1, rest - 1, i);
                }else{
                    ans += solve(pos + 1, rest, i);
                }
            }else if(ver1 && ver2){
                if(a != b){
                    ans += solve(pos + 1, rest - 2, i);
                }else{
                    ans += solve(pos + 1, rest - 1, i);
                }
            }else{
                ans += solve(pos + 1, rest, i);
            }

            ans %= mod;
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %d", &n, &k);

    printf("%lld\n", solve(0, k, 0));
    
    return 0;
}