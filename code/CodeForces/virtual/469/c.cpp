#include <bits/stdc++.h>

using namespace std;

set<int>q0, q1;
vector<vector<int> > adj;

int main(){
    string s;

    ios::sync_with_stdio(false);

    cin >> s;

    bool ok = true;
    
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '0'){
            if(q1.size() == 0){
                q0.insert(adj.size());
                adj.push_back({i + 1});
            }else{
                int idx = *(q1.begin());
                adj[idx].push_back(i + 1);
                q0.insert(idx);
                q1.erase(idx);
            }
        }else{
            if(q0.size() != 0){
                int idx = *(q0.begin());
                adj[idx].push_back(i + 1);
                q1.insert(idx);
                q0.erase(idx);
            }else{
                ok = false;
                break;
            }
        }
    }

    if(ok && q1.size() == 0){
        cout << adj.size() << endl;

        for(int i = 0 ; i < adj.size() ; i++){
            cout << adj[i].size();

            for(int j = 0 ; j < adj[i].size() ; j++){
                cout << ' ' << adj[i][j];
            }

            cout << endl;
        }
    }else{
        cout << -1 << endl;
    }

    return 0;
}