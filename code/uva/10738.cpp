//21, 06, 2018, 22:21:34 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e6 + 100);
int cnt[N];
bool is_not_square_free[N];
int M[N];
int mu[N];

void sieve(){
    for(int i = 2 ; i < N ; i++){
        if(!cnt[i]){
            for(int j = i ; j < N ; j += i){
                cnt[j]++;

                if((j / i) % i == 0)
                    is_not_square_free[j] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();

    mu[1] = 1;
    M[1] = 1;

    for(int i = 2 ; i < N ; i++){
        if(!is_not_square_free[i]){
            if(cnt[i] % 2){
                mu[i] = -1;
            }else{
                mu[i] = 1;
            }
        }

        M[i] = mu[i] + M[i - 1];
    }
    
    int n;

    while(scanf("%d", &n) != EOF){
        if(n == 0)
            break;
            
        printf("%8d%8d%8d\n", n, mu[n], M[n]);
    }

    return 0;
}