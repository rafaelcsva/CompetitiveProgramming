//25, 05, 2018, 21:29:18 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(1e5 + 100);
ll v[N];
ll p[N];
map<ll, ll>mp;

int main(){
    int t;

    cin >> t;

    while(t--){
        ll n, m, k;

        cin >> n >> m >> k;

        for(int i = 0 ; i < n ; i++){
            cin >> v[i];
            v[i] %= m;
        }

        for(int i = 0 ; i < n ; i++){
            p[i] = v[i];

            if(i){
                p[i] *= p[i - 1];
                p[i] %= m;
            }

            mp[p[i]]++;
        }

        ll tot = 0LL;
        ll aux = k;

        for(int i = 0 ; i < n ; i++){
            tot += mp[aux];

            mp[p[i]]--;

            if(!v[i]){
                int ini = i + 1;
                
                while(ini < n && v[ini] != 0){
                    mp[p[ini]]--;
                    p[ini] = v[ini];

                    if(ini != i + 1){
                        p[ini] *= p[ini - 1];
                    }                    

                    p[ini] %= m;
                    mp[p[ini]]++;
                    ini++;
                }

                aux = k;
            }else{
                aux = k * p[i];
                aux %= m;
            }

        }

        cout << tot << endl;
        
        mp.clear();
    }   

    return 0;
}