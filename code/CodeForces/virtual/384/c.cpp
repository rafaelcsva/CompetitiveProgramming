//31, 05, 2018, 10:15:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

ll n;
const ll N = int(1e4);
const ll INF = int(1e9);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n ;

    if(n == 1)
        cout << "-1" << endl;
    else
        cout << n << ' ' << n + 1 << " " << n * (n + 1) << endl;
        
    return 0;
}