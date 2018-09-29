//31, 07, 2018, 13:12:38 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 201;
const int S = 201;
ll dp[N][N][S][2];
bool used[N][N][S][2];
int n, m;
int saldo = 0;
ll mod = 1000000007LL;
string s;
int b[N];

void KMP_preprocess(){
    int i = 0, j = -1;
    b[0] = -1;

    while(i < m){
        while(j >= 0 && s[i] != s[j]){
            j = b[j];
        }

        i++, j++;
        b[i] = j;
    }
}

ll solve(int pos, int poss, int sum, bool taked ){
    if(sum < 0){
        return 0LL;
    }
    
    if(poss == m){
        taked = true;
    }

    ll &ans = dp[pos][poss][sum][taked];
    
    if(pos == 2 * n){
        return ans = taked && (sum == 0);
    }

    if(used[pos][poss][sum][taked]){
        return ans;
    }

    used[pos][poss][sum][taked] = true;

    if(!taked){
        int w = poss;

        if(s[poss] == ')'){
            while(w >= 0 && s[w] != '('){
                w = b[w];
            }
            
            ans = solve(pos + 1, w + 1, sum + 1, taked) + solve(pos + 1, poss + 1, sum - 1, taked);
            ans %= mod;
        }else{
            while(w >= 0 && s[w] != ')'){
                w = b[w];
            }

            ans = solve(pos + 1, poss + 1, sum + 1, taked) + solve(pos + 1, w + 1, sum - 1, taked);
            ans %= mod;
        }
    }else{
        ans = solve(pos + 1, 0, sum + 1, taked) + solve(pos + 1, 0, sum - 1, taked);
        ans %= mod;
    }
    
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> s;
    
    m = s.length();
    
    KMP_preprocess();

    cout << solve(0, 0, 0, 0) << endl;
    
    return 0;
}