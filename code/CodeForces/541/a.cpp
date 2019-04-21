//23, 02, 2019, 07:23:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll w1, h1, w2, h2;

    cin >> w1 >> h1 >> w2 >> h2;

    if(w1 > w2){
        cout << w2 + w1 + h1 * 2LL + h2 * 2LL + w1 - w2 - 1LL + 5LL << endl;
    }else{
        cout << w1 + w2 + h1 * 2LL + h2 * 2LL + 4LL << endl;
    }
    // cout << 2LL *h2 + w2 + h1 * 2LL + w1 + w1 - w2 << endl;
    
    return 0;
}