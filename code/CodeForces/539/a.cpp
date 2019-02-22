//16, 02, 2019, 15:53:02 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(3e5 + 100), M = int(2e6 + 100);
int a[N];
ll pref[M];
ll cnt[M][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        pref[i] = a[i] ^ pref[i - 1];
        cnt[pref[i]][i & 1]++;
    }
    
    ll tot = 0LL;

    for(int i = 1 ; i <= n ; i++){
        tot += cnt[pref[i - 1]][!(i & 1)];
        cnt[pref[i]][i & 1]--;
    }

    cout << tot << endl;

    return 0;
}