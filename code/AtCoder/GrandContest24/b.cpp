//20, 05, 2018, 10:03:16 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(2e5 + 10);
bool lf[N], rg[N];
int v[N];
vector<int>tmp;
int pos[N];
map<int, int>mp;

int main(){
    int n;

    cin >> n;

    int mnr = n;
    int mnl = -1;
    
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];

        v[i]--;

        pos[v[i]] = i;
        
        if(v[i] > i){
            mnr = min(mnr, i);
            rg[v[i]] = true;
        }else if(v[i] < i){
            mnl = max(mnl, i);
            lf[v[i]] = true;
        }
    }

    int best1 = 0;

    for(int i = n - 1 ; i >= 0 ; i--){
        
        if(rg[i]){
            tmp.push_back(i);
            best1++;
            // cout << i << endl;
        }else{
            if(tmp.size() == i){
                mp[i] = 1;
                // cout << i << endl;
                tmp.push_back(i);
                best1++;
            }
        }
    }

    for(int i = n - 1 ; i >= 0 ; i--){
        int u = v[i];

        if(!rg[u] && !mp[u]){
            tmp.push_back(u);
            // cout << u << endl;
        }
    }

    reverse(tmp.begin(), tmp.end());

    bool ent = false;

    for(int i = 0 ; i < n ; i++){
        int u = tmp[i];

        if(u != i){
            ent = true;
            best1++;
        }
    }

    if(ent){
        best1--;
    }

    tmp.clear();
    mp.clear();
    
    ent = false;
    
    int best2 = 0;

    for(int i = 0 ; i < n ; i++){
        if(lf[i]){
            best2++;
            tmp.push_back(i);
        }else{
            if(tmp.size() == i){
                mp[i] = true;
                best2++;
                tmp.push_back(i);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        int u = v[i];

        if(!lf[u] && !mp[u]){
            tmp.push_back(u);
        }
    }

    for(int i = 0 ; i < n ; i++){
        cout << tmp[i] << ' ';
    }

    cout << endl;
    
    for(int i = 0 ; i < n ; i++){
        if(tmp[i] != i){
            best2++;
            cout << i << endl;
            ent = true;
        }
    }

    if(ent){
        best2--;
    }

    cout << min(best1, best2) << endl;

    return 0;
}