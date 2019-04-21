//05, 03, 2019, 12:14:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6);
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    ll sum = 0LL;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        sum += a[i];
    }

    sort(a + 1, a + 1 + n);

    int q;

    cin >> q;

    while(q--){
        int qi;

        cin >> qi;

        cout << sum - a[n - qi + 1] << endl;
    }

    return 0;
}