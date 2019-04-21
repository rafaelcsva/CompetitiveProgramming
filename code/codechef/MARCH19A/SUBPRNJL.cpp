//02, 03, 2019, 18:13:08 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2010;
ll BIT[N];
int a[N];

int LSOne(int x){
    return x & (-x);
}

void update(int x, ll val){
    while(x < N){
        BIT[x] += val;
        x += LSOne(x);
    }
}

ll query(int x){
    ll sum = 0LL;

    while(x > 0){
        sum += BIT[x];
        x -= LSOne(x);
    }

    return sum;
}

ll rsq(int l, int r){
    return query(r) - query(l - 1);
}

bool is_beautiful(int n, int k, int len){
    ll m = (k + len - 1) / len;

    int lo = 0, hi = N - 1;
    int r = 0;
    
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        ll val = rsq(0, mid);

        if(val * m < k){
            lo = mid + 1;
        }else{
            r = mid;
            hi = mid - 1;
        }
    }

    lo = 0, hi = N - 1;
    int r2 = 0;

    ll cnt = rsq(r, r);

    return rsq(cnt, cnt) != 0LL;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n, k;

        cin >> n >> k;

        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }

        int cnt_arrays_beautiful = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                update(a[j], 1LL);
                // cout << "testando " << i << " " << j << endl;
                if(is_beautiful(n, k, (j - i) + 1)){
                    // cout << "deu certo" << endl;
                    cnt_arrays_beautiful++;
                }
            }

            memset(BIT, 0LL, sizeof BIT);
        }

        cout << cnt_arrays_beautiful << endl;
    }

    return 0;
}