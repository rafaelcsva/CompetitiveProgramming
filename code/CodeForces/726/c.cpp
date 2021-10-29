#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int a[N];
int h[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &h[i]);
        }

        sort(h, h + n);

        if(n == 2){
            for(int i = 0 ; i < n ; i++){
                printf("%d ", h[i]);
            }
            printf("\n");
        }else{
            int ans = int(1e9) + 1;
            int ansi = 0;

            for(int i = 1 ; i < n ; i++){
                if(h[i] - h[i - 1] < ans){
                    ansi = i;
                    ans = h[i] - h[i - 1];
                }
            }

            vector< int > f1, f2;

            for(int i = 0 ; i < n ; i++){
                if(i == ansi - 1 || i == ansi){
                    continue;
                }
                if(i < ansi){
                    f1.push_back(h[i]);
                }else{
                    f2.push_back(h[i]);
                }
            }
            printf("%d ", h[ansi - 1]);

            for(auto u: f2){
                printf("%d ", u);
            }
            for(auto u: f1){
                printf("%d ", u);
            }
            printf("%d\n", h[ansi]);
        }
    }

    return 0;
}