#include <bits/stdc++.h>

using namespace std;

const int N = 20, F = 30, TAM = 500;
int dp1[N][N][F][TAM], used1[N][N][F][TAM], dp2[N][N][F][TAM], used2[N][N][F][TAM];
const int mod = 20437;
const int INF = int(1e5);
int vi[] = {-1, 1, 0, 0}, vj[] = {0, 0, -1, 1};
int n, m, l;
char tab[N][N];
int test = 1;

bool ok(int i, int j, int food){
    return i >= 0 && i < n && j >= 0 && j < n && (tab[i][j] == '.' || tab[i][j] <= char('A' + food)) && tab[i][j] != '#';
}
//posicao (i, j) , comida atual, tamanho do caminho
int solve1(int i, int j, int food, int tam){
    if(food == l){
        return tam;
    }

    if(tam >= TAM){
        return INF;
    }

    int &ans = dp1[i][j][food][tam];

    if(used1[i][j][food][tam] == test){
        return ans;
    }
    used1[i][j][food][tam] = test;

    ans = INF;

    if(tab[i][j] == char('A' + food)){
        return ans = solve1(i, j, food + 1, tam);
    }

    for(int k = 0 ; k < 4 ; k++){
        int ti = vi[k] + i, tj = vj[k] + j;

        if(ok(ti, tj, food)){
            ans = min(ans, solve1(ti, tj, food, tam + 1));
        }
    }

    return ans;
}

int solve2(int i, int j, int food, int tam){
    if(tam == m && food == l){
        return 1;
    }

    if(tam > TAM){
        return 0;
    }

    int &ans = dp2[i][j][food][tam];

    if(used2[i][j][food][tam] == test){
        return ans;
    }
    used2[i][j][food][tam] = test;
    ans = 0;
    
    if(tab[i][j] == char('A' + food)){
        return ans = solve2(i, j, food + 1, tam);
    }

    for(int k = 0 ; k < 4 ; k++){
        int ti = i + vi[k], tj = j + vj[k];

        if(ok(ti, tj, food)){
            ans += solve2(ti, tj, food, tam + 1);
            ans %= mod;
        }
    }

    return ans;
}

int main (){
    while(cin >> n){
        if(n == 0){
            break;
        }

        int ini = 0, inj = 0;
        l = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> tab[i][j];

                if(tab[i][j] == 'A'){
                    ini = i, inj = j;
                }

                if(tab[i][j] >= 'A' && tab[i][j] <= 'Z'){
                    l++;
                }
            }
        }

        m = solve1(ini, inj, 0, 0);

        cout << "Case " << test << ": ";

        if(m >= INF){
            cout << "Impossible" << endl;
        }else{
            cout << m << ' ' << solve2(ini, inj, 0, 0) << endl;
        }

        test++;
    }

    return 0;
}