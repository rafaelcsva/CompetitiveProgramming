//29, 08, 2018, 11:30:14 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const ld EPS = 0.0000000000001L;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    while(cin >> n){
        if(n == 0LL){
            break;
        }
        
        ld ans = -1;
        ll ansi = 0;

        for(int i = 0 ; i < n ; i++){
            ld l, r;

            cin >> l >> r;

            ld cur = max({min(l, r / 4.0L), min(l / 4.0L, r), min(l / 2.0L, r / 2.0L)});

            if(cur - ans > EPS){
                ans = cur;
                ansi = i + 1;
            }
        }

        cout << ansi << endl;
    }

    return 0;
}