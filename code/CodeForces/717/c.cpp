#include <bits/stdc++.h>

using namespace std;

const int M = 102;
const int N = 2002 * M;
int dp[M][N];
int a[M];
int n;

int solve(int i, int sum){
    if(sum < 0){
        return false;
    }
    int &ans = dp[i][sum];

    if(sum == 0){
        return ans = 1;
    }

    if(ans != -1){
        return ans;
    }

    if(i >= n){
        return ans = 0;
    }

    ans = 0;

    ans = solve(i + 1, sum - a[i]) | solve(i + 1, sum);

    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);

    scanf("%d", &n);

    int sum = 0;
    int odd = -1;
    int ev = 0;

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);

        sum += a[i];

        if(a[i] & 1){
            odd = i;
        }else if((a[ev] & -a[ev]) > (a[i] & (-a[i]))){
            ev = i;
        }
    }

    if(sum & 1){
        printf("0\n");
    }else{
        if(solve(0, sum / 2)){
            printf("1\n");

            if(odd != -1){
                printf("%d\n", odd + 1);
            }else{
                printf("%d\n", ev + 1);
            }
        }else{
            printf("0\n");
        }
    }

    return 0;
}