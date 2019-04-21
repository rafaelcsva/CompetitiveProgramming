//17, 04, 2019, 18:10:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 100);
ll a[N];

int binary_search(int i, int n, ll x){
    int lo = i, hi = n;
    int r = -1;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        ll sum = a[mid] - a[i - 1];

        if(sum < x){
            r = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    assert(r != -1);

    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n;
        ll x;

        cin >> n >> x;

        for(int i = 1 ; i <= n ; i++){
            cin >> a[i];
            a[i] += a[i - 1];
        }

        ll tot = 0LL;

        for(int i = 1 ; i <= n ; i++){
            if(a[i] - a[i - 1] < x){
                tot += ll(binary_search(i, n, x) - i) + 1LL;
            }
        }

        cout << tot << endl;
    }
    
    return 0;
}