#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;

map< string, int > mp;
map< string, int > tim;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    cin.ignore();

    for(int i = 0 ; i < 3 * n ; i++){
        string si;

        getline(cin, si);

        mp[si]++;
        tim[si] = i;
    }

    vector< pair< pii, string > > v;

    for(auto u: mp){
        v.push_back({{u.second, tim[u.first]}, u.first});
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for(int i = 0 ; i < min((int)v.size(), k) ; i++){
        cout << v[i].second << "\n";
    }

    return 0;
}