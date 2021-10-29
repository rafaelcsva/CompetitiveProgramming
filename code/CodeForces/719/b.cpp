#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
vector< ll > ordinary;

int main(){
    for(int i = 0 ; i < 10 ; i++){
        for(ll k = 1 ; k <= 9 ; k++){
            ll num = k;

            for(int j = 0 ; j < i ; j++){
                num = num * 10LL + k;
            }

            ordinary.push_back(num);
        }
    }

    sort(ordinary.begin(), ordinary.end());

    int t;

    cin >> t;

    while(t--){
        ll ni;

        cin >> ni;
    
        cout << (upper_bound(ordinary.begin(), ordinary.end(), ni) - ordinary.begin()) << endl;
    }

    return 0;
}