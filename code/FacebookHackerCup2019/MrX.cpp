#include <bits/stdc++.h>
using namespace std;

const int N = int(3e3 + 10);
char s[N];
char mp[N];
const int O = 3, V = 4;
int dp[N][N][V];
int used[N][N][V];
int test = 1;
const int inf = N;
int match[N];
stack< int > st;
char op[O] = {'&', '|', '^'};

int eval(char op, int val1, int val2){
    if(val1 > val2){
        swap(val1, val2);
    }
    
    if(op == '^'){
        if(val1 == 2 && val2 == 3){
            return 1;
        }
        
        return val1 ^ val2;
    }else if(op == '&'){
        if(val1 == 2 && val2 == 3 || val1 == 0){
            return 0;
        }
        
        if(val2 >= 2){
            return val2;
        }
        
        return val1 & val2;
    }else if(op == '|'){
        if(val1 == 2 && val2 == 3){
            return 1;
        }
        
        if(val1 == 0){
            return val2;
        }else{
            return val1;
        }
    }
}

int solve(int i, int j, int val){
    //printf("%d, %d\n", i, j);
    fflush(stdout);
    
    if(i == j){
        return val != mp[s[i]];
    }
    
    if(s[i] == '(' && match[i] == j){
        return solve(i + 1, j - 1, val);
    }
    
    int &ans = dp[i][j][val];
    int &us = used[i][j][val];
    
    if(us == test){
        return ans;
    }
    
    ans = inf;
    us = test;
    int mid;
    
    if(s[i] == '('){
        mid = match[i] + 1;
    }else{
        mid = i + 1;
    }
    
    for(int k = 0 ; k < O ; k++){
        for(int val1 = 0 ; val1 < V ; val1++){
            for(int val2 = 0 ; val2 < V ; val2++){
                if(eval(op[k], val1, val2) == val){
                    ans = min(ans, (op[k] != s[mid]) + solve(i, mid - 1, val1) + solve(mid + 1, j, val2));
                }
            }
        }
    }
    
    return ans;
}

int main() {
    mp['0'] = 0;
    mp['1'] = 1;
    mp['x'] = 2;
    mp['X'] = 3;
    
    int t;

    scanf("%d", &t);
    
    while(t--){
        scanf("\n%s", s);
        
        int n = strlen(s);
        
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                match[st.top()] = i;
                st.pop();
            }
        }
        
        printf("Case #%d: %d\n", test++, min(solve(0, n - 1, 1), solve(0, n - 1, 0)));
    }
    
	return 0;
}