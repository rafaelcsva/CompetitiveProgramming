#include <bits/stdc++.h>

using namespace std;

const int D = 30;
vector< int > con[D][2];
string s, t;

bool solve(int p, int j, int last){
    if(j == t.length()){
        return true;
    }

    int lt = t[j] - 'a';
    int pos = upper_bound(con[lt][p].begin(), con[lt][p].end(), last) - con[lt][p].begin();

    if(pos == con[lt][p].size()){
        return false;
    }

    return solve(!p, j + 1, con[lt][p][pos]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int te;

    cin >> te;

    while(te--){

        cin >> s >> t;

        s.push_back('z');
        t.push_back('z');

        for(int i = 0 ; i < s.length() ; i++){
            con[s[i] - 'a'][i & 1].push_back(i);
        }

        if(solve(0, 0, -1) || solve(1, 0, -1)){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }

        for(int d = 0 ;d < D ; d++){
            con[d][0].clear();
            con[d][1].clear();
        }
    }

    return 0;
}