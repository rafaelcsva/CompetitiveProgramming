#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair< int, int > pii;
typedef pair< pii, int >  piipi;

vector< piipi > v;

int main(){
    int n;

    scanf("%d", &n);

    ll ans = 0LL;

    for(int i = 0 ; i < n ; i++){
        int ui, vi;

        scanf("%d %d", &ui, &vi);
    
        v.push_back({{ui, vi}, i});

        ans += vi;
    }

    sort(v.begin(), v.end());

    int i;
    int st = -1;

    for(i = 0 ; i < v.size() ; i++){
        
    
        if(i == 0){
            st = v[i].first.first + v[i].first.second;
        }else if(st < v[i].first.first){
            ans += ll(v[i].first.first - st);
        }

        st = max(st, v[i].first.first + v[i].first.second);
        // printf("d: %d %d %d\n", v[i].first.first, v[i].first.second, st);

        if(v[i].second == 0){
            break;
        }
    }

    i++;

    for(; i < v.size() ; i++){
        
        if(st < v[i].first.first){
            // printf("add %lld\n", ll(v[i].first.first - v[i - 1].first.first));
            ans += ll(v[i].first.first - st);
        }

        st = max(st, v[i].first.first + v[i].first.second);

        // printf("d: %d %d %d\n", v[i].first.first, v[i].first.second, st);
    }

    printf("%lld\n", ans);

    return 0;
}