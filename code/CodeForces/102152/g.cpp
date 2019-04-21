//01, 04, 2019, 17:33:32 Rafaelcs cpp
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
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        cout << abs(x1 - x2) + abs(y1 - y2) << endl;
    }
    
    return 0;
}