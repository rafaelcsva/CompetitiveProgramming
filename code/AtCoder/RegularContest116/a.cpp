#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        long long n;

        scanf("%lld", &n);
        if(n & 1LL){
            printf("Odd\n");
        }else{
            if(n % 4LL == 0LL){
                printf("Even\n");
            }else{
                printf("Same\n");
            }
        }
    }

    return 0;
}