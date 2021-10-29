#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[3];

    scanf("%d %d %d", &a[0], &a[1], &a[2]);

    sort(a, a + 3);

    if(a[1] == a[2]){
        printf("%d\n", a[0]);
    }else if(a[0] == a[1]){
        printf("%d\n", a[2]);
    }else{
        printf("0\n");
    }

    return 0;
}