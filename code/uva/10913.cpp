#include <bits/stdc++.h>

using namespace std;

const int N = 80;
typedef long long   ll;
ll dp[N][N][10][10];
int used[N][N][10][10];
int n, k;
ll m[N][N];
int test = 1;
const ll INF = 10000000000000000LL;
bool ok = false;

ll solve(int l, int c, int dir, int neg){
    if(c < 0 || l < 0 || l >= n || c >= n){
        return -INF;
    }
    
    if(neg > k){
        return -INF;
    }
    
    if(l == n - 1 && dir == 2){
        return -INF;
    }

    if(l == n - 1 && c == n - 1){
        if((neg + (m[l][c] < 0LL)) > k){
            return -INF;
        }

        ok = true;
        return m[l][c];
    }

    int &us = used[l][c][dir][neg];
    ll &ans = dp[l][c][dir][neg];

    if(us == test){
        return ans;
    }

    ans = -INF;
    us = test;

    ans = solve(l + 1, c, 0, neg + (m[l][c] < 0LL)) + m[l][c];

    if(dir == 1 || dir == 0){
        ans = max(ans, solve(l, c + 1, 1, neg + (m[l][c] < 0)) + m[l][c]);
    }
    
    if(dir == 2 || dir == 0){
        ans = max(ans, solve(l, c - 1, 2, neg + (m[l][c] < 0)) + m[l][c]);
    }
    
    return ans;
}

int main (){
    ios::sync_with_stdio(false);

    while(cin >> n >> k){
        if(n == 0 && k == 0){
            break;
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> m[i][j];
            }
        }

        ll r = solve(0, 0, 0, 0);

        cout << "Case " << test << ": ";
        
        if(!ok){
            cout << "impossible" << endl;
        }else{
            cout << r << endl;
        }

        test++;
        ok = false;
    }

    return 0;    
}