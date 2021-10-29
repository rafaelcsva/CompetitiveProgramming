#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[5];

    for(int i = 0 ; i < 3 ; i++){
        scanf("%d", &a[i]);
    }

    sort(a, a + 3);

    if(a[1] - a[0] == a[2] - a[1]){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}