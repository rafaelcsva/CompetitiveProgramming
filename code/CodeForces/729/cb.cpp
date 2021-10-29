#include <bits/stdc++.h>

using namespace std;

int f(int x){
    for(int j = 1 ; j <= x + 1 ; j++){
        if(x % j){
            return j;
        }
    }

    assert(false);
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        int ans = 0;
        
        for(int i = 1 ; i <= n ; i++){
            ans += f(i);
        }

        printf("%d\n", ans);
    }

    return 0;
}