#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair<ll, ll>    pii;
map<int, int>cnt;
map<int, ll>calc;
set<int>x_axes;
vector<int>v;
const int N = int(1e5 + 10);
pii p[N];
ll INF = ll(1e14);
ll disL[N], disR[N];
vector<ll>distances;

int main() {
    int n, k;
    
    cin >> n >> k;
    
    for(int i = 0 ; i < n ; i++){
        int a, b;
        
        cin >> p[i].first >> p[i].second;
        cnt[p[i].first]++;
        calc[p[i].first] += p[i].second;
        
        if(x_axes.find(p[i].first) == x_axes.end()){
            x_axes.insert(p[i].first);
            v.push_back(p[i].first);
        }
    }
    
    sort(v.begin(), v.end());
    
    ll guys = 0;
    
    for(int i = 0 ; i < v.size() ; i++){
        disL[i] = calc[v[i]];
        
        if(i){
            disL[i] += disL[i - 1] + guys * (v[i] - v[i - 1]);
        }
        
        guys += cnt[v[i]];
    }
    
    guys = 0;
    
    for(int i = v.size() - 1 ; i >= 0 ; i--){
        disR[i] = calc[v[i]];
        
        if(i != v.size() - 1)
            disR[i] += disR[i + 1] + guys * (v[i + 1] - v[i]);
        
        guys += cnt[v[i]];
    }
    
    ll ans = INF;
    int best = 0;
    
    for(int i = 0 ; i < v.size() ; i++){
        ll dis = disR[i] + disL[i] - calc[v[i]];
        
        if(dis < ans){
            ans = dis;
            best = v[i];
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        ll dis = 0;
        
        dis = p[i].second + abs(best - p[i].first);
        distances.push_back(dis);
    }
    
    sort(distances.begin(), distances.end());
    
    ll sum = 0;
    
    for(int i = 0 ; i < k ; i++){
        sum += distances[i];    
    }
    
    cout << sum << endl;
    
    return 0;
}