#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int N = int(1e5 + 100);
ll v[N];
int n;

bool can(ll days){
    ll sum = 0;

    for(int i = 0 ; i < n ; i++){
        if(v[i] <= days){
            sum += days - v[i];
        }else{
            return false;
        }
    }

    if(sum >= days){
        return true;
    }

    return false;
}

int main(){
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }

    ll st = 1LL, en = ll(1e12);
    ll r = -1LL;

    while(st <= en){
        ll mid = (st + en) / 2LL;

        if(can(mid)){
            en = mid - 1LL;
            r = mid;
        }else{
            st = mid + 1LL;
        }
    }
    
    cout << r << endl;
    
    return 0;
}