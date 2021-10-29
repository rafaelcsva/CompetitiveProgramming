#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
bool markedp[N];
bool markedk[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            int ki;

            scanf("%d", &ki);

            int fi = -1;

            for(int j = 0 ; j < ki ; j++){
                int xi;

                scanf("%d", &xi);

                if(!markedk[xi] && fi == -1){
                    fi = xi;
                }
            }

            if(fi != -1){
                // printf("%d-%d\n", i, fi);
                markedp[i] = markedk[fi] = true;
            }
        }

        int pr = -1;
        int kg = -1;

        for(int i = 1 ; i <= n ; i++){
            if(!markedp[i]){
                pr = i;
            }
            if(!markedk[i]){
                kg = i;
            }
            markedp[i] = markedk[i] = false;
        }

        if(pr != -1 && kg != -1){
            printf("IMPROVE\n%d %d\n", pr, kg);
        }else{
            printf("OPTIMAL\n");
        }
    }

    return 0;
}