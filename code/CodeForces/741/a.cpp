#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int l, r;

        scanf("%d %d", &l, &r);

        int hf = r / 2 + 1;

        hf = max(hf, l);

        printf("%d\n", r % hf);
    }

    return 0;
}