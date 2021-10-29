#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, pos, l, r;

    scanf("%d %d %d %d", &n, &pos, &l, &r);

    if(l == 1 && r == n){
        printf("0\n");
    }else if(r == n){
        printf("%d\n", abs(pos - l) + 1);
    }else if(l == 1){
        printf("%d\n", abs(pos - r) + 1);
    }else{
        int mv = min(abs(pos - l) + r - l, abs(pos - r) + r - l) + 2;

        printf("%d\n", mv);
    }

    return 0;
}