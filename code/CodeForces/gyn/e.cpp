//06, 12, 2018, 17:31:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 3000;
ll dp[N][N];
int a[N];
int pos[N];
int n;
const ll mod = 2147483647LL;

ll solve(int i, int j){
    if(i == a[n] || j == a[n]){
        return 1LL;
    }

    ll &ans = dp[i][j];

    if(ans != -1LL){
        return ans;
    }

    ans = 0LL;

    int posi = pos[i];
    int posj = pos[j];
    int nxt;

    if(posi > posj){
        nxt = a[posi + 1];
    }else{
        nxt = a[posj + 1];
    }
    // cout << i << " " << j << " " << posi << " " << posj << " " << nxt << endl;

    vector< int > v1, v2;

    v1.push_back(i);
    v1.push_back(j);
    sort(v1.begin(), v1.end());

    v2.push_back(j);
    v2.push_back(nxt);
    sort(v2.begin(), v2.end());

    int ii = max(v1[0], v2[0]);
    int jj = min(v2[1], v1[1]);

    if((jj - ii + 1) > 1){
        ans += solve(j, nxt);
    }

    // cout << jj - ii + 1 << " " << jj << " " << j << "->" << nxt << endl;
    
    v2.clear();

    v2.push_back(nxt);
    v2.push_back(i);

    sort(v2.begin(), v2.end());
    
    ii = max(v1[0], v2[0]);
    jj = min(v2[1], v1[1]);

//    cout << jj - ii + 1 << " " << jj << " " << nxt << "->" << i << " " << jj << " " << ii << endl;
    if((jj - ii + 1) > 1){
        ans += solve(nxt, i);
    }

    ans %= mod;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1LL, sizeof dp);

    scanf("%d", &n);

    for(int i = 0 ; i < n + 1 ; i++){
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }

    printf("%lld\n", solve(a[0], a[1]));

    return 0;
}