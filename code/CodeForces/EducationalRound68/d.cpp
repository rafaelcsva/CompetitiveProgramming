#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, k;

        scanf("%d %d", &n, &k);

        if(k % 3){
            if(n % 3){
                printf("Alice\n");
            }else{
                printf("Bob\n");
            }
            continue;
        }

        int r = n % (k + 1);

        if(r == k || r %  3){
            printf("Alice\n");
        }else{
            printf("Bob\n");
        }
    }

    return 0;
}