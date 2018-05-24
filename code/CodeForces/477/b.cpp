//29, 04, 2018, 10:34:30 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
const int N = int(1e5 + 100);
ll first, v[N];

int main(){
    ll n, a, b;

    cin >> n >> a >> b;

    cin >> first;

    ll tot = first;

    for(int i = 0 ; i < n - 1 ; i++){
        cin >> v[i];
        tot += v[i];
    }

    sort(v, v + n - 1);

    int c = 0;

    for(int i = n - 2 ; i >= 0 ; i--){
        if(first * a >= tot * b){
            break;
        }    

        c++;
        tot -= v[i];
    }

    cout << c << endl;

    return 0;
}