#include <bits/stdc++.h>

using namespace std;

char tab[60][60];
char c[60];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        memset(tab, 0, sizeof tab);

        int n;

        scanf("%d", &n);

        vector< int > tw;

        for(int i = 0 ; i < n ; i++){
            scanf("\n%c", &c[i]);

            if(c[i] == '2'){
                tw.push_back(i);
            }
        }

        if(tw.size() > 0 && tw.size() <= 2){
            printf("NO\n");
            continue;
        }

        for(int i = 0 ; i < n ; i++){
            if(c[i] == '1'){
                for(int j = 0 ; j < n ; j++){
                    if(i == j){
                        tab[i][j] = 'X';
                    }else{
                        tab[i][j] = tab[j][i] = '=';
                    }
                }
            }
        }

        for(int i = 0 ; i < tw.size() ; i++){
            int u = tw[(i + 1) % tw.size()];
            // printf("%d->%d\n", tw[i], u);
            tab[tw[i]][u] = '+';
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == j){
                    tab[i][j] = 'X';
                }else{
                    if(tab[i][j]) continue;

                    if(tab[j][i] == '+'){
                        tab[i][j] = '-';
                    }else if(tab[j][i] == '-'){
                        tab[i][j] = '+';
                    }else{
                        tab[i][j] = '=';
                    }
                }
            }
        }

        printf("YES\n");

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                printf("%c", tab[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}