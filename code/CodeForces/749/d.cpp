#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N];

int main(){
    int n;

    scanf("%d", &n);

    int an = 1;

    int d = 2;

    while(d <= n){
        printf("?");

        for(int i = 1 ; i <= n - 1 ; i++){
            printf(" %d", d);
        }
        printf(" %d\n", 1);
        fflush(stdout);

        int ans;

        scanf("%d", &ans);

        if(ans == 0){
            break;
        }

        an++;
        d++;
    }

    int r = n + 1 - an;
    d = 1;
    a[n] = an;

    while(d <= n){
        printf("?");

        for(int i = 1 ; i <= n - 1 ; i++){
            printf(" %d", d);
        }
        printf(" %d\n", r);
        fflush(stdout);

        int ans;

        scanf("%d", &ans);

        if(ans != 0){
            a[ans] = n - d + 1;
        }

        d++;
    }

    printf("!");

    for(int i = 1 ; i <= n ; i++){
        printf(" %d", a[i]);
    }
    printf("\n");
    fflush(stdout);

    return 0;
}