//16, 05, 2018, 13:47:17 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

vector< vector<int> > nothave;
const int N = 1000;
vector<pii>v;

bool compar(pii a, pii b){
    if(a.first * b.second < b.first * a.second){
        return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);

    nothave.resize(N + 1);
    
    for(int i = 1 ; i <= N ; i++){
        for(int j = i ; j > 0 ; j--){ 
            if(__gcd(i, j) == 1){
                nothave[i].push_back(j);
            }
        }
    }   

    int n, k;
    
    while(cin >> n >> k){
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j < nothave[i].size() ; j++){
                int u = nothave[i][j];

                v.push_back({u, i});
            }
        }    

        sort(v.begin(), v.end(), compar);

        k--;
        
        cout << v[k].first << "/" << v[k].second << endl;

        v.clear();
        
    }

    return 0;
}