#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int te;

    cin >> te;

    while(te--){
        string s, t, p;

        cin >> s >> t >> p;

        queue< char > q;

        for(auto c: s){
            q.push(c);
        }

        string ft = "";

        for(auto c: t){
            if(!q.empty() && q.front() == c){
                q.pop();
                continue;
            }

            ft.push_back(c);
        }

        // cout << " ft = " << ft << "\n";
        if(!q.empty()){
            cout << "NO\n";
        }else{
            multiset< char > mst;

            for(auto c: p){
                mst.insert(c);
            }

            bool frag = true;
        
            for(auto c: ft){
                auto u = mst.find(c);

                if(u == mst.end()){
                    frag = false;
                    break;
                }

                mst.erase(u);
            }

            if(frag){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }

    return 0;
}