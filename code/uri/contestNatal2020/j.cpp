#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 10;
int a[N];

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    int x = 0;

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
        x ^= (a[i] % (k + 1));
    }

    if(x == 0){
        printf("Dila\n");
    }else{
        printf("Dali\n");
    }

    return 0;
}