#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
typedef long long ll;
const ll mod=1e9+7LL;
ll a[N];
vector<pair<int,ll>>rs[N];
map<ll, int> sub_gcd[N];
multiset<ll> s;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int n,p;
        cin>>n>>p;
        s.clear();
        for (int i = 0; i < n; ++i)
        {
            sub_gcd[i].clear();
            cin>>a[i];
            rs[i].clear();
        }
        sub_gcd[n-1][a[n-1]] = 0;
        for(int i = n-2; i >= 0; i--)
        {
            sub_gcd[i][a[i]] = 0;
            for(auto it: sub_gcd[i + 1])
            {
                ll new_gcd = __gcd(it.first, a[i]);
                sub_gcd[i][new_gcd] = max(sub_gcd[i][new_gcd], it.second + 1);
            }
            if(sub_gcd[i][a[i]]){
                rs[i].push_back({0,a[i]});
                rs[i+sub_gcd[i][a[i]]].push_back({1,a[i]});
            }
        }
        for (int i = 0; i < n; ++i)
            sub_gcd[i].clear();
        sub_gcd[0][a[0]] = 0;
        for(int i = 1; i < n; i++)
        {
            sub_gcd[i][a[i]] = 0;
            for(auto it: sub_gcd[i - 1])
            {
                ll new_gcd = __gcd(it.first, a[i]);
                sub_gcd[i][new_gcd] = max(sub_gcd[i][new_gcd], it.second + 1);
            }
            if(sub_gcd[i][a[i]]){
                rs[i-sub_gcd[i][a[i]]].push_back({0,a[i]});
                rs[i].push_back({1,a[i]});
            }
        }
        s.insert(p);
        ll ans=0;
        for (int i = 0; i < n; ++i)
        {
            if(i!=0)
                ans+=*s.begin();
            for(auto v:rs[i])
            {
                if(v.first)
                    s.erase(s.find(v.second));
                else
                    s.insert(v.second);
            }
        }
        cout<<ans<<"\n";
 
    }
    return 0;
}  