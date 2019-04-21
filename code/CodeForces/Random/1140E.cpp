#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
vector< ll > v[2];
ll n, k;
const ll mod = 998244353L;

int main() {
    cin >> n >> k;
    
    for(int i = 0 ; i < n ; i++){
        ll ai;
        
        cin >> ai;
        
        v[i & 1].push_back(ai);
    }
    
    if(n == 1){
        if(v[0][1] == -1){
            cout << k << endl;
        }else{
            cout << 1 << endl;
        }
    }else{
        ll rg = 1LL;
        
        for(int d = 0 ; d < 2 ; d++){
            for(int i = 0 ; i < v[d].size() ; i++){
                ll ag = 1LL;
                
                if(v[d][i] == -1){
                    ag = k;    
                    
                    if(i == 0 && i < v[d].size() - 1 && v[d][i + 1] != -1){
                        ag = k - 1;
                    }
                }else{
                    if(i < v[d].size() - 1){
                        if(v[d][i + 1] == v[d][i]){
                            ag = 0LL;
                        }
                    }
                }
                
                if(i != 0 && v[d][i] == -1){
                    ag = k - 1;
                    
                    if(i < v[d].size() - 1){
                        if(v[d][i + 1] != -1 && v[d][i + 1] != v[d][i - 1]){
                            ag = k - 2;
                        }
                    }
                }
                
                ag = max(ag, 0LL);
                
                rg = (ag * rg) % mod;
            }
            
            //cout << rg << endl;
        }
        
        cout << rg << endl;
        //cout << (lf * rg) % mod << endl;
    }
    
	return 0;
}