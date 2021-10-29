#include <bits/stdc++.h>

using namespace std;

const int M = int(1e4);
const int Q = int(1e5);

int main(){
    srand(time(NULL));

    int n, m, q;

    n = 8;
    m = 256;
    q = 256;

    printf("%d %d %d\n", n, m, q);

    for(int i = 0 ; i < m ; i++){
        int num = i;

        for(int j = 0 ; j < n ; j++){
            int e = 1 << j;

            if(num & e){
                printf("1");
            }else{
                printf("0");
            }
        }
        printf("\n");
    }

    for(int i = 0 ; i < q ; i++){
        int num = i;

        for(int j = 0 ; j < n ; j++){
            int e = 1 << j;

            if(num & e){
                printf("1");
            }else{
                printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}