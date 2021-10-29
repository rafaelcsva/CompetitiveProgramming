#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        int n, m, a, b;

        scanf("%d %d %d %d", &n, &m, &a, &b);
        
        printf("Case #%d: ", test);

        if(min(a, b) < n + m - 1){
            printf("Impossible\n");
        }else{
            printf("Possible\n");
            for(int i = 1 ; i <= n ; i++){
                for(int j = 1 ; j <= m ; j++){
                    if(i == 1 && j == 1){
                        printf("%d", a - (n + m - 2));
                    }else if(i == 1 && j == m){
                        printf("%d", b - (n + m - 2));
                    }else{
                        printf("1");
                    }

                    printf("%c", j == m ? '\n' : ' ');
                }
            }
        }
    }

    return 0;
}