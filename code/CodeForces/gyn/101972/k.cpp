//15, 11, 2018, 15:24:31 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector< int > ind;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        string a, b;

        int n;

        cin >> n;
        cin >> a >> b;

        for(int i = 0 ; i < n ; i++){
            if(a[i] != b[i]){
                ind.push_back(i);
            }
        }

        string tmp = b;

        for(int i = 0 ; i < ind.size() ; i++){
            int u = ind[i];
            int idv = (i - 1 + ind.size()) % ind.size();
            int v = ind[idv];

            tmp[u] = b[v];
        }

        if(tmp != a){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }

        ind.clear();
    }

    return 0;
}