#include <bits/stdc++.h>

using namespace std;

int a[110];
int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        int mn = 110;
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
            mn = min(mn, a[i]);
        }

        int cnt = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(mn != a[i]){
                cnt++;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}