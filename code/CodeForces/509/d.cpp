//16, 09, 2018, 08:12:52 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll , int> pii;
typedef unsigned long long ull;

const int N = int(2e5 + 100);
ll pre[N];
pii pt[N];
set< pii > st;
set< pii >::iterator it;
const ll mx = 2e18;
int n;
ll h;

ll solve(int pos){
    ll lo = pt[pos].first;
    ll hi = mx;
    ll r = -1LL;
    ll o;
    
    while(lo <= hi){
        ll mid = (lo + hi) / 2LL;
        ll tot = 0LL;
    
        it = st.lower_bound({mid, -1});

        if(it != st.end()){
            if(it->first > mid){
                it = prev(it);
            }
        }

        bool flag = false;
        
        if(it == st.end()){
            tot = pre[n] - pre[pos - 1];
            
            if(mid <= pt[n].second){
                if(mid > pt[n].first){
                    flag = true;
                }
            }
        }else{
            if(mid <= pt[it->second].second){
                if(mid > pt[it->second].first){
                    flag = true;
                }
                
                tot = pre[it->second - 1] + mid - pt[it->second].first - pre[pos - 1];
            }else{
                tot = pre[it->second] - pre[pos - 1];
            }
        }

        ll x = mid - tot - pt[pos].first;

        if(x < h || (x == h && !flag)){
            r = mid - pt[pos].first;
            o = tot;
            // if(pos == 3)
            // cout << "x = " << x << " " << mid << " " << tot << " " << pt[pos].first << endl;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %lld", &n, &h);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld %d", &pt[i].first, &pt[i].second);
        st.insert({pt[i].first, i});
    }

    for(int i = 1 ; i <= n ; i++){
        pre[i] = pt[i].second - pt[i].first;
        pre[i] += pre[i - 1];
    }

    ll best = 0LL;
    
    for(int i = 1 ; i <= n ; i++){
        best = max(best, solve(i));

        // if(i == 3){
        //     cout << solve(i) << " " << pt[i].first << endl;
        // }
    }

    // if(mx - pre[n] - pt[1].first <= h){
    //     best = max(best, mx - pt[1].first + h - (mx - pre[n] - pt[1].first));
    // }
    // printf("%lld\n", mx - pt[1].first + mx - pre[n] - pt[1].first);

    while(!best){

    }
    
    printf("%lld\n", best);
    
    return 0;
}