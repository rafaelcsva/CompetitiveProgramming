#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 10100;
const int OFF_SET = 5010;
int f1[N], s1[N], f2[N], s2[N];
vector< int > vert;
vector< int > hor;
int bit[N];

int LSOne(int x){
    return x & (-x);
}

void update(int x, int add){
    assert(x > 0 && x < N);

    while(x < N){
        bit[x] += add;
        x += LSOne(x);
    }
}

int query(int x){
    assert(x >= 0 && x < N);
    int sum = 0;

    while(x > 0){
        sum += bit[x];
        x -= LSOne(x);
    }

    return sum;
}

int rsq(int l, int r){
    if(l > r){
        return 0;
    }

    return query(r) - query(l - 1);
}

bool compar_vert(int i, int j){
    return f1[i] < f1[j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d %d %d", &f1[i], &s1[i], &f2[i], &s2[i]);
        f1[i] += OFF_SET;
        f2[i] += OFF_SET;
        s1[i] += OFF_SET;
        s2[i] += OFF_SET;

        if(f1[i] > f2[i]){
            swap(f1[i], f2[i]);
        }

        if(s1[i] > s2[i]){
            swap(s1[i], s2[i]);
        }

        if(f1[i] == f2[i]){
            vert.push_back(i);
        }else{
            hor.push_back(i);
        }
    }

    sort(vert.begin(), vert.end(), compar_vert);
    sort(hor.begin(), hor.end(), compar_vert);

    ll ans = 0LL;

    for(int i = 0 ; i < vert.size() ; i++){
        int st = 0;
        priority_queue< pair< int, int > > pq;

        while(st < hor.size() && f1[hor[st]] <= f1[vert[i]]){
            pq.push({f2[hor[st]], st});
            assert(s1[hor[st]] == s2[hor[st]]);
            update(s1[hor[st]], 1);
            st++;
        }

        for(int j = i + 1; j < vert.size() ; j++){
            assert(f1[vert[j]] >= f1[vert[i]]);
            while(!pq.empty() && pq.top().first < f1[vert[j]]){
                auto u = pq.top();
                assert(s1[hor[u.second]] == s2[hor[u.second]]);
                update(s1[hor[u.second]], -1);

                pq.pop();
            }
 
            int s1q = max(s1[vert[i]], s1[vert[j]]);
            int s2q = min(s2[vert[i]], s2[vert[j]]);

            ll tot = ll(rsq(s1q, s2q));

            ans += (tot * (tot - 1LL)) / 2LL;
        }

        while(!pq.empty()){
            auto u = pq.top();
            update(s1[hor[u.second]], -1);
            assert(s1[hor[u.second]] == s2[hor[u.second]]);

            pq.pop();
        }

        assert(rsq(1, N - 1) == 0);
    }

    assert(ans >= 0LL);

    printf("%lld\n", ans);

    return 0;
}
