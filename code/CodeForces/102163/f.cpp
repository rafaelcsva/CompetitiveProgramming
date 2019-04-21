//17, 04, 2019, 17:53:01 Rafaelcs cpp
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
        ll a, b;

        cin >> a >> b;

        ll rest = a - b;

        cout << (rest / 6LL) + (rest % 6LL != 0LL) << endl;
    }
    
    return 0;
}