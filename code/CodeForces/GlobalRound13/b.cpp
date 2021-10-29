#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, u, v;

        scanf("%d %d %d", &n, &u, &v);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
        }

        int mdif = 0;
        for(int i = 1 ; i < n ; i++){
            mdif = max(mdif, abs(a[i] - a[i - 1]));
        }

        if(mdif == 0){
            printf("%d\n", v + min(v, u));
        }else if(mdif == 1){
            printf("%d\n", min(u, v));
        }else{
            printf("0\n");
        }
    }

    return 0;
}