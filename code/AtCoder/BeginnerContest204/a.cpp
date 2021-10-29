#include <bits/stdc++.h>

using namespace std;

int ver[3];

int main(){
    int a, b;

    scanf("%d %d", &a, &b);

    ver[a] = ver[b] = 1;

    if(a == b){
        printf("%d\n", a);
    }else{
        for(int i = 0 ; i < 3 ; i++){
            if(!ver[i]){
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}