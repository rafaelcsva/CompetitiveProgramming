#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, k;

        scanf("%d %d", &n, &k);

        if(k > (n + 1) / 2 - 1){
            printf("-1\n");
        }else{
            int i = 2, j = n;
            
            printf("1");

            int pt = 1;

            while(i <= j && k){
                if(pt & 1){
                    printf(" %d", j);
                    j--;
                    k--;
                }else{
                    printf(" %d", i);
                    i++;
                }
                pt = (pt + 1) & 1;
            }

            while(i <= j){
                printf(" %d", i);
                i++;
            }
            printf("\n");
        }
    }
}