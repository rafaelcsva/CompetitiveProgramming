//26, 04, 2018, 20:59:59 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;

int main(){
    ll test = 1;
    
    while(cin >> n){
        if(n == -1){
            break;
        }

        ll resp = -1;
        ll q = -1;

        cout << n << " coconuts, ";
        
        for(ll i = 1 ; i * i <= n ; i++){
            ll r = n % i;
            ll tmp = n;

            if(r == 0){
                continue;
            }

            for(ll j = 0 ; j < i ; j++){
                if(tmp % i != r){

                    tmp = -1;
                    break;
                }

                tmp -= (tmp / i) + tmp % i;
            }
            
            if(tmp != -1 && tmp % i == 0){
                resp = i;
                q = n % i;
                break;
            }
        }

        if(resp != -1){
            cout << resp << " people and " << q << " monkey" << endl;
        }else{
            cout << "no solution" << endl;
        }

    }

    return 0;
}