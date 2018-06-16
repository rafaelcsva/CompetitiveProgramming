//24, 05, 2018, 10:41:32 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
vector<pii>col, lin;

const int N = 110;
int g[N][N];
int tmp[N][N];
int n, m;

void print(vector<pii>&v){
    cout << v.size() << endl;
    
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i].first == 1){
            cout << "row ";
        }else{
            cout << "col ";
        }

        cout << v[i].second << endl;
    }
}

int get_min_col(int x){
    int r = 1000;
    
    for(int i = 0 ; i < n ; i++){
        int diff = g[i][x] - tmp[i][x];

        r = min(r, diff);
    }

    return r;
}

int get_min_lin(int x){
    int r = 1000;

    for(int i = 0 ; i < m ; i++){
        int diff = g[x][i] - tmp[x][i];
        
        r = min(r, diff);
    }

    return r;
}

int get_max_col(int x){
    int r = -1;
    
    for(int i = 0 ; i < n ; i++){
        int diff = g[i][x] - tmp[i][x];
        
        r = max(r, diff);
    }

    return r;
}

int get_max_lin(int x){
    int r = -1;

    for(int i = 0 ; i < m ; i++){
        
        int diff = g[x][i] - tmp[x][i];
        
        r = max(r, diff);
    }

    return r;
}


bool is_equal(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(tmp[i][j] != g[i][j])
                return false;
        }
    }

    return true;
}

bool try_col(){
    for(int i = 0 ; i < m ; i++){
        int r = get_min_col(i);

        int tr = r;
        
        while(tr--) {
            col.push_back({2, i + 1});
        }
        
        for(int x = 0 ; x < n ; x++){
            tmp[x][i] += r;
        }
    }

    for(int i = 0 ; i < n ; i++){
        int r = get_max_lin(i);
        int tr = r;
        
        while(tr--){
            col.push_back({1, i + 1});
        }

        for(int x = 0 ; x < m ; x++){
            tmp[i][x] += r;
        }
    }

    bool ok = is_equal();

    memset(tmp, 0, sizeof tmp);

    return ok;
}

void printTable(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << tmp[i][j] << ' ';
        }

        cout << endl;
    }
}

bool try_lin(){
    for(int i = 0 ; i < n ; i++){
        int r = get_min_lin(i);
        int tr = r;
        // cout << tr << endl;
        while(tr--){
            lin.push_back({1, i + 1});
        }    

        for(int x = 0 ; x < m ; x++){
            tmp[i][x] += r;
        }
    }
    // printTable();
    
    for(int i = 0 ; i < m ; i++){
        int r = get_max_col(i);
        // cout << i << ' ' << r << endl;
        int tr = r;

        while(tr--) {
            lin.push_back({2, i + 1});
        }
        
        for(int x = 0 ; x < n ; x++){
            tmp[x][i] += r;
        }
    }

    bool ok = is_equal();
    
    return ok;
}

int main(){
    
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> g[i][j];
        }
    }    

    bool okcol = false, oklin = false;

    okcol = try_col();
    oklin = try_lin();

    if(okcol || oklin){
        if(!oklin){
            print(col);
        }else if(!okcol){
            print(lin);
        }else{
            if(col.size() < lin.size()){
                print(col);
            }else{
                print(lin);
            }
        }
    }else{
        cout << "-1" << endl;
    }

    return 0;
}