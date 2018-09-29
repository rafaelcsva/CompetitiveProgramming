#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 4;
char t[N][N];
int ii, jj;
const int M = 7;

// int add(char c, int i, int j){
//     int p = i * N + j;
//     int k = c == 'x' ? 1 : 2;

//     int p = 1;

//     for(int i = 0 ; i < p ; i++){
//         p *= 10;
//     }

//     return p * k;
// }

bool i_win(char c){
    bool col = false, lin = false, dia1 = true, dia2 = true;

    for(int i = 0 ; i < N ; i++){
        bool tmp = true;
        for(int j = 0 ; j < N ; j++){
            tmp &= t[i][j] == c;
        }

        col |= tmp;
    }

    for(int i = 0 ; i < N ; i++){
        bool tmp = true;
        for(int j = 0 ; j < N ; j++){
            tmp &= t[j][i] == c;
        }

        lin |= tmp;
    }

    for(int i = 0, j = 0 ; i < N ; i++, j++){
        dia1 &= t[i][j] == c;
    }

    for(int i = 0, j = N - 1; i < N ; i++, j--){
        dia2 &= t[i][j] == c;
    }

    return col || lin || dia1 || dia2;
}

int solve(int game){ // 1 to win, 0 to draw, -1 to lose.
    if(game >= M){
        return 0;
    }

    char c = (game & 1) ? 'o' : 'x';

    int best = -1;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(t[i][j] == '.'){
                t[i][j] = c;

                if(i_win(c)){
                    t[i][j] = '.';
                    ii = i, jj = j;
                    return 1;
                }

                int r = solve(game + 1);

                t[i][j] = '.';

                if(r == 0){
                    best = 0;
                }

                if(r == -1){
                    ii = i, jj = j;
                    return 1;
                }
            }
        }
    }

    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    char c;

    while(scanf("\n%c", &c) != EOF){
        if(c == '$')
            break;

        int mask = 0;

        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                scanf("\n%c", &t[i][j]);
                // mask += add(t[i][j], i, j);
            }
        }

        if(solve(0) == 1){
            printf("(%d,%d)\n", ii, jj);
        }else{
            printf("#####\n");
        }
    }

    return 0;
}