//06, 05, 2018, 12:16:20 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

map<ll, int>mp;
const int N = int(2e5 + 100);
ll v[N];

int main(){
    int n;

    cin >> n;

    int ans = 0;
    
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
        ll x = v[i];

        mp[x] = max(mp[x], mp[x - 1] + 1);
        
        ans = max(ans, mp[x]);
    }
    
    ll el = -1LL;

    cout << ans << endl;
    vector<int>ind;
    
    for(int i = n - 1 ; i >= 0 ; i--){
        ll x = v[i];
        
        if(mp[x] == ans){
            if(el == -1){
                ind.push_back(i + 1);
                el = x - 1LL;
                ans--;
            }else if(el == x){
                ind.push_back(i + 1);
                el--;
                ans--;
            }
        }
    }

    for(int i = ind.size() - 1 ; i >= 0 ; i--){
        char c = i == 0 ? '\n' : ' ';

        cout << ind[i] << c;
    }

    return 0;
}