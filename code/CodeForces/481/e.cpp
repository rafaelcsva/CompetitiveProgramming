//13, 05, 2018, 06:38:54 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    int n, w;

    cin >> n >> w;

    ll mn = 0LL, mx = 0LL;
    ll sum = 0LL;

    for(int i = 0 ; i < n ; i++){
        ll x;

        cin >> x;

        sum += x;
        
        mx = max(mx, sum);
        mn = min(mn, sum);
    }

    ll up = w - mx;
    ll down = -mn;
    
    if(down > up){
        cout << 0 << endl;
    }else{
        cout << up - down + 1LL << endl;
    }

    return 0;
}