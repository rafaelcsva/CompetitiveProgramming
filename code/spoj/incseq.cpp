//18, 07, 2018, 08:53:42 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e5 + 10), M = 52;
ll Bit[N][M];
ll mod = 5000000LL;

int LSOne(int i){
    return i & (-i);
}

ll add(ll x, ll v){
    x += v;

    if(x >= mod){
        x -= mod;
    }    

    return x;
}

void update(int v, int t, int value){
    for(int i = v ; i < N ; i += LSOne(i)){
        Bit[i][t] = add(Bit[i][t], value);
    }
}

ll query(int v, int t){
    ll value = 0LL;
    
    for(int i = v ; i > 0 ; i -= LSOne(i)){
        value = add(value, Bit[i][t]);
    }

    return value;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;
    
    for(int i = 0 ; i < n ; i++){
        int x;

        cin >> x;
        x++;
        
        for(int t = 1 ; t <= k ; t++){
            if(t > 1){
                ll q = query(x - 1, t - 1);
                if(q == 0){
                    break;
                }

                update(x, t, q);
            }else{
                update(x, t, 1);
            }
        }
    }

    cout << query(N, k) << endl;

    return 0;
}