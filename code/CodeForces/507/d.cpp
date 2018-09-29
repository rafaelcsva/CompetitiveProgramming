//05, 09, 2018, 15:28:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int X = 50;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));

    ll n, k;

    cin >> n >> k;

    ll lo = 1, hi = n;

    string resp;
    int guess = 4500;

    while(guess--){
        if(hi - lo <= X){
            ll sz = hi - lo;

            ll r = rand() % (sz + 1LL);

            cout << r + lo << " " << r + lo << endl;
        
            cin >> resp;

            if(resp == "Yes"){
                return 0;
            }

            lo = max(1LL, lo - k);

            hi = min(n, hi + k);
        }else{
            ll mid = (lo + hi) / 2LL;
            
            cout << lo << " " << mid << endl;

            cin >> resp;

            if(resp != "Yes"){
                // cout << "entrei aqui! " << mid - k << endl;
                lo = max(1LL, mid - k);
                hi = min(n, hi + k);
            }else{
                hi = min(n, mid + k);
                lo = max(1LL, lo - k);
            }
        }
    }
    
    assert(guess == 0);
    
    return 0;
}