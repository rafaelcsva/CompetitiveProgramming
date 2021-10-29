#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        if(n == 1){
            printf("9\n");
            continue;
        }

        printf("98");
        n -= 2;
        int num = 9;

        for(int i = 0 ; i < n ; i++){
            printf("%d", num);
            num = (num + 1) % 10;
        }
        printf("\n");
    }

    return 0;
}