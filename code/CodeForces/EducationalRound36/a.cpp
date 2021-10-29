#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    int ans = k + 1;

    for(int i = 0 ; i < n ; i++){
        int ai;

        scanf("%d", &ai);

        if(k % ai == 0){
            ans = min(ans, k / ai);
        }
    }

    printf("%d\n", ans);

    return 0;
}