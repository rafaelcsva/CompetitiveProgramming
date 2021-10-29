#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b,&c, &d);

        if(a > b){
            swap(a,b);
        }
        if(c> d){
            swap(c, d);
        }

        if(a > max(c, d) || c > max(a, b)){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }

    return 0;
}