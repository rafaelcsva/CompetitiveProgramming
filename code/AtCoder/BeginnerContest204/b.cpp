#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    scanf("%d", &n);

    int sum = 0;

    for(int i = 0 ; i < n ;i++){
        int ai;

        scanf("%d", &ai);

        sum += max(ai - 10, 0);
    }

    printf("%d\n", sum);

    return 0;
}