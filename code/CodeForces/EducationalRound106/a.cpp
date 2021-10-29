#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, k1, k2;
        int w, b;

        scanf("%d %d %d", &n, &k1, &k2);
        scanf("%d %d", &w, &b);
        
        int r = (max(k1, k2) - min(k1, k2)) / 2;
        int black = min(n - k1, n - k2) + r;
        int white = min(k1, k2) + r;

        if(w <= white && b <= black){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}