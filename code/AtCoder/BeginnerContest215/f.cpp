#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;

const int N = int(2e5) + 10;
pii p[N];
int mn[N], mx[N];
vector< int > x;

bool can(int v){
    for(int i = 0 ; i < x.size() ; i++){
        int fnd = x[i] - v;

        if(x[0] > fnd){
            continue;
        }

        int l = upper_bound(x.begin(), x.end(), fnd) - x.begin() - 1;

        int ge = max(abs(mn[l] - p[i].second), abs(mx[l] - p[i].second));

        if(ge >= v){
            return true;
        }
    }

    return false;
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d", &p[i].first, &p[i].second);
    }

    sort(p, p + n);

    int me = int(1e9) + 10, ma = -1;

    for(int i = 0 ; i < n ; i++){
        me = min(me, p[i].second);
        ma = max(ma, p[i].second);

        mx[i] = ma;
        mn[i] = me;
    
        x.push_back(p[i].first);
    }

    int lo = 0, hi = int(1e9);
    int r = -1;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;

        if(can(mid)){
            r = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    printf("%d\n", r);

    return 0;
}