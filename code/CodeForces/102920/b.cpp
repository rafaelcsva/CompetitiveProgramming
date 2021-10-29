#include <bits/stdc++.h>

using namespace std;

int a[7];
int b[7];

int main(){
    for(int i = 0 ; i < 6 ; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0 ; i < 6 ; i++){
        scanf("%d", &b[i]);
    }

    int win = 0;

    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 6 ; j++){
            if(b[j] < a[i]){
                win++;
            }
        }
    }

    int g = __gcd(win, 36);
    // printf("%d\n", win);
    printf("%d/%d\n", win / g, 36 / g);

    return 0;
}