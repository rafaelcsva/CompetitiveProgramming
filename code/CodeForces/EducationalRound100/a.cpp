#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        int x = min({a, b, c});
        int s = (a - x) + (b - x) + (c - x);
        if(6 * x >= s && (a + b + c) % 9 == 0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}