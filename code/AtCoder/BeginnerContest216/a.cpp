#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y;

    scanf("%d.%d", &x, &y);

    printf("%d", x);

    if(y >= 0 && y <= 2){
        printf("-\n");
    }else if(y >= 3 && y <= 6){
        printf("\n");
    }else if(y >= 7 && y <= 9){
        printf("+\n");
    }

    return 0;
}