#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair< double, int > pdi;

const int N = int(2e3) + 10;
const double pi = acos(-1.0);

ll x0[N], x1[N], y[N];
int n;
const double eps = double(1e-15);

ll solve(ll mx, ll mt){
    vector< pdi > v;

    for(int i = 0 ; i < n ; i++){
        if(y[i] == mt){
            continue;
        }

        ll x00 = x0[i] - mx;
        ll x11 = x1[i] - mx;
        ll my = y[i] - mt;
        // printf("%lld-%lld have %lf %lf (%lld %lld %lld)\n", x0[i], x1[i], atan2(my, x00), atan2(my, x11), x00, x11, my);

        v.push_back({atan2(my, x00), i});
        v.push_back({atan2(my, x11), i});

        v.push_back({atan2(my, x00) + 2.0 * pi, i});
        v.push_back({atan2(my, x11) + 2.0 * pi, i});
    }

    sort(v.begin(), v.end());

    int d = 0;
    set< int > s1, s2;
    ll ans = 0LL;
    ll tmp = 0LL;

    for(int i = 0 ; i < (v.size()) / 2 ; i++){
        int tp = 0;

        if(s1.find(v[i].second) == s1.end()){
            tp = 1;
            if(s2.find(v[i].second) != s2.end()){
                s2.erase(v[i].second);
                tmp -= x1[v[i].second] - x0[v[i].second];    
            }
            
            // printf("add (%lld, %lld)\n", x0[v[i].second], x1[v[i].second]);

            tmp += x1[v[i].second] - x0[v[i].second];
            s1.insert(v[i].second);
        }

        ll carry = 0LL;

        while(d < v.size() && (pi - (v[d].first - v[i].first)) > -eps){
            int idx = v[d].second;

            if(s1.find(idx) != s1.end()){
                d++;
            }else{
                if(s2.find(idx) != s2.end()){
                    if(fabs(v[d].first - v[i].first - pi) < eps){
                        carry += (x1[idx] - x0[idx]);
                    }else{
                        tmp -= (x1[idx] - x0[idx]);
                    }

                    s2.erase(idx);
                }else{
                    tmp += x1[idx] - x0[idx];
                    s2.insert(idx);
                }

                d++;
            }
        }

        ans = max(ans, tmp);
        tmp -= carry;

        if(!tp){
            // printf("rmv (%lld, %lld)\n", x0[v[i].second], x1[v[i].second]);
            tmp -= x1[v[i].second] - x0[v[i].second];
            s1.erase(v[i].second);
        }
    }

    return ans;
}

int main(){
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld %lld %lld", &x0[i], &x1[i], &y[i]);
        if(x1[i] < x0[i]){
            swap(x0[i], x1[i]);
        }
    }

    ll ans = 0LL;
    // solve(110, 40);

    for(int i = 0 ; i < n ; i++){
        ll tmp = x1[i] - x0[i];

        tmp += max(solve(x0[i], y[i]), solve(x1[i], y[i]));

        ans = max(ans, tmp);
    }

    printf("%lld\n", ans);
    
    return 0;
}