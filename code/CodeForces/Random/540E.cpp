//15, 02, 2019, 12:18:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(3e5);
map< int, int > slots;
vector< int > changes;
ll BIT[N];

int LSOne(int x){
    return x & (-x);
}

ll query(int x){
    ll sum = 0LL;

    while(x != 0){
        sum += BIT[x];
        x -= LSOne(x);
    }

    return sum;
}

void update(int x, ll value){
    while(x < N){
        BIT[x] += value;
        x += LSOne(x);
    }
}

ll rsq(int l, int r){
    return query(r) - query(l - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        int ai, bi;

        scanf("%d %d", &ai, &bi);

        if(slots.count(ai) == 0){
            slots[ai] = ai;
        }

        if(slots.count(bi) == 0){
            slots[bi] = bi;
        }

        swap(slots[ai], slots[bi]);

        changes.push_back(ai);
        changes.push_back(bi);
    }

    sort(changes.begin(), changes.end());

    auto it = unique(changes.begin(), changes.end());

    changes.erase(it, changes.end());

    ll inversion_cnt = 0LL;

    // printf("%lu\n", changes.size());
    sort(changes.begin(), changes.end());
    
    assert(changes.size() < N);
    
    for(int i = 0 ; i < changes.size() ; i++){
        int pos = changes[i];
        // printf("%d\n", pos);

        int idx = lower_bound(changes.begin(), changes.end(), slots[pos]) - changes.begin() + 1;
        // printf("idx = %d\n", idx);
        inversion_cnt += rsq(idx + 1, N - 1);

        update(idx, 1LL);

        if(pos > slots[pos]){
            inversion_cnt += ll(pos - (slots[pos] + 1)) - 
            ll(lower_bound(changes.begin(), changes.end(), pos) - lower_bound(changes.begin(), changes.end(), slots[pos] + 1));
        }else if(pos < slots[pos]){
            inversion_cnt += ll(slots[pos] - (pos + 1)) - 
            ll(lower_bound(changes.begin(), changes.end(), slots[pos]) - lower_bound(changes.begin(), changes.end(), pos + 1));
        }
    }

    printf("%lld\n", inversion_cnt);

    return 0;
}