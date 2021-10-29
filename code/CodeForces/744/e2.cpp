#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
ll bit[N];
int a[N];

int LSOne(int x){
    return x & (-x);
}

ll query(int x){
    ll sum = 0LL;

    while(x > 0){
        sum += bit[x];
        x -= LSOne(x);
    }

    return sum;
}

void update(int x, ll add = 1LL){
    while(x < N){
        bit[x] += add;
        x += LSOne(x);
    }
}

ll rsq(int l, int r){
    if(l > r){
        return 0LL;
    }

    return query(r) - query(l - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        vector< int > v;

        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
            v.push_back(a[i]);
        }

        sort(v.begin(), v.end());

        ll sum = 0LL;

        for(int i = 0 ; i < n ; i++){
            a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1; 

            sum += min(rsq(1, a[i] - 1), rsq(a[i] + 1, N - 1));

            update(a[i]);
        }

        cout << sum << "\n";

        for(int i = 0 ; i < n ; i++){
            update(a[i], -1LL);
        }
    }

    return 0;
}