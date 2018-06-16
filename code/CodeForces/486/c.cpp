//01, 06, 2018, 11:50:05 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

map<ll, vector<pii> >mp;
const int N = int(2e5 + 10);
ll v[N];
map<ll, int>ver;

int main(){
    int k;

    cin >> k;

    for(int i = 0 ; i < k ; i++){
        int n;

        cin >> n;

        ll sum = 0LL;

        for(int j = 0 ; j < n ; j++){
            cin >> v[j];
            sum += v[j];
        }

        for(int j = 0 ; j < n ; j++){
            if(ver[sum - v[j]] == i + 1)
                continue;

            ver[sum - v[j]] = i + 1;
            sum -= v[j];
            
            mp[sum].push_back({i + 1, j + 1});
            sum += v[j];
        }
    }

    for(map<ll, vector<pii> >::iterator it = mp.begin() ; it != mp.end() ; it++){
        if((it->second).size() >= 2){
            cout << "YES" << endl;
            cout << (it->second)[0].first << ' ' << (it->second)[0].second << endl;
            cout << (it->second)[1].first << ' ' << (it->second)[1].second << endl;

            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}