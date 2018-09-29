#include <bits/stdc++.h>

using namespace std ;

typedef pair< int, int >    pii;
const int N = int(1e5 + 100);

bool dp1[N][2], dp2[N][2];
char s[N], t[N];

int main() {
    int test;

    scanf("%d", &test);

    while(test--){
        scanf("\n%s", s);
        scanf("\n%s", t);

        int m = strlen(s);
        int n = strlen(t);

        for(int i = 1 ; i <= m ; i++){
            if(i == 1){
                if(s[i - 1] == '0' || t[i - 1] == '0'){
                    dp1[i][0] = true;
                }else{
                    dp1[i][0] = false;
                }
            }else{
                if(s[i - 1] == '0' || !dp1[i - 1][0]){
                    dp1[i][0] = true;
                }else{
                    dp1[i][0] = false;
                }
            }
        }

        for(int i = 1 ; i <= n ; i++){
            if(i == 1){
                if(s[i - 1] == '0' || t[i - 1] == '0'){
                    dp2[i][0] = true;
                }else{
                    dp2[i][0] = false;
                }
            }else{
                if(t[i - 1] == '0' || !dp2[i - 1][0]){
                    // printf("%d eh verdade! %d\n", i, dp2[i - 1][0]);
                    dp2[i][0] = true;
                }else{
                    dp2[i][0] = false;
                }
            }
        }

        if(n > 1){
            for(int i = 1 ; i <= m ; i++){
                if(i == 1){
                    if(!dp1[i][0] || dp2[i + 1][0]){
                        dp1[i][1] = true;
                    }else{
                        dp1[i][1] = false;
                    }
                }else{
                    if(!dp1[i - 1][1] || !dp1[i][0]){
                        dp1[i][1] = true;
                    }else{
                        dp1[i][1] = false;
                    }
                }
            }
        }

        if(m > 1){
            for(int i = 1 ; i <= n ; i++){
                if(i == 1){
                    if(!dp2[i][0] || dp1[i + 1][0]){
                        dp2[i][1] = true;
                    }else{
                        dp2[i][1] = false;
                    }
                }else{
                    if(!dp2[i][0] || !dp2[i - 1][1]){
                        dp2[i][1] = true;
                    }else{
                        dp2[i][1] = false;
                    }
                }
            }
        }

        int q;

        scanf("%d", &q);

        while(q--){
            int x, y;

            scanf("%d %d", &x, &y);

            if(x == 1 || y == 1){
                if(x >= y){
                    if(dp2[x][0]){
                        printf("1");
                    }else{
                        printf("0");
                    }
                }else{
                    if(dp1[y][0]){
                        printf("1");
                    }else{
                        printf("0");
                    }
                }
            }else{
                int mn = min(x, y) - 2;

                if(x >= y){
                    if(dp2[x - mn][1]){
                        printf("1");
                    }else{
                        printf("0");
                    }
                }else{
                    if(dp1[y - mn][1]){
                        printf("1");
                    }else{
                        printf("0");
                    }
                }
            }
        }

        printf("\n");
    }

	return 0;
}