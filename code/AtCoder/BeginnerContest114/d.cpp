//02, 12, 2018, 10:18:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 110;
int a[N];
const int TARGET = 75;
int dp[N][N];
bool used[N][N];

int solve(int pos, int mult){
    if(mult == TARGET){
        return 1;
    }

    if(pos == N){
        return 0;
    }

    if(mult > TARGET){
        return 0;
    }

    int &ans = dp[pos][mult];
    if(used[pos][mult]){
        return ans;
    }

    used[pos][mult] = true;

    for(int i = 0 ; i <= a[pos] ; i++){
        ans += solve(pos + 1, mult * (i + 1));
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    if(n <= 9){
        cout << 0 << endl;
        return 0;
    }

    for(int i = 1 ; i <= n ; i++){
        int k = i;

        for(int j = 2 ; j * j <= k ; j++){
            if(k % j == 0){
                int e = 0;

                while(k % j == 0){
                    e++;
                    k /= j;
                }

                a[j] += e;
            }
        }

        if(k != 1){
            a[k]++;
        }
    }

    cout << solve(1, 1) << endl;

    return 0;
}