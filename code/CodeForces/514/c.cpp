//05, 10, 2018, 12:02:49 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    if(n > 3 && n != 6 && n != 7){
        int p = 1;
        int m = n;

        while(n){
            for(int i = 0 ; i < (n + 1) / 2 ; i++){
                printf("%d ", p);
            }

            n -= ((n + 1) / 2);

            p *= 2;

            if(n == 3){
                break;
            }
        }

        if(n){
            printf("%d %d %d", p, p, (m / p) * p);
        }

        printf("\n");

    }else{
        if(n == 1){
            printf("1\n");
        }else if(n == 2){
            printf("1 2\n");
        }else if(n == 3){
            printf("1 1 3\n");
        }else if(n == 6){
            printf("1 1 1 2 2 6\n");
        }else{
            printf("1 1 1 1 2 2 6\n");
        }
    }

    return 0;
}