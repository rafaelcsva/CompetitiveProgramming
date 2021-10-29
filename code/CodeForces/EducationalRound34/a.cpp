#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    scanf("%d", &n);

    while(n--){
        int x;

        scanf("%d", &x);

        while(x >= 0 && x % 7 != 0){
            x -= 3;
        }

        if(x >= 0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}