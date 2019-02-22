//14, 11, 2018, 15:10:38 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

map< pii, bool > mark;
int n;

int sum(int d){
    int tot = 0;

    for(int i = 2 ; i <= n ; i++){
        if(d % i == 0){
            int q = abs(d / i);
            
            if(q == 1){
                continue;
            }

            if(!mark[{d, i}]){
                mark[{i, d}] = mark[{d, i}] = true;
                return q + sum(i);
            }
        }else if(i % d == 0){
            int q = abs(i / d);

            if(q == 1){
                continue;
            }

            if(!mark[{d, i}]){
                mark[{i, d}] = mark[{d, i}] = true;

                return q + sum(i);
            }
        }
    }

    for(int i = 2 ; i <= n ; i++){
        if(d % i == 0){
            int q = abs(d / i);
            
            if(q == 1){
                continue;
            }

            if(!mark[{d, -i}]){
                mark[{-i, d}] = mark[{d, -i}] = true;
                return q + sum(-i);
            }
        }else if(i % d == 0){
            int q = abs(i / d);

            if(q == 1){
                continue;
            }

            if(!mark[{d, -i}]){
                mark[{-i, d}] = mark[{d, -i}] = true;

                return q + sum(-i);
            }
        }
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &n);

    int r;

    if(n & 1){
        r = sum(n);
    }else{
        r = sum(n);
    }

    printf("%d\n", r);

    return 0;
}