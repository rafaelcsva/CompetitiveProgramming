#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 10;
int p[N];

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    if(k == 0){
        printf("-1\n");
    }else{
        k--;
        for(int i = 1 ; i <= n ; i++){
            p[i] = i;
        }

        for(int i = 2 ; i <= n && k ; i++){
            k--;
            swap(p[i], p[i - 1]);
        }

        if(k){
            printf("-1\n");
        }else{
            for(int i = 1 ; i <= n ; i++){
                printf("%d ", p[i]);
            }
            printf("\n");
        }
    }
}