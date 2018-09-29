#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char c[] = {'L', 'R', 'D', 'U'};

int main(){
    int T = 100;
    srand(time(NULL));

    printf("%d\n", T);

    while(T--){
        int n, m;
        
        n = rand() % 10 + 1, m = rand() % 10 + 1;

        printf("%d %d\n", n, m);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                printf("%d", rand() % 2);
            }
            printf("\n");
        }

        for(int i = 0 ; i < 4 ; i++){
            printf("%c", c[rand() % 4]);
        }
        printf("\n");
    }

    return 0;
}