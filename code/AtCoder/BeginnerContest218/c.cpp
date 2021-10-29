#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;
const int N = int(210);
string s[N], t[N], tmp[N];

bool equal(pii a, pii b, int n){
    for(int  i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(s[(i + a.first) % n][(j + a.second) % n] != t[(i + b.first) % n][(j + b.second) % n]){
                // if(a == make_pair(1, 1)){
                //     cout << "on " << i << " " << j << " " << (i + a.first) % n << "\n";
                // }
                return false;
            }
        }
    }
    
    return true;
}

void rotate(int n, int d = 0){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[n - j - 1][i] = s[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s[i][j] = tmp[i][j];
        }
    }
}

void print(int n){
    cout << "*****\n";
    for(int i =0  ; i< n ; i++){
        cout << s[i] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
        tmp[i] = s[i];
    }

    for(int i = 0 ; i < n ; i++){
        cin >> t[i];
    }

    pair< int, int > xt = {n - 1, n - 1};
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(t[i][j] == '#'){
                xt.first = min(xt.first, i);
                xt.second = min(xt.second, j);
            }
        }
    }

    for(int d = 0 ; d <= 4 ; d++){
        pair< int, int > xs = {n - 1, n - 1};

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(s[i][j] == '#'){
                    xs.first = min(xs.first, i);
                    xs.second = min(xs.second, j);
                }
            }
        }

        if(equal(xs, xt, n)){
            cout << "Yes\n";
            return 0;
        }

        rotate(n, d);
    }

    cout << "No\n";
    return 0;
}