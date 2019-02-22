//19, 10, 2018, 19:36:58 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int a, b, c;
const int POS = 30, QTD = 30, CARRY = 2;
int dp[POS][QTD][QTD][CARRY];
int used[POS][QTD][QTD][CARRY];
int test;

int solve(int pos, int qtd_a, int qtd_b, int carry){
    if(pos == POS){
        // printf("r: %d %d %d\n", qtd_a, qtd_b, carry);
        return qtd_a == 0 && qtd_b == 0 && !carry;
    }

    int &us = used[pos][qtd_a][qtd_b][carry];
    int &ans = dp[pos][qtd_a][qtd_b][carry];

    if(us == test){
        return ans;
    }

    us = test;
    ans = 0;

    int lim_a = min(1, qtd_a);
    int lim_b = min(1, qtd_b);
    int e = 1 << pos;
    // printf("%d\n", e);
    int test = c & e;
    // printf("%d %d\n", pos, test);

    for(int a = 0 ; a <= lim_a ; a++){
        for(int b = 0 ; b <= lim_b ; b++){
            if(a && b){
                if(carry){
                    if(test){
                        ans += solve(pos + 1, qtd_a - a, qtd_b - b, 1);
                    }
                }else{
                    if(!test){
                        ans += solve(pos + 1, qtd_a - a, qtd_b - b, 1);
                    }
                }
            }else if(a || b){
                if(carry){
                    if(!test){
                        ans += solve(pos + 1, qtd_a - a, qtd_b - b, 1);
                    }
                }else{
                    if(test){
                        ans += solve(pos + 1, qtd_a - a, qtd_b - b, 0);
                    }
                }
            }else{
                if(carry){
                    if(test){
                        ans += solve(pos + 1, qtd_a, qtd_b, 0);
                    }
                }else{
                    if(!test){
                        ans += solve(pos + 1, qtd_a, qtd_b, 0);
                    }
                }
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    for(test = 1 ; test <= t ; test++){
        scanf("%d %d %d", &a, &b, &c);

        printf("%d\n", solve(0, __builtin_popcount(a), __builtin_popcount(b), 0));
    }

    return 0;
}