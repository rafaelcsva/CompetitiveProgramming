#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
const int D = 20;
int last[D][N];
int a[N];
int xxor[N];
const int E = 1000;

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
        xxor[i] = a[i] ^ xxor[i - 1];
    }

    int lst = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int d = 0 ; d < D ; d++){
            int e = 1 << d;

            if(xxor[i] & e){
                last[d][i + 1] = i;
            }
        }
    }

    int ans = int(1e9);

    for(int i = 2 ; i <= n - 1 ; i++){
        for(int d = 0 ; d < D ; d++){
            int e = 1 << d;

            if((xxor[i] & e) == 0){
                int ls = last[d][i];

                int num = xxor[i] ^ xxor[ls];

                if(num > a[i + 1]){
                    ans = min(ans, i - ls - 1);
                }
            }
        }
    }

    printf("%d\n", ans == int(1e9) ? -1 : ans);

    return 0;
}