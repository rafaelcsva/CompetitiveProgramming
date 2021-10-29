#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int x;

        scanf("%d", &x);

        int st = 1;
        int ans = 0;

        while(x >= st){
            x -= st;
            ans++;
            st += 2;
        }

        if(x > 0){
            ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}