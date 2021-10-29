#include <bits/stdc++.h>

using namespace std;

const int N = 10;
int mark[N];
int dp[N];

int mex(int a, int b, int c){
    memset(mark, 0, sizeof mark);
    mark[a] = mark[b] = 1;

    if(c != -1){
        mark[c] = 1;
    }

    for(int i = 0 ; i < N ; i++){
        if(!mark[i]){
            return i;
        }
    }

    return -1;
}

int main(){
    dp[1] = 1;

    int k;
    int n;
    
    scanf("%d %d", &n, &k);
    
    printf("0 1 ");

    for(int i = 2 ; i <= n ; i++){
        dp[i] = mex(dp[i - 1], dp[i - 2], i >= k ? dp[i - k] : -1);
        printf("%d ", dp[i]);
    }

    printf("\n");

    return 0;
}