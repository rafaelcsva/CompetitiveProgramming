#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int h[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, k;

        scanf("%d %d", &n, &k);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &h[i]);
        }

        if(k > 10000){
            printf("-1\n");
        }else{
            int p;

            while(k){
                p = 0;
                for(; p < n - 1 ; p++){
                    if(h[p] < h[p + 1]){
                        h[p]++;
                        break;
                    }
                }
                k--;
            }

            if(p == n - 1){
                printf("-1\n");
            }else{
                printf("%d\n", p + 1);
            }
        }
    }

    return 0;
}