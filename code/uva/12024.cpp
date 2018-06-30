//25, 06, 2018, 16:39:11 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 13;
ll dp[N];
ll fat[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fat[1] = 1LL;
    fat[2] = 2LL;
    dp[2] = 1LL;

    for(ll i = 3 ; i < N ; i++){
        dp[i] = (i - 1LL) * (dp[i - 1] + dp[i - 2]);
        fat[i] = i * fat[i - 1];
    }    

    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        cout << dp[n] << "/" << fat[n] << endl;
    }
    
    return 0;
}