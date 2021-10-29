#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int ni;

        scanf("%d", &ni);

        for(int i = 0 ; i < ni ; i++){
            printf("%d ", 4 * ni - 2 * i);
        }

        printf("\n");
    }

    return 0;
}