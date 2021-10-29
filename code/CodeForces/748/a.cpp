#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;

    int t;

    scanf("%d", &t);

    while(t--){
        scanf("%d %d %d", &a, &b, &c);

        printf("%d %d %d\n", max({b - a + 1, c - a + 1, 0}), max({a - b + 1, c - b + 1, 0}), max({a - c + 1, b - c + 1, 0}));
    }
    
    return 0;
}