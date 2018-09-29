//28, 07, 2018, 08:50:54 Rafaelcs cpp
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
        int x;

        cin >> x;

        x /= 6;

        int q = sqrt(x);

        cout << q << endl;
    }

    return 0;
}