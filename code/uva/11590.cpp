#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e7) + 10;
int root = 0;
int x = 0;
ll dp[N];
int uused[N];
int adj[N][2];
int used[N][2];
int leaf[N];
int test = 1;
string s[N];
ll m;

void add_string(string &s){
    int len = int(s.length()) - 1;

    int cur = 0;

    for(int i = 0 ; i < len ; i++){
        int d = s[i] - '0';

        if(used[cur][d] != test){
            used[cur][d] = test;
            adj[cur][d] = ++x;
        }

        cur = adj[cur][d];
    }

    leaf[cur] = test;
}

ll solve(int cur, int d){
    ll &ans = dp[cur];

    // if(uused[cur] == test){
    //     return ans;
    // }

    uused[cur] = test;
    ans = 0LL;

    if(used[cur][0] != test){
        ans += 1LL << ll(m - (d + 1));
    }else if(leaf[adj[cur][0]] != test){
        ans += solve(adj[cur][0], d + 1);
    }

    if(used[cur][1] != test){
        ans += 1LL << ll(m - (d + 1));
    }else if(leaf[adj[cur][1]] != test){
        ans += solve(adj[cur][1], d + 1);
    }

    return ans;
}

ll solve(string s){
    int len = int(s.length()) - 1;

    if(len == m){
        return 1LL;
    }

    int cur = 0;

    for(int i = 0 ; i < len ; i++){
        int d = s[i] - '0';

        if(used[cur][d] != test){
            return 1LL << ll(m - len);
        }

        cur = adj[cur][d];
    }

    return solve(cur, len);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while(cin >> n >> m){
        if(n == 0 && m == 0) break;

        for(int i = 0 ; i < n ; i++){
            cin >> s[i];

            add_string(s[i]);
        }

        int k;

        cin >> k;

        for(int i = 0 ; i < k ; i++){
            string s;

            cin >> s;

            cout << solve(s) << endl;
        }

        test++;
        x = 0;
        cout << "\n";
    }  

    return 0;
}
