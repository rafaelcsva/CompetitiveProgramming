//16, 08, 2018, 13:57:46 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector< ll > numbers;
vector< char > operators;

const int N = 300;
ll dp[N][2];
int used[N][2];
int test = 1;
int n;
int m;

ll solve(int pos, int mx){//mx = 0 para maximizar, 1 caso contrario
    if(pos == m){
        if(mx){
            return - numbers[m];
        }
        return numbers[m];
    }

    ll &ans = dp[pos][mx];

    if(used[pos][mx] == test){
        return ans;
    }
    
    used[pos][mx] = test;
    
    ans = -1e18;
        
    ll st = numbers[pos];

    if(mx){
        st *= -1LL;
    }
    
    if(mx == 0){
        for(int k = pos; k < m ; k++){
            if(operators[k] == '-'){
                ans = max(ans, st + solve(k + 1, 1));
                st -= numbers[k + 1];
            }else{
                ans = max(ans, st + solve(k + 1, 0));
                st += numbers[k + 1];
            }
        }
        ans = max(ans, st);
    }else{
        for(int k = pos ; k < m ; k++){
            if(operators[k] == '-'){
                ans = max({ans, st + solve(k + 1, 0), st + solve(k + 1, 1)});
                st += numbers[k + 1];
            }else{
                ans = max({ans, st + solve(k + 1, 0), st + solve(k + 1, 1)});
                st -= numbers[k + 1];
            }
        }
        ans = max(ans, st);
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){  
        scanf("%d", &n);
        m = n - 1;
        
        for(int i = 0 ; i < n + n - 1 ; i++){
            if(i & 1){
                char c;

                scanf(" %c ", &c);
                operators.push_back(c);
            }else{
                ll numb;

                scanf("%lld", &numb);
                numbers.push_back(numb);
            }
        }

        printf("%lld\n", solve(0, 0));
        test++;

        numbers.clear();
        operators.clear();
    }

    return 0;
}