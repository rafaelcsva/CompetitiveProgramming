//10, 05, 2018, 22:55:22 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    ll n;

    while(cin >> n){
        cout << "TERM " << n << " IS ";

        for(ll i = 1LL ; true ; i++){
            
            if(i >= n){
                if(i % 2LL == 0LL){
                    cout << i << "/" << (i - n) + 1LL << endl; 
                    
                }else{
                    cout << i << "/" << n << endl;
                }
                break;
            }else{
                n -= i;
            }
        }
    }

    return 0;
}