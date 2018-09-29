//25, 07, 2018, 16:21:44 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll l, r;

    cin >> l >> r;

    if(r - l <= 1000){
        if(r - l == 0){
            cout << r << endl;
            return 0;
        }
        
        int cnt2 = 0, cnt3 = 0;

        for(ll i = l ; i <= r ; i++){
            if(i % 2LL == 0){
                cnt2++;
            }

            if(i % 3LL == 0){
                cnt3++;
            }
        }

        if(cnt2 > cnt3){
            cout << "2" << endl;
        }else{
            cout << "3" << endl;
        }
    }else{
        cout << "2" << endl;
    }

    return 0;
}