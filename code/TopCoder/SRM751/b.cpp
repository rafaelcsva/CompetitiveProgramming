//21, 02, 2019, 23:06:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

class CalkinWilfReversed{
    public:
    ll getDepth(ll a, ll b){
        ll steps = 0LL;
        while(a != 1LL || b != 1LL){
            if(b == 1LL){
                steps += (a - 1LL);
                break;
            }else if(a == 1LL){
                steps += (b - 1LL);
                break;
            }
            // cout << a << " " << b << endl;
            if(a > b){
                ll q = a / b;
                if(a % b == 0LL){
                    q--;
                }
                steps += q;
                a -= q * b;
            }else{
                ll q = b / a;
                if(b % a == 0LL){
                    q--;
                }
                steps += q;
                b -= q * a;
            }
        }

        return steps;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    
    CalkinWilfReversed test;

    while(true){
    ll a = rand() % 1000000000;
    ll b = rand () % 1000000000;

    cout << "testing with " << a << " and " << b << endl;

    cout << test.getDepth( a
, a + 1
) << endl;
    }

    return 0;
}