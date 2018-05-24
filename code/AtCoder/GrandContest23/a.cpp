//28, 04, 2018, 09:16:31 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
map<ll, int>mp;
const int N = int(2e5 + 100);
ll a[N];

int main(){
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];

        if(i){
            a[i] += a[i - 1];
        }

        mp[a[i]]++;
    }   
    
    ll sum = 0LL;
    ll cnt = 0LL;

    for(int i = 0 ; i < n; i++){
        if(i){
            if(mp[sum])
                mp[sum]--;
        }

        cnt += mp[sum];
        
        sum = a[i];    
    }

    cout << cnt << endl;

    return 0;
}