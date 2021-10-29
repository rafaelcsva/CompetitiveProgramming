#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 62;
ll c[N][N];

int main(){
    for(int i = 0 ; i < N ; i++){
        c[i][i] = c[i][0] = 1LL;
        for(int j = 1 ; j < i ; j++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }

    int a, b;
    ll k;

    cin >> a >> b >> k;

    string ans = "";
    while(k && a){
        // cout << k << " " << a <<  " " << b << endl;
        if(c[a - 1 + b][a - 1] >= k){
            ans.push_back('a');
            a--;
        }else{
            ans.push_back('b');
            k -= (c[a + b - 1][a - 1]);
            b--;
        }
    }

    while(a){
        ans.push_back('a');
        a--;
    }

    while(b){
        ans.push_back('b');
        b--;
    }

    cout << ans << endl;

    return 0;
}