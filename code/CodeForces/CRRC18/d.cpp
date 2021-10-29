#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6);
int qtd[N];
int ans[N];

int main(){
    for(int i = 1 ; i < N ; i++){
        for(int j = i ; j < N ; j += i){
            qtd[j]++;
        }
    }

    for(int i = 1 ; i < N ; i++){
        if(ans[qtd[i]] == 0){
            ans[qtd[i]] = i;
        }
    }

    for(int i = 1 ; i <= 1000 ; i++){
        if(ans[i]){
            printf("%d %d\n", i, ans[i]);
        }
        // assert(ans[i]);
    }

    return 0;
}