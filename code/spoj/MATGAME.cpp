//15, 04, 2019, 11:34:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int solve(vector< int > v){
    int m = int(v.size()) - 1;

    int grundy = 1e9;

    for(int i = m ; i >= 0 ; i--){
        if(v[i] > grundy){
            grundy++;
        }else{
            if(i == m)
                grundy = v[i];
            else
                grundy = v[i] - 1;
        }
    }

    return grundy;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int xxor = 0;

        int n, m;

        cin >> n >> m;

        for(int i = 0 ; i < n ; i++){
            vector< int > v;

            for(int j = 0 ; j < m ; j++){
                int xi;

                cin >> xi;

                v.push_back(xi);
            }

            xxor ^= solve(v);
            v.clear();
        }

        cout << ((xxor) ? "FIRST" : "SECOND") << endl;
    }
    
    return 0;
}