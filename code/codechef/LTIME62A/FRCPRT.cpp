//28, 07, 2018, 11:08:25 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 200;
char tab[N][N];
char s[N * N];
int n, m;

void solve(char c){
    if(c == 'L' || c == 'R'){
        for(int i = 0 ; i < n ; i++){
            int cnt_particle = 0;

            for(int j = 0 ; j < m ; j++){
                if(tab[i][j] == '1'){
                    cnt_particle++;
                }
            }

            for(int j = 0 ; j < m ; j++){
                if(j < cnt_particle){
                    tab[i][j] = '1';
                }else{
                    tab[i][j] = '0';
                }
            }

            if(c == 'R'){
                reverse(tab[i], tab[i] + m);
            }
        }
    }else{
        if(c == 'D'){
            for(int i = 0 ; i < m ; i++){
                int cnt_particle = 0;

                for(int j = 0 ; j < n ; j++){
                    if(tab[j][i] == '1'){
                        cnt_particle++;
                    }
                }

                for(int j = n - 1 ; j >= 0 ; j--){
                    if(cnt_particle){
                        tab[j][i] = '1';
                        cnt_particle--;
                    }else{
                        tab[j][i] = '0';
                    }
                }
            }
        }else{
            for(int i = 0 ; i < m ; i++){
                int cnt_particle = 0;

                for(int j = 0 ; j < n ; j++){
                    if(tab[j][i] == '1'){
                        cnt_particle++;
                    }
                }

                for(int j = 0 ; j < n ; j++){
                    if(cnt_particle){
                        tab[j][i] = '1';
                        cnt_particle--;
                    }else{
                        tab[j][i] = '0';
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){

        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < n ; i++){
            scanf("\n%s", tab[i]);
        }
        
        scanf("\n%s", s);

        int len = strlen(s);

        char last_v = 0, last_h = 0;

        for(int i = 0 ; i < len ; i++){
            if(s[i] == 'L'){
                last_h = 'L';
            }

            if(s[i] == 'R'){
                last_h = 'R';
            }

            if(s[i] == 'U'){
                last_v = 'U';
            }

            if(s[i] == 'D'){
                last_v = 'D';
            }
        }

        solve(s[0]);

        if(last_h){
            solve(last_h);
        }
        if(last_v){
            solve(last_v);
        }

        for(int i = 0 ; i < n ; i++){
            printf("%s\n", tab[i]);
        }
    }

    return 0;
}