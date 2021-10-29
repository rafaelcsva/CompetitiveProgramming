#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        int sum = 0;

        for(int i = 0 ; i < n ; i++){
            int ai;

            scanf("%d", &ai);
            sum += ai;
        }

        if(sum < n){
            printf("1\n");
        }else{
            printf("%d\n", sum - n);
        }
    }

    return 0;
}