//01, 11, 2018, 19:34:20 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 10000, NUMBER = 40, OFF_SET = 3000, M = 3010 + OFF_SET;
char expr[N];

vector< int > numbers;
vector< char > operators;
int dp[M][NUMBER][NUMBER][2];
int used[M][NUMBER][NUMBER][2];
int can[M];
int test = 1;

void solve(int sum, int i, int open, int flag){
    if(i == numbers.size()){
        // cout << sum << endl;
        can[sum] = test;
        return;
    }

    if(used[sum][i][open][flag] == test){
        return;
    }

    used[sum][i][open][flag] = test;
    int cur = numbers[i];

    if(flag){
        cur *= -1;
    }

    if(open & 1){
        cur *= -1;
    }

    if(open > 0){
        solve(sum + cur, i + 1, open - 1, 0);
    }

    solve(sum + cur, i + 1, open, 0);

    if(operators[i] == '-'){
        solve(sum + cur, i + 1, open + 1, 1);

        if(open > 0)
            solve(sum + cur, i + 1, open, 1);
    }
}

bool is_number(char &c){
    return '0' <= c && c <= '9';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(scanf("\n%[^\n]s", expr) != EOF){
        int n = strlen(expr);

        int cur = 0;

        for(int i = 0 ; i < n ; i++){
            if(expr[i] == ' '){
                continue;
            }

            if(is_number(expr[i])){
                cur = cur * 10 + (expr[i] - '0');
            }else{
                numbers.push_back(cur);
                // cout << cur << endl;
                operators.push_back(expr[i]);
                cur = 0;
            }
        }

        numbers.push_back(cur);

        for(int i = 0 ; i < operators.size() ; i++){
            if(operators[i] == '-'){
                numbers[i + 1] *= -1;
            }
        }

        solve(OFF_SET, 0, 0, 0);

        int qtd = 0;

        for(int i = 0 ; i < M ; i++){
            if(can[i] == test){
                // cout << i - OFF_SET << endl;
                qtd++;
            }
        }

        printf("%d\n", qtd);

        test++;
        operators.clear();
        numbers.clear();
    }

    return 0;
}