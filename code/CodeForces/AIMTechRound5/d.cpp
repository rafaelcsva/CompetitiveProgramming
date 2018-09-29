//27, 08, 2018, 15:40:20 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

multiset<int>carry;
multiset<int>::iterator it;
const ll mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    int lo = -1, hi = -1;
    ll all = 1LL;
    bool part = false;
    bool ver = false;
    
    for(int i = 0 ; i < n ; i++){
        string s;
        int x;

        cin >> s >> x;

        if(s == "ADD"){
            if(carry.size() == 0){
                part = false;
            }

            carry.insert(x);
            if(lo == -1 && hi == -1){
                lo = hi = x;
            }
        }else{
            ver = true;
            
            if(part){
                if(lo != x && hi != x){
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                all *= 2LL;
                all %= mod;

                part = true;

                lo = hi = x;

                it = carry.find(x);
                
                if(it == carry.begin()){
                    lo = -1;
                }else{
                    lo = *prev(it);
                }

                it = next(it);

                if(it != carry.end()){
                    hi = *it;
                }else{
                    hi = -1;
                }
                
                it = prev(it);
                
                carry.erase(it);
            }
        }
    }

    if(!ver){
        all = n - 1LL;
    }
    
    cout << all << endl;

    return 0;
}