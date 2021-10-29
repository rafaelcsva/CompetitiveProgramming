#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;

    scanf("%d %d", &n, &x);

    for(int i = 0 ; i < n ; i++){
        int ai;

        scanf("%d", &ai);

        if(ai != x){
            printf("%d ", ai);
        }
    }

    printf("\n");
}