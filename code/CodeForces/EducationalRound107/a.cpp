#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d",&n);

        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            int xi;

            scanf("%d", &xi);

            cnt += (xi == 1 || xi == 3);
        }

        printf("%d\n", cnt);
    }

    return 0;
}