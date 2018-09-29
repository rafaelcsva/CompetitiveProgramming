//31, 07, 2018, 12:04:31 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 1010;
char tab[N][N];
bool mark[N][N];
typedef pair<pii, int>pipii;
vector< pipii > stars;
int n, m;

bool can(int m, int i, int j){
    int l = 0;

    while(l <= m){
        if(tab[i + l][j] != '*'){
            return false;
        }

        if(tab[i - l][j] != '*'){
            return false;
        }

        if(tab[i][j + l] != '*'){
            return false;
        }

        if(tab[i][j - l] != '*'){
            return false;
        }
        
        l++;
    }

    return true;
}

void solve(int i, int j){
    int st = 1, en = min({i, j, n - i - 1, m - j - 1});
    int r = -1;

    while(st <= en){
        int mid = (st + en) / 2;

        if(can(mid, i, j)){
            r = mid;
            st = mid + 1;
        }else{
            en = mid - 1;
        }
    }

    if(r != -1){
        int l = 0;
        stars.push_back({{i + 1, j + 1}, r});

        while(l <= r){
            mark[l + i][j] = true;
            mark[i - l][j] = true;
            mark[i][j + l] = true;
            mark[i][j - l] = true;
            l++;
        }

        l = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("\n%c", &tab[i][j]);
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(tab[i][j] == '*'){
                solve(i, j);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(tab[i][j] == '*'){
                if(!mark[i][j]){
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }

    printf("%lu\n", stars.size());

    for(pipii u: stars){
        printf("%d %d %d\n", u.first.first, u.first.second, u.second);
    }

    return 0;
}