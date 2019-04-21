//06, 04, 2019, 08:45:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
ll a[N];

bool can(int mid, ll h){
    vector< ll > v;

    for(int i = 1 ; i <= mid ; i++){
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());

    for(int i = mid - 1 ; i >= 0 ; i -= 2){
        h -= v[i];
    }

    return h >= 0LL;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll h;

    cin >> n >> h;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }   

    int lo = 1, hi = n;
    int r = 0;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;

        if(can(mid, h)){
            r = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    cout << r << endl;

    return 0;
}