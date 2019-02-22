//22, 02, 2019, 12:44:52 Rafaelcs cpp
#include <bits/stdc++.h>

#define px  second
#define py  first

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
pii points[N];
const int INF = 1e9;
set< pii > st;

bool compar(pii &a, pii &b){
    return a.px < b.px;
}

int maximum_square_size(int n){
    assert(n != 1);
    sort(points, points + n, compar);
    int sz = INF;

    st.insert(points[0]);
    int left = 0;
    int best = INF;

    for(int i = 1 ; i < n ; i++){
        while(left < i && points[i].px - points[left].px > best){
            st.erase(points[left]);
            left++;
        }

        for(auto p = st.lower_bound({points[i].py - best, points[i].py - best}) ; p != st.end() && (points[i].py + best >= p->py) ; p++){
            best = min(best, max(abs(points[i].px - p->px), abs(points[i].py - p->py)));
        }

        st.insert(points[i]);
    }
    
    st.clear();

    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while(scanf("%d", &n) != EOF){
        for(int i = 0 ; i < n ; i++){
            scanf("%d %d", &points[i].px, &points[i].py);
        }

        printf("%d\n", maximum_square_size(n));
    }
    
    return 0;
}