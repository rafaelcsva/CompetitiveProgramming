#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

typedef pair< int, int >    pii;
string s;
const int D = 4, M = 8, N = 1e4 + 3;
string tab[D] = {"123", "456", "789", ".0."};
ll dp[N][5][5][101];
int vi[M] = {-2, -2, -1, -1, 2,  2, 1,  1};
int vj[M] = { 1, -1,  2, -2, 1, -1, 2, -2};
int b[110];
int n, m, k;
const ll mod = 1e9 + 7;

pii get_pos(int number){
    for(int i = 0 ; i < D ; i++){
        for(int j = 0 ; j < tab[i].length() ; j++){
            if(tab[i][j] == number + '0'){
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

void kmpPreprocess(){
    int i = 0, j = -1;
    b[0] = -1;

    while(i < m){
        while(j >= 0 && s[i] != s[j]) j = b[j];

        i++; j++;
        b[i] = j;
    }
}

bool ok(int i, int j){
    return 0 <= i && i < D && 0 <= j && j < 3 && tab[i][j] != '.';
}

ll solve(int taked, int i, int j, int pos){
    // cout << taked << " " << i << " " << j << " " << pos << endl;
    
    if(pos == m && m != 0){
        return 0LL;
    }
    // cout << "HERE0" << endl;

    if(taked == n){
        return 1LL;
    }
    // cout << "HERE" << endl;
    
    ll &ans = dp[taked][i][j][pos];

    if(ans != -1LL){
  //      cout << "AQUI" << endl;
        return ans;
    }

    ans = 0LL;

    for(int k = 0 ; k < M ; k++){
        int xi = vi[k] + i;
        int xj = vj[k] + j;

        if(ok(xi, xj)){
            // cout << "X = " << xi << " " << xj << endl;
         //   cout << "AQUI" << endl;
            if(m == 0 || tab[xi][xj] == s[pos]){
                // cout << "AQUI1" << endl;
                ans += solve(taked + 1, xi, xj, min(pos + 1, m));
                ans %= mod;
            }else{
                int tpos = pos;
                // cout << "AQUI2" << endl;
                while(tpos >= 0 && tab[xi][xj] != s[tpos]) tpos = b[tpos];
                tpos++;

                ans += solve(taked + 1, xi, xj, tpos);
                
                ans %= mod;
                // cout << "ACABOU2" << endl;
            }
        }
    }

    return ans;
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    if(m){
        cin >> s;
    }
    
    kmpPreprocess();
    
    memset(dp, -1LL, sizeof dp);
    
    pii pos = get_pos(k);
    // cout << pos.first << " " << pos.second << endl;
    cout << solve(0, pos.first, pos.second, 0) << endl;
    return 0;
}