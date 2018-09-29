//18, 09, 2018, 14:56:13 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, int> pii;
typedef unsigned long long ull;

const int N = 3e5;
ll a[N];
map< ll, bool > mark;
map< ll, int > idx;
set< pii > st;

ll Bit[N];

int LSOne(int x){
    return x & (-x);
}

void update(int x, ll value){
    while(x < N){
        Bit[x] += value;
        x += LSOne(x);
    }
}

ll query(int x){
    ll sum = 0LL;

    while(x > 0){
        sum += Bit[x];
        x -= LSOne(x);
    }

    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    ll t;

    scanf("%d %lld", &n, &t);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];

        if(!mark[a[i]]){
            st.insert({a[i], i});
            mark[a[i]] = true;
        }
    }

    int id = 1;

    for(set< pii >::iterator it = st.begin() ; it != st.end() ; it++){
        idx[it->first] = id++;
    }

    for(int i = 1 ; i <= n ; i++){
        update(idx[a[i]], 1LL);
    }

    ll tot = 0LL;
    ll search = t;

    for(int i = 1 ; i <= n ; i++){
        set< pii >::iterator se = st.lower_bound({search, -1LL});
        int pos = id;

        if(se != st.end()){
            pos = idx[se->first] - 1;
        }

        tot += query(pos);
        
        search = t + a[i];
        update(idx[a[i]], -1LL);
    }

    printf("%lld\n", tot);
    
    return 0;
}