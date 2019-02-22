//18, 02, 2019, 12:45:09 Rafaelcs cpp
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

    int n, m, k;

    cin >> n >> m >> k;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    ll sum = 0LL;

    sort(a, a + n);

    ll add = a[n - 1] * k + a[n - 2];
    ll rep = m / (k + 1);
    ll rest = m % (k + 1);
    
    cout << add * rep + rest * a[n - 1] << endl;
    
    return 0;
}