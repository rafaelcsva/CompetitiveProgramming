//20, 03, 2019, 18:54:41 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

map< int, vector< pii > > mp, mp2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;

    scanf("%d %d %d", &n, &k, &m);

    for(int i = 0 ; i < k ; i++){
        int x, y;

        scanf("%d %d", &x, &y);

        mp[x + y].push_back({x, 0});
        
        mp2[y - x].push_back({x, 0});
    }

    for(int i = 0 ; i < m ; i++){
        int x, y;

        scanf("%d %d", &x, &y);

        mp[x + y].push_back({x, 1});

        mp2[y - x].push_back({x, 1});
    }

    ll sum = 0LL;

    for(map< int, vector< pii > >::iterator it = mp.begin() ; it != mp.end() ; it++){
        sort((it->second).begin(), (it->second).end());

        ll last = it->first - n - 1LL;
        last = max(last, 0LL);

        int signal_last = 1;
        bool first = true;

        for(pii u: it->second){
            if(u.second == 0 || signal_last == 0){
                if(first){
                    ll y = it->first - u.first;
                    // cout <<  u.first << " " << y << " x adding " << min(ll(n - u.first), ll(n - y)) << " " << (it->second)[1].first << endl;
                    sum += min(ll(u.first) - 1LL, ll(n - y));
                }else{
                    sum += u.first - last - 1LL;
                    // cout <<" + " << u.first << " " << last << endl;
                }
            }   

            first = false;
            signal_last = u.second;
            last = u.first;
        }

        if(signal_last == 0){
            ll y = it->first - last;
            // cout <<  last << " " << y << " adding " << min(n - y, n - last) << endl;
            sum += min(n - last, y - 1LL);
        }
    }

    for(map< int, vector< pii > >::iterator it = mp2.begin() ; it != mp2.end() ; it++){
        sort((it->second).begin(), (it->second).end());

        ll last = it->first + 1LL - 1LL;
        last = max(last, 0LL);

        int signal_last = 1;
        bool first = true;

        for(pii u: it->second){
            if(u.second == 0 || signal_last == 0){
                if(first){
                    ll y = it->first + u.first;
                    // cout <<  u.first << " " << y << " adding " << min(ll(u.first - 1LL), y - 1LL) << endl;
                    sum += min(ll(u.first - 1LL), y - 1LL);
                }else{
                    sum += u.first - last - 1LL;
                    // cout <<" + " << u.first << " " << last << endl;
                }
            }

            first = false;
            last = u.first;

            signal_last = u.second;
        }

        if(signal_last == 0){
            ll y = it->first + last;
            // cout <<  last << " " << y << " adding " << min(n - y, n - last) << endl;
            sum += min(n - y, n - last);
        }
    }

    sum += k;

    printf("%lld\n", sum);
    
    return 0;
}