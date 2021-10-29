#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, w;

    scanf("%d %d %d", &a, &b, &w);

    w *= 1000;

    int ans1 = w + 1;
    int ans2 = 0;

    for(int i = 1 ; i <= w ; i++){
        int v = w / i;
        int r = w % i;
        int v1 = v;

        if(r){
            v++;
        }

        if(v1 >= a && v <= b){
            ans1 = min(ans1, i);
            ans2 = max(ans2, i);
        }
    }

    if(ans2 == 0){
        printf("UNSATISFIABLE\n");
    }else{
        printf("%d %d\n", ans1, ans2);
    }

    return 0;
}