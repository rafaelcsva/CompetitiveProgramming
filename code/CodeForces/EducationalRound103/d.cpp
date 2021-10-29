#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;

const int N = int(3e5) + 10;
int sz[N][2];
pii father[N][2];
int n;
string s;

pii find(pii a){
    if(father[a.first][a.second] == a){
        return father[a.first][a.second];
    }

    return father[a.first][a.second] = find(father[a.first][a.second]);
}

void join(pii a, pii b){
    auto x = find(a);
    auto y = find(b);

    if(x != y){
        if(x > y){
            father[x.first][x.second] = y;
            sz[y.first][y.second] += sz[x.first][x.second];
        }else{
            father[y.first][y.second] = x;
            sz[x.first][x.second] += sz[y.first][y.second];
        }
    }
}

char rev(char c){
    return c == 'L' ? 'R' : 'L';
}

void dfs(pii a){
    // printf("%d %d (%d, %d)\n", a.first, a.second, find(a).first, find(a).second);
    int idx = a.first;
    int r = a.second;

    if(idx < n){
        char d = s[idx];

        if(r){
            d = rev(d);
        }

        if(d == 'R'){
            if(find({idx + 1, !r}) != find(a)){
                join({idx + 1, !r}, a);
                dfs({idx + 1, !r});
            }
        }
    }

    if(idx > 0){
        char d = s[idx - 1];

        if(r){
            d = rev(d);
        }
        if(d == 'L'){
            if(find({idx - 1, !r}) != find(a)){
                join({idx - 1, !r}, a);
                dfs({idx - 1, !r});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;
    while(t--){

        cin >> n;
        cin >> s;

        for(int i = 0 ; i <= n ; i++){
            for(int d = 0 ; d <= 1 ; d++){
                father[i][d] = {i, d};
                sz[i][d] = 1;
            }
        }
        // dfs({1, 0});
        for(int i = 0 ; i <= n ; i++){
            dfs({i, 0});

            auto u = find({i, 0});

            printf("%d ", sz[u.first][u.second]);
        }

        printf("\n");
    }

    return 0;
}