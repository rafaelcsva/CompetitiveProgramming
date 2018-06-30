//25, 06, 2018, 13:28:03 Rafaelcs cpp
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
    
    ll a, b;

    while(cin >> a >> b){
        extendedEuclid(a, b);

        ll n1 = (-x * d) / b;
        ll n2 = (y * d) / a;
        ll r1a = x + (b / d) * n1, r1b = y - (a / d) * n1;
        ll r2a = x + (b / d) * n2, r2b = y - (a / d) * n2;

        if(abs(r1a) + abs(r1b) < abs(r2a) + abs(r2b)){
            cout << r1a << ' ' << r1b << ' ';
        }else if(abs(r1a) + abs(r1b) == abs(r2a) + abs(r2b)){
            if(r1a <= r1b){
                cout << r1a << ' ' << r1b << ' ';
            }else{
                cout << r2a << ' ' << r2b << ' ';
            }
        }else{
            cout << r2a << ' ' << r2b << ' ';
        }

        cout << d << endl;
    }

    return 0;
}