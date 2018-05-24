//05, 05, 2018, 09:03:08 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    int v[3];

    for(int i = 0 ; i < 3 ; i++){
        cin >> v[i];
    }

    int k;
    cin >> k;

    sort(v, v + 3);

    v[2] = v[2] * (1 << k);

    cout << v[0] + v[1] + v[2] << endl;
    return 0;
}