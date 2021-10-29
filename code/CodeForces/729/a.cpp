#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        int cnt[2];
        cnt[0] = cnt[1] = 0;

        scanf("%d", &n);

        for(int i = 0 ; i < 2 * n ; i++){
            int ai;

            scanf("%d", &ai);
            cnt[ai & 1]++;
        }

        if(cnt[0] == cnt[1]){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

    return 0;
}