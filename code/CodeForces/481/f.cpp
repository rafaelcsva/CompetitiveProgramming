//13, 05, 2018, 07:29:12 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(2e5 + 100);
int r[N];
vector<int>ord;
vector<vector< int > > conjunto;

bool compar(int i, int j){
    if(r[i] < r[j]){
        return true;
    }

    return false;
}

int binary_search(int en, int v){
    int st = 0;
    int r = -1;

    while(st <= en){
        int mid = (st + en) / 2;

        if(ord[mid] >= v){
            en = mid - 1;
        }else{
            r = mid;
            st = mid + 1;
        }
    }

    return r;
}

int main(){
    int n, k;

    cin >> n >> k;

    conjunto.resize(n + 3);

    for(int i = 0 ; i < n ; i++){
        cin >> r[i];

        ord.push_back(r[i]);
    }

    sort(ord.begin(), ord.end());

    for(int i = 0 ; i < k ; i++){
        int u, v;

        cin >> u >> v;

        u--, v--;

        if(r[u] > r[v]){
            conjunto[u].push_back(v);
        }else if(r[v] > r[u]){
            conjunto[v].push_back(u);
        }
    }

    for(int i = 0 ; i < n; i++){
        int qtd = binary_search(ord.size() - 1, r[i]) + 1;
        
        cout << qtd - conjunto[i].size() << ' ';
    }
    
    cout << endl;
    return 0;
}