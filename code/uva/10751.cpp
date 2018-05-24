//28, 04, 2018, 17:35:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    ll n;
    ll t;

    cin >> t;

    while(t--){

        cin >> n;

        if(n == 1){
            cout << fixed << setprecision(3) << ld(0.0L) << endl;
        }else{
            if(n % 2){
                cout << fixed << setprecision(3) << ld(0.414L * n + n * n - 0.828L) << endl;
            }else{
                cout << fixed << setprecision(3) << ld(n * n) << endl;
            }
        }
    }

    return 0;
}