#include <bits/stdc++.h>

using namespace std;

const int N = 55;
char tab[N][N];

int n;

int solve_lin(int row){
    int tmp = 0;

    for(int j = 0 ; j < n ; j++){
        if(tab[row][j] == 'O'){
            return int(1e9);
        }

        if(tab[row][j] == '.'){
            tmp++;
        }
    }

    return tmp;
}

int solve_col(int col){
    int tmp = 0;

    for(int j = 0 ; j < n ; j++){
        if(tab[j][col] == 'O'){
            return int(1e9);
        }

        if(tab[j][col] == '.'){
            tmp++;
        }
    }

    return tmp;
}

set< pair< int, int > > get_lin(int row){
    set< pair< int, int > > st;

    for(int j = 0 ; j < n ; j++){
        if(tab[row][j] == '.'){
            st.insert({row, j});
        }
    }

    return st;
}

set< pair< int, int > > get_col(int col){
    set< pair< int, int > > st;

    for(int j = 0 ; j < n ; j++){
        if(tab[j][col] == '.'){
            st.insert({j, col});
        }
    }

    return st;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                scanf("\n%c", &tab[i][j]);
            }
        }

        int best = int(1e9);
        for(int i = 0 ; i < n ; i++){
            best = min(best, solve_lin(i));
            best = min(best, solve_col(i));
        }

        printf("Case #%d: ", test);

        int cnt = 0;

        set< set< pair< int, int > > > st;

        for(int i = 0 ; i < n ; i++){
            int te = 0;

            if(solve_lin(i) == best){
                st.insert(get_lin(i));
            }

            if(solve_col(i) == best){
                st.insert(get_col(i));
            }
        }

        if(best == int(1e9)){
            printf("Impossible\n");
        }else{
            printf("%d %lu\n", best, st.size());
        }
    }
    
    return 0;
}
