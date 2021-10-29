#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N];

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        int sum = 0;

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);

            sum += a[i];
        }

        bool is_prime = true;

        for(int j = 2 ; j * j <= sum ; j++){
            if(sum % j == 0 && j != sum){
                is_prime = false;
            }
        }

        if(!is_prime){
            printf("%d\n", n);

            for(int i = 1 ; i <= n ; i++){
                printf("%d ", i);
            }
            printf("\n");
        }else{
            printf("%d\n", n - 1);
            bool taked = false;

            for(int i = 1 ; i <= n ; i++){
                if(a[i - 1] & 1 && !taked){
                    taked = true;
                    continue;
                }

                printf("%d ", i);
            }
            printf("\n");
        }
    }

    return 0;
}