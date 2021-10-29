#include <bits/stdc++.h>

using namespace std;

const int N = int(5e4) + 10;
string s[N];
string x;
int n;
int pos[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> n;

    for(int i = 0 ; i < x.length() ; i++){
        pos[x[i]] = i;
    }

    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
    
        for(int j = 0 ; j < s[i].length() ; j++){
            s[i][j] = pos[s[i][j]] + 'a';
        }
    }

    sort(s, s + n);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < s[i].length() ; j++){
            s[i][j] = x[s[i][j] - 'a'];
        }
    }

    for(int i = 0 ; i < n ; i++){
        cout << s[i] << "\n";
    }
    return 0;
}