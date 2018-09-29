//14, 08, 2018, 16:08:13 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
vector< int > idx[N];
map<int, int>id;
int a[N];
set< int > st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;

    scanf("%d %d", &n, &k);

    int e = 1;

    for(int i = 1 ; i <= n ; i++){
        int x;

        scanf("%d", &x);
        a[i] = x;

        if(id[x] == 0){
            id[x] = e++;
        }

        idx[id[x]].push_back(i);
    }

    int past = 0;
    ll cnt = 0LL;

    st.insert(n + 1);
    
    for(int i = 1 ; i <= n ; i++){
        int d = id[a[i]];

        ll lf = i - past;
        ll rg = 0LL;

        int pos = lower_bound(idx[d].begin(), idx[d].end(), i) - idx[d].begin();

        if(pos + k - 1 < idx[d].size()){
            int f = *st.lower_bound(idx[d][pos + k - 1]);
            
            cnt += lf * (f - idx[d][pos + k - 1]);
            if(past && f != n + 1){
                cnt += lf + (f - idx[d][pos + k - 1]);
            }
            past = i;
            st.insert(idx[d][pos + k - 1]);
        }
        
    }

    printf("%lld\n", cnt);

    return 0;
}