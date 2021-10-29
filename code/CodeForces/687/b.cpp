#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int a[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, k;

        scanf("%d %d", &n, &k);
    
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
        }

        int ans = int(1e9);

        for(int color = 1 ; color <= 100 ; color++){
            int i = 0;
            int day = 0;

            while(i < n){
                if(a[i] != color){
                    i += k;
                    day++;
                }else{
                    i++;
                }
            }

            ans = min(ans, day);
        }

        printf("%d\n", ans);
    }

    return 0;
}