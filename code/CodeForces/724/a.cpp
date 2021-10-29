#include <bits/stdc++.h>

using namespace std;

int mark[200];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        bool frag = false;
    
        for(int i = 0 ; i < n ; i++){
            int ai;

            scanf("%d", &ai);
            if(ai < 0){
                frag = true;
            }
        }

        if(frag){
            printf("no\n");
        }else{
            printf("yes\n");
            printf("201\n");

            for(int i = 0 ; i <= 200 ; i++){
                printf("%d ", i);
            }
            printf("\n");
        }
    }

    return 0;
}