#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

typedef pair< ll, ll > pii;
typedef pair< double, int > pdi;

const int N = int(1e4) + 10;
pii kids[N];
bool mark[N];
int inv[N];
pii seg1[N], seg2[N];
int s, k, w;
const double pi = acos(-1.0);

pii substract(pii a, pii b){
    return {a.first - b.first, a.second - b.second};
}

ll cross(pii v1, pii v2){
    return v1.first * v2.second - v2.first * v1.second;
}

bool ccw(pii a, pii b, pii c){
    pii v1 = substract(b, a);
    pii v2 = substract(c, a);

    return cross(v1, v2) > 0;
}

bool comp(int i, int j){
    return (ccw(seg1[j], seg2[j], seg1[i]) || ccw(seg1[j], seg2[j], seg2[i])) && !(ccw(seg1[i], seg2[i], seg1[j]) && ccw(seg1[i], seg2[i], seg2[j]));
}

class Node {
    public:
    int i;
    bool operator <(const Node b) const{
        if(this->i == b.i){
            return false;
        }

        // printf("compare %d %d gives %d\n", this->i, b.i, comp(this->i, b.i));
        return comp(this->i, b.i);
    }
};

set< Node > st;

int solve(pii a){
    st.clear();
    memset(mark, false, sizeof mark);

    int ans = 0;
    vector< pdi > events;

    for(int i = 0 ; i < k ; i++){
        ll dx = kids[i].first - a.first;
        ll dy = kids[i].second - a.second;

        double tan = atan2(dy, dx);

        // printf("kid on %lf\n", tan * 180.0 / pi);

        events.push_back(make_pair(tan, -(i + 1)));
        events.push_back(make_pair(tan + 2 * pi, -(i + 1)));
    }

    for(int i = 0 ; i < w ; i++){
        ll dx = seg1[i].first - a.first;
        ll dy = seg1[i].second - a.second;

        double tan = atan2(dy, dx);

        ll dx1 = seg2[i].first - a.first;
        ll dy1 = seg2[i].second - a.second;

        double tan1 = atan2(dy1, dx1);

        // printf("seg on %lf, %lf\n", tan * 180.0 / pi, tan1 * 180.0 / pi);

        int tccw = ccw(a, seg1[i], seg2[i]);

        if(!tccw){
            swap(seg1[i], seg2[i]);
        }

        events.push_back(make_pair(tan, i * 2 + !tccw));
        events.push_back(make_pair(tan + 2 * pi, i * 2 + !tccw));

        events.push_back(make_pair(tan1, i * 2 + tccw));
        events.push_back(make_pair(tan1 + 2 * pi, i * 2 + tccw));
    }

    sort(events.begin(), events.end());

    for(auto u: events){
        if(u.second < 0){
            int idx = -u.second - 1;
            // printf("test %d\n", idx);
            if(st.size() > 0){
                int bg = (*st.begin()).i;
                int rbg = (*st.rbegin()).i;

                // for(auto u: st){
                //     int bg = u.i;
                //     int rbg = u.i;
                //     if(!ccw(seg1[bg], seg2[bg], kids[idx]) || !ccw(seg1[rbg], seg2[rbg], kids[idx])){
                //         mark[idx] = true;
                //     }    
                // }
    
                if(!ccw(seg1[bg], seg2[bg], kids[idx]) || !ccw(seg1[rbg], seg2[rbg], kids[idx])){
                    mark[idx] = true;
                }
            }
        }else{
            int idx = u.second / 2;

            if(u.second & 1){
                // printf("rmv %d i am %lu\n", idx, st.size());
                // for(auto u: st){
                //     printf("%d\n", u.i);
                // }
                // assert(st.find({idx}) != st.end());
                st.erase({idx});
                // printf("become %lu\n", st.size());
            }else{
                // printf("add %d\n", idx);
                st.insert({idx});
            }
        }
    }

    for(int i = 0 ; i < k ; i++){
        if(!mark[i]){
            // printf("vejo %d\n", i);
            ans++;
        }
    }

    return ans - 1;
}

int main(){
    int ptnum = 0;

    while(scanf("%d %d %d", &s, &k, &w) != EOF){
        for(int i = 0 ; i < k ; i++){
            scanf("%lld %lld",
                &kids[i].first,
                &kids[i].second);
        }

        for(int i = 0 ; i < w ; i++){
            scanf("%lld %lld %lld %lld", 
                &seg1[i].first,
                &seg1[i].second,
                &seg2[i].first,
                &seg2[i].second);
        }

        for(int i = 0 ; i < s ; i++){
            // printf("testando %d\n", i);
            // ptnum++;

            // if(ptnum == 76){
            printf("%d\n", solve(kids[i]));
                // break;
            // }
        }

        // printf("\n");
    }

    return 0;
}
