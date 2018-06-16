//01, 06, 2018, 12:09:16 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(2e5 + 100);
map<ll, bool>mp;
map<ll, int>cat;
ll x[N];
vector<pii>seq;
int best, ans;
const ll INF = ll(1e9);

int main(){
    int n;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n ; i++){

        cin >> x[i];

        mp[x[i]] = true;
    }

    sort(x, x + n);
    
    for(ll p = 0 ; p < 32LL ; p++){
        
        seq.push_back({1, x[0]});
        
        for(int i = 0 ; i < n ; i++){
            if(cat[x[i]] == p + 1)
                continue;
                
            ll diff = (1LL << p);
            
            int tam = 1;
            ll start = x[i];
            ll k = start + diff;
            
            while(k <= INF){
                if(!mp[k] && diff == 1LL){
                    break;
                }

                if(mp[k])
                    tam++;

                diff = diff * diff;
                
                if(diff == 1LL){
                    cat[k] = p + 1;
                    k++;
                } 
                else
                    k = start + diff;
            }

            if(seq[p].first < tam){
                seq[p] = {tam, start};
            }
        }

        if(seq[p].first > ans){
            ans = seq[p].first;
            best = p;
        }
         
    }

    cout << seq[best].first << endl;

    ll diff = (1LL << best);
    ll k = seq[best].second;
    
    while(k <= INF){
        if(!mp[k] && diff == 1LL){
            break;
        }

        if(mp[k])
            cout << k << " ";
            
        if(diff == 1LL){
            k++;
        }else{
            k = seq[best].second + diff;
            diff = diff * diff;
        }
    }

    cout << endl;

    return 0;
}