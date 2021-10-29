#include <bits/stdc++.h>
 
using namespace std;
 
int n, a;
int dp[1010];
int k;
int a1[1010], b1[1010];
 
int solve(int s){
    if(min(s + a, 2 * s) >= n){
        return 0;
    }
 
    int &ans = dp[s];
 
    if(ans != -1){
        return ans;
    }
    ans = 0;
    if(2 * s < n){
        ans |= !solve(2 * s);
    }
    if(s + a < n){
        ans |= !solve(s + a);
    }
    return ans;
}
 
bool check(){
    // printf("check! %d\n", k);
    memset(dp, -1, sizeof dp);
 
    for(int i = 0 ; i < k ; i++){
        // printf("lel: %d\n", solve(a1[i]));
    
        if(!((solve(a1[i]) & 1) == (b1[i] & 1))){
            return false;
        }
    }
 
    return true;
}
 
int main(){
    scanf("%d", &k);
 
    int st = 0;
 
    for(int i = 0 ; i < k ; i++){
        scanf("%d %d", &a1[i], &b1[i]);
        st = max(st, a1[i] + 1);
    }
 
    for(n = st ; n <= 1000 ; n++){
        for(a = 1 ; a <= 1000 ; a++){
            if(check()){
                printf("%d %d\n", n, a);
                return 0;
            }
        }
    }
    printf("0 0\n");
 
    return 0;
}