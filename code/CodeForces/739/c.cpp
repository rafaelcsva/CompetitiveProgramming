#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int k;

        scanf("%d", &k);

        int c = 1;
        int r = 1;

        while(k > r){
            k -= r;
            c++;
            r += 2;
        }

        int row = 1, col = c;

        if(k <= c){
            row = k;
        }else{
            row = c;
            k -= c;
            col -= k;
        }

        printf("%d %d\n", row, col);
    }

    return 0;
}