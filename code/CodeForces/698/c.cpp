#include <bits/stdc++.h>

using namespace std;

#define x   first
#define y   second

typedef long long   ll;

typedef pair< ll, ll >    pii;
typedef pair< pii, int > piipi;

set< piipi > st;

ll mdistance(pii a, pii b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

const int N = 5010;
piipi p[N];

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld %lld", &p[i].first.first, &p[i].first.second);
        p[i].second = i;
        st.insert(p[i]);
    }

    vector< int > ans;
    ans.push_back(st.begin()->second);
    st.erase(st.begin());

    while(st.size() != 0){
        int bg = *ans.rbegin();
        ll ansr = -1LL;
        piipi ansp;

        for(auto u: st){
            auto dis = mdistance(u.first, p[bg].first);

            if(dis > ansr){
                ansr = dis;
                ansp = u;
            }
        }

        ans.push_back(ansp.second);
        st.erase(ansp);
    }

    for(auto u: ans){
        printf("%d ", u + 1);
    }

    printf("\n");

    return 0;
}