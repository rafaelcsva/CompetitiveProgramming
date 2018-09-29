//01, 07, 2018, 09:19:29 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 1 << 19;
ll a[N];
ll r[N];
ll x[N];
const int B = 20;

ll get_best(int k){
    bitset<B>bst(k);

    ll best = 0LL;
    
    for(int i = 0 ; i < B ; i++){
        int idx = 0;
        
        for(int j = i ; j < B ; j++){
            int w = j;

            best = max(best, a[idx]);
            
            if(bst.test(j)){
                idx |= (1 << w);
            }

            // cout << idx << ' ' << bst << endl;
            
            if(idx == k){
                break;
            }
        
        }
    }

    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    for(int i = 0 ; i < (1 << n) ; i++){
        cin >> a[i];
    }

    ll mx1 = a[0];
    ll mx2 = 0LL;
    int K = (1 << n) - 1;
    int m = 1;
    
    for(int i = 0 ; i < K ; i++){
        if(i == m){
            x[m] = mx1 + mx2;
            m *= 2;
        }
        
        ll b = get_best(i + 1);
        
        r[i + 1] = max(b + a[i + 1], x[m] / 2);
        
        cout << max(r[i], r[i + 1]) << endl;
        
        if(i != (1 << n) - 1){
            if(a[i + 1] >= mx1){
                mx2 = mx1;
                mx1 = a[i + 1];
            }else if(a[i + 1] >= mx2){
                mx2 = a[i + 1];
            }
        }
    }

    return 0;
}