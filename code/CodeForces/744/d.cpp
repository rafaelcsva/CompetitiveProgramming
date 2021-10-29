#include <bits/stdc++.h>

using namespace std;

priority_queue< pair< int, int > > pq;
vector< int > ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 1 ; i <= n ; i++){
            int ai;

            cin >> ai;
            if(ai){
                pq.push({ai, i});
            }    
        }

        while(pq.size() >= 2){
            auto u = pq.top();
            pq.pop();
            auto v = pq.top();
            pq.pop();

            ans.push_back(u.second);
            ans.push_back(v.second);

            u.first--;
            v.first--;

            if(u.first){
                pq.push(u);
            }

            if(v.first){
                pq.push(v);
            }
        }

        while(!pq.empty()){
            pq.pop();
        }

        cout << (ans.size() / 2) << "\n";
    
        for(int i = 0 ; i < ans.size() ; i+= 2){
            cout << ans[i] << " " << ans[i + 1] << "\n";
        }

        ans.clear();
    }

    return 0;
}