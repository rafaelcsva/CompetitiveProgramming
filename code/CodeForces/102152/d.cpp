//01, 04, 2019, 18:37:12 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 12;
int dp[N][N][N][N];
const int D = 10;
const int inf = 1e9;

int solve(int digit, int n1_1, int n1_2, int n1_3){
    if(n1_1 < 0 || n1_2 < 0 || n1_3 < 0){
        return -inf;
    }
    // cout << digit << " " << n1_1 << " " << n1_2 << " " << n1_3 << endl;

    if(digit == D){
        if(n1_1 != 0 || n1_2 != 0 || n1_3 != 0){
            return -inf;
        }

        return 0;
    }

    int &ans = dp[digit][n1_1][n1_2][n1_3];
    
    if(ans != -1){
        return ans;
    }

    for(int j = 0 ; j < (1 << 3) ; j++){
        int r1 = j & 1;
        int r2 = (j & 2) ? 1 : 0;
        int r3 = (j & 4) ? 1 : 0;
        int d = __builtin_popcount(j);

        ans = max(ans, solve(digit + 1, n1_1 - r1, n1_2 - r2, n1_3 - r3) + (d & 1) * (1 << digit));
    }

    if(ans == -1){
        ans = -inf;
    }
    
    return ans;
}

int count_1(string &s){
    int cnt = 0;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '1'){
            cnt++;
        }
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof dp);

    int t;

    cin >> t;

    while(t--){
        string a, b, c;

        cin >> a >> b >> c;

        int r = solve(0, count_1(a), count_1(b), count_1(c));
        assert(r >= 0);

        for(int j = 9 ; j >= 0 ; j--){
            if(r & (1 << j)){
                cout << 1;
            }else{
                cout << 0;
            }
        }

        cout << endl;
    }

    return 0;
}