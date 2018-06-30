//25, 06, 2018, 09:07:13 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

ll x, y, d;

// store x, y, and d as global variables
void extendedEuclid(ll a, ll b) {
    if (b == 0) {
        x = 1; y = 0; d = a; 
        return; 
    }
    // base case
    extendedEuclid(b, a % b);
    // similar as the original gcd
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, c1, c2, n1, n2;

    while(cin >> n){
        if(n == 0LL)
            break;

        cin >> c1 >> n1 >> c2 >> n2;
        
        extendedEuclid(n1, n2);
        
        if(n % d != 0LL){
            cout << "failed" << endl;
        }else{
            ll q = n / d;
            
            if(c1 * n2 > c2 * n1){
                ll en;

                if(x < 0LL){
                    en = (-1LL * x * q * d + n2 - 1LL) / n2;
                }else{
                    en = (-1LL * x * q * d) / n2;
                }
                
                if(y * q - (n1 / d) * en < 0LL){
                    cout << "failed" << endl;
                    continue;
                }

                cout << x * q + (n2 / d) * en << ' ' << y * q - (n1 / d) * en << endl;
            }else{
                ll en;

                if(y < 0LL){
                    en = (y * q * d - n1 + 1LL) / n1;
                }else{
                    en = (y * q * d) / n1;
                }

                if(x * q + (n2 / d) * en < 0LL){
                    cout << "failed" << endl;
                    continue;
                }

                cout << x * q + (n2 / d) * en << ' ' << y * q - (n1 / d) * en << endl;
            }
            
        }
    }

    return 0;
}