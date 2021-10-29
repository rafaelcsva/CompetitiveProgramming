#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 10;
int n;
string s[N];
bool dp[N];
bool old[N][(1 << 8) + 5];
bool keep[N][(1 << 8) + 5];
bool memo[N][(1 << 8) + 5];
bool ans;

int diff(int a, int b){
    int cnt = 0;

    for(int d = 0 ; d < s[a].length() ; d++){
        if(s[a][d] == s[b][d]){
            cnt++;
        }
    }

    return cnt;
}

void print_mask(int mask){
    for(int i = 7 ; i >= 0 ; i--){
        int e = 1 << i;

        if(mask & e){
            cout << "1";
        }else{
            cout << "0";
        }
    }
}

void solve(int i, int mask){
    if(memo[i][mask]){
        ans = keep[i][mask];
        return;
    }

    int oldv = -1;

    if(memo[i][mask]){
        oldv = 1;
    }

    memo[i][mask] = true;
    dp[i] = false;

    int d = 1;
    for(int j = 7 ; j >= 0 ; j--){
        int e = 1 << j;

        if((mask & e) == 0 && diff(i, i + d) >= d){
            dp[i] = true;
            break;
        }
        d++;
    }

    int mmask = mask;

    // if(oldv != -1 && old[i][mask] != dp[i]){
    //     cout << "problem " << i << " " << mask << endl;
    // }
    
    old[i][mask] = dp[i];

    mmask >>= 1;
    if(dp[i]){
        mmask |= (1 << 7);
    }
    
    if(i > 0){
        solve(i - 1, mmask);
    }else{
        ans = dp[i];
    }
    keep[i][mask] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
    }

    for(int i = 0 ; i < n ; i++){
        solve(i, (1 << 8) - 1);

        if(ans){
            cout << "1";
        }else{
            cout << "2";
        }
    }

    cout << "\n";

    return 0;
}
