#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int r, b, d;

        scanf("%d %d %d", &r, &b, &d);

        int x = min(r, b);
        int y = max(r, b);
        int ult = y / x + ((y % x) ? 1 : 0);
    
        if(ult - 1 > d){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }

    return 0;
}