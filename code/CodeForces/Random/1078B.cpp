//19, 11, 2018, 18:24:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 110, S = int(1e4 + 10);
int a[N];
int dp[S][N];
bool pre[S][N];
int process[S][N];
int cnt[N];
int test;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);

        cnt[a[i]]++;
    }

    sort(a, a + n);

    dp[0][0] = -1LL;
    
    for(int i = 0 ; i < n ; i++){
        for(int k = 1 ; k <= n ; k++){
            for(int sum = 0 ; sum < S ; sum++){
                if(sum - a[i] >= 0){
                    if(!dp[sum - a[i]][k - 1]){
                        continue;
                    }

                    if(process[sum - a[i]][k - 1] == i + 1){
                        // printf("%d %d %d\n", sum - a[i], a[i], dp[sum][k]);
                        continue;
                    }

                    if(!dp[sum][k]){
                        process[sum][k] = i + 1;
                    }

                    bool change = pre[sum][k];

                    if(pre[sum - a[i]][k - 1]){
                        pre[sum][k] = true;
                    }

                    if(dp[sum][k] == 0LL || dp[sum][k] == a[i]){
                        dp[sum][k] = a[i];
                    }else{
                        // dp[sum][k] = a[i];
                        pre[sum][k] = true;
                    }

                    if(dp[sum - a[i]][k - 1] != -1LL){
                        if(dp[sum - a[i]][k - 1] != a[i]){
                            pre[sum][k] = true;
                        }
                    }

                    // if(change != pre[sum][k] && sum == 150 && k == 3){
                    //     printf("i: %d %d %d\n", a[i], dp[sum - a[i]][k - 1], dp[sum - a[i] - dp[sum - a[i]][k - 1]][k - 2]);
                    // }
                }
            }
        }
    }

    int best = 1;
    int diff = 0;
    int val = 0;

    for(int i = 1 ; i < N ; i++){
        if(cnt[i]){
            diff++;
        
            val = max(cnt[i], val);
        }

        for(int k = 1 ; k <= cnt[i] ; k++){
            int sum = i * k;
        
            if(!pre[sum][k]){
                best = max(best, k);
            }else{
                // printf("%d %d\n", sum, k);
            }
        }    
    }

    if(diff == 2){
        if(val == best){
            best = n;
        }
    }

    printf("%d\n", best);
    
    return 0;
}