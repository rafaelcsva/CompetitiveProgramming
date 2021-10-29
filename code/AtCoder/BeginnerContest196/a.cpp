#include <bits/stdc++.h>

using namespace std;

int a[4];

int main(){
    for(int i = 0 ; i < 4 ; i++){
        scanf("%d", &a[i]);
    }

    printf("%d\n", max(a[0], a[1]) - min(a[2], a[3]));

    return 0;
}