//03, 10, 2018, 18:52:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1000;
int n, t;
int a[N];
int dp[N];

void run(){
    int mx = 0;

    for(int i = 0 ; i < t * n ; i++){
        dp[i] = 1;

        for(int j = 0 ; j < i ; j++){
            if(a[i] >= a[j]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        mx = max(mx, dp[i]);
    }

    return mx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    scanf("%d %d", &n, &t);

    for(int i = n ; i <= 3 * n ; i++){
        a[i] = a[i % n];
    }

    int x = run();
    if(t <= 3){
        printf("%d\n", x);
    }else{
        for(int i = 0 ; i < 2 * n ; i++){
            dp[i] = 1;

            for(int j = 0 ; j < 2 * n ; j++){
                if(j == i % n){
                    int f = dp[i] - dp[j];
                }
            }
        }
    }

    return 0;
}