#include <bits/stdc++.h>

using namespace std;

deque< int > dq;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;  

    while(t--){
        int n;

        cin >> n;

        int mn = int(1e9);

        for(int i = 0 ; i < n ; i++){
            int ai;

            cin >> ai;
            if(ai < mn){
                dq.emplace_front(ai);
            }else{
                dq.emplace_back(ai);
            }

            mn = min(mn, ai);
        }

        while(!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << "\n";
    }

    return 0;
}