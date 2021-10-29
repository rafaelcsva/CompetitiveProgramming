#include <bits/stdc++.h>

using namespace std;

string s[410];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        vector< pair< int, int > > v;
    
        for(int i = 0 ; i < n ; i++){
            cin >> s[i];

            for(int j = 0  ; j < s[i].length() ; j++){
                if(s[i][j] == '*'){
                    v.push_back({i, j});
                }
            }
        }

        s[v[0].first][v[1].second] = '*';
        s[v[1].first][v[0].second] = '*';

        if(v[1].second == v[0].second){
            if(v[1].second == 0){
                s[v[0].first][v[1].second + 1] = s[v[1].first][v[0].second + 1] = '*';
            }else{
                s[v[0].first][v[1].second - 1] = s[v[1].first][v[1].second - 1] = '*';
            }
        }else if(v[0].first == v[1].first){
            if(v[0].first == 0){
                s[v[0].first + 1][v[1].second] = s[v[1].first + 1][v[0].second] = '*';
            }else{
                s[v[0].first - 1][v[1].second] = s[v[1].first - 1][v[0].second] = '*';
            }
        }

        for(int i = 0 ; i < n ; i++){
            cout << s[i] << "\n";
        }
    }

    return 0;
}