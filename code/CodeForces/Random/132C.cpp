//18, 09, 2018, 19:10:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 203;
char s[N];
int dp[N][N][N][2];
bool used[N][N][N][2];
const int P = 100;

int solve(int pos, int tu, int f, int dir){
    if(pos == strlen(s)){
        
        if(tu != 0){
            return -1;
        }

        return abs(P - f);
    }

    int &ans = dp[pos][tu][f][dir];
    
    if(used[pos][tu][f][dir]){
        return ans;
    }

    used[pos][tu][f][dir] = true;

    int add = dir ? -1 : 1;

    for(int u = 0 ; u <= tu ; u++){
        if(u & 1){
            if(s[pos] == 'F'){
                ans = max(ans, solve(pos + 1, tu - u, f, !dir));
            }else{
                ans = max(ans, solve(pos + 1, tu - u, f + add, dir));
            }
        }else{
            if(s[pos] == 'F'){
                ans = max(ans, solve(pos + 1, tu - u, f + add, dir));
            }else{
                ans = max(ans, solve(pos + 1, tu - u, f, !dir));
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    scanf("%s", s);

    scanf("%d", &n);

    printf("%d\n", solve(0, n, P, 0));

    return 0;
}