//08, 01, 2019, 13:41:25 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){    
        ll R, r;

        cin >> R >> r;

        if(2LL * r * r < R * R){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }
    
    return 0;
}