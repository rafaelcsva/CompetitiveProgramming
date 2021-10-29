#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        vector< int > va, vb;

        for(int i = 0 ; i < n ; i++){
            int xi;

            scanf("%d", &xi);

            va.push_back(xi);
            vb.push_back(xi);
        }

        sort(vb.begin(), vb.end());

        vector< pair< int, int > > op;

        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(va[j] == vb[i]){
                    if(j != i){
                        op.push_back({i + 1, j + 1});
                        rotate(va.begin() + i, va.begin() + j, va.begin() + j + 1);
                    }
                
                    break;
                }
            }    
        }

        cout << op.size() << "\n";
        
        for(auto u: op){
            cout << u.first << " " << u.second << " " << u.second - u.first << "\n";
        }
    }

    return 0;
}