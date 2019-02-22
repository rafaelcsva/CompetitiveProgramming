//29, 12, 2018, 10:58:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define clockwise   0
#define counter_clockwise   1

const int N = int(2e3 + 10);
ll dp[N][N][2];
ll a[N];
ll n, l;
string name[2] = {"\tclockwise", "\tcounter_clockwise"};

ll solve(int i, int j, int dir){
    if(i > j){
        return 0LL;
    }

    ll &ans = dp[i][j][dir];

    if(ans != -1LL){
        return ans;
    }

    ll mn1, mn2;

    if(dir == clockwise){
        ll cur = a[i - 1];
        mn1 = a[i] - cur;
        mn2 = cur + l - a[j];

        ans = max(solve(i + 1, j, dir) + mn1, solve(i, j - 1, !dir) + mn2);
    }else{  
        ll cur = a[j + 1];
        
        mn1 = cur - a[j];
        mn2 = l - cur + a[i];

        ans = max(solve(i, j - 1, dir) + mn1, solve(i + 1, j, !dir) + mn2);
    }

    return ans;
}

void print_dp(int i, int j, int dir){
    if(i > j){
        return;
    }

    ll &ans = dp[i][j][dir];

    ll mn1, mn2;

    if(dir == clockwise){
        ll cur = a[i - 1];
        mn1 = a[i] - cur;
        mn2 = cur + l - a[j];
    
        if(ans == solve(i + 1, j, dir) + mn1){
            cout << cur << " -> " << a[i] << " " << name[dir] << endl;
            print_dp(i + 1, j, dir);
        }else{
            cout << cur << " -> " << a[j] << " " << name[!dir] << endl;
            print_dp(i, j - 1, !dir);
        }
    }else{  
        ll cur = a[j + 1];
        
        mn1 = cur - a[j];
        mn2 = l - cur + a[i];

        if(ans == solve(i, j - 1, dir) + mn1){
            cout << cur << " -> " << a[j] << " " << name[dir] << endl;
            print_dp(i, j - 1, dir);
        }else{
            cout << cur << " -> " << a[i] << " " << name[!dir] << endl;
            print_dp(i + 1, j, !dir);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1LL, sizeof dp);

    cin >> l >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }

    ll val = max(solve(2, n, clockwise) + a[1], solve(1, n - 1, counter_clockwise) + l - a[n]);

    if(val != solve(2, n, clockwise) + a[1]){
        cout << 0 << " -> " << a[n] << "\tcounter_clockwise" << endl;
        print_dp(1, n - 1, counter_clockwise);
    }else{
        
        cout << 0 << " -> " << a[1] << "\tclockwise" << endl;
        print_dp(2, n, clockwise);
    }

    cout << "val = " << val << endl;
    
    return 0;
}