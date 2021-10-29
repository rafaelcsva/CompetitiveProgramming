#include <bits/stdc++.h>

using namespace std;

const int D = 30;

const int N = int(1e4) + 10;
int v[N];

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    int or12, and12, or13, and13, and23;

    printf("or 1 2\n");
    fflush(stdout);
    scanf("%d", &or12);

    printf("and 1 2\n");
    fflush(stdout);
    scanf("%d", &and12);

    printf("or 1 3\n");
    fflush(stdout);
    scanf("%d", &or13);

    printf("and 1 3\n");
    fflush(stdout);
    scanf("%d", &and13);

    printf("and 2 3\n");
    fflush(stdout);
    scanf("%d", &and23);

    for(int i = 0 ; i < D ; i++){
        int e = 1 << i;

        if((or12 & e) == 0 || (or13 & e) == 0){
            continue;
        }

        if((and12 & e) || (and13 & e) || (and23 & e) == 0){
            v[1] |= e;
        }
    }

    for(int i = 0 ; i < D ; i++){
        int e = 1 << i;

        if((v[1] & e)){
            if(and12 & e){
                v[2] |= e;
            }

            if(and13 & e){
                v[3] |= e;
            }
        }else{
            if(or12 & e){
                v[2] |= e;
            }

            if(or13 & e){
                v[3] |= e;
            }
        }
    }

    for(int i = 4 ; i <= n ; i++){
        int orx;
        int andx;

        printf("or 1 %d\n", i);
        fflush(stdout);
        scanf("%d", &orx);

        printf("and 1 %d\n", i);
        fflush(stdout);
        scanf("%d", &andx);

        for(int j = 0 ; j < D ; j++){
            int e = 1 << j;

            if((v[1] & e) == 0){
                if(orx & e){
                    v[i] |= e;
                }
            }else{
                if(andx & e){
                    v[i] |= e;
                }
            }
        }
    }

    sort(v + 1, v + 1 + n);

    printf("finish %d\n", v[k]);

    fflush(stdout);

    return 0;
}
