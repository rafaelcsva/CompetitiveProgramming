//13, 05, 2018, 06:14:37 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef pair<int, pii> pipii;

const int N = int(2e5 + 100);
ll a[N];

int main(){
    int n, m;

    cin >> n >> m;

    
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];

        if(i){
            a[i] += a[i - 1];
        }
    }

    for(int i = 0 ; i < m ; i++){
        ll x;

        cin >> x;

        int ind = lower_bound(a, a + n, x) - a;
        ll room;

        if(ind == 0){
            room = x;
        }else{
            room = x - a[ind - 1];
        }
        
        cout << ind + 1 << ' ' << room << endl;
    }
    
    return 0;
}