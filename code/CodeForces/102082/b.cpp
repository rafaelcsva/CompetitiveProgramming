//17, 02, 2019, 16:12:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5001, M = int(1e4), T = int(1e5);
int a[N];
int dp[N][M];
// vector< int > diffs;
vector< int > diffs;
set< int > st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(st.find(a[i] - a[j]) == st.end()){
                st.insert(a[i] - a[j]);
                diffs.push_back(a[i] - a[j]);
                if(diffs.size() >= T){
                	break;
                }
            }
        }

        if(diffs.size() >= T){
        	break;
        }
    }

    sort(diffs.begin(), diffs.end());

    // auto it = unique(diffs.begin(), diffs.end());
    // diffs.erase(it, diffs.end());

    int best = 1;

    for(int i = 1 ; i < n ; i++){
        int idx = 0;

        for(int j = i - 1 ; j >= 0 ; j--){
            int idx = lower_bound(diffs.begin(), diffs.end(), a[i] - a[j]) - diffs.begin();
            if(idx >= M){
                continue;
            }
            if(dp[j][idx] == 0){
                dp[j][idx] = 1;
            }

            dp[i][idx] = max(dp[i][idx], 1 + dp[j][idx]);
            best = max(dp[i][idx], best);
        }
    }

    cout << best << endl;
    
    return 0;
}