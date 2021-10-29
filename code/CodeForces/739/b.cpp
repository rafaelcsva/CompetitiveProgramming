#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        if(a > b){
            swap(a, b);
        }

        int d = b - a;

        if(max({a, b, c}) > 2 * d){
            printf("-1\n");
        }else{
            int o = (c + d) % (2 * d);
        
            if(o == 0){
                o = 2 * d;
            }

            printf("%d\n", o);
        }
    }

    return 0;
}