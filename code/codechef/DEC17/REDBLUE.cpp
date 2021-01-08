#include <bits/stdc++.h>

using namespace std;

/*  
    <Basic Geometry>
    
    If we have two points A = (x1, y1) and B = (x2, y2), remember that:
    The line equation in the form Ax + By + C for this specific line is
    A = y2 - y1, B = x1 - x2, C = - A * x1 - B * y1

    So if we want to know for some point (x, y) is on the left or right 
    side of this line, we just need to check the signal value of Ax + By + C 
*/

typedef long long   ll;

class Point {
    public:
    ll x, y;
    int tp;
};

vector< Point > pnts;

bool compar(Point &a, Point &b){
    int qda = 0, qdb = 0;

    if(a.x < 0 && a.y >= 0){
        qda = 1;
    }else if(a.x <= 0 && a.y < 0){
        qda = 2;
    }else if(a.x > 0 && a.y < 0){
        qda = 3;
    }

    if(b.x < 0 && b.y >= 0){
        qdb = 1;
    }else if(b.x <= 0 && b.y < 0){
        qdb = 2;
    }else if(b.x > 0 && b.y < 0){
        qdb = 3;
    }

    if(qda < qdb){
        return true;
    }else if(qda > qdb){
        return false;
    }else{
        // x / y = x / y
        if(qda & 1){
            return abs(a.x * b.y) < abs(b.x * a.y);
        }
        return abs(a.y * b.x) < abs(b.y * a.x);
    }
}

int orient(ll a, ll b, ll c, Point d){
    ll res = a * d.x + b * d.y + c;

    if(res < 0){
        return -1;
    }else if(res > 0){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;
        
        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < n ; i++){
            ll x, y;

            scanf("%lld %lld", &x, &y);

            pnts.push_back({x, y, 0});
        }

        for(int i = 0 ; i < m ; i++){
            ll x, y;

            scanf("%lld %lld", &x, &y);

            pnts.push_back({x, y, 1});
        }
        
        int tn = n;
        n += m;
        int ans = int(1e9);

        for(int i = 0 ; i < n ; i++){
            vector< Point > v;

            for(int j = 0 ; j < n ; j++){
                if(i == j) continue;

                v.push_back({pnts[j].x - pnts[i].x, pnts[j].y - pnts[i].y, pnts[j].tp});
            }

            sort(v.begin(), v.end(), compar);

            int l = 0, r = 0;
            int cnt[2];
            cnt[0] = cnt[1] = 0;
            // if(i == 7){
            //     printf("ordered :::\n\n\n\n");

            //     for(auto u: v){
            //         printf("%lld %lld\n", u.x, u.y);
            //     }
            // }

            // printf("tentando com %d\n", i);
            cnt[v[0].tp]++;

            for(; l < n - 1 ; l++){
                if(l != 0){
                    cnt[v[l - 1].tp]--;
                }
                
                if(r < l){
                    r = l;
                    cnt[v[l].tp]++;
                }

                ll a = v[l].y, b = -v[l].x;
                ll c = 0LL;
                int last = -1;
                // printf("l: %d %lld %lld\n", l, a, b);

                while((last = orient(a, b, c, v[(r + 1) % (n - 1)])) == -1){
                    r = (r + 1);
                    cnt[v[r % (n - 1)].tp]++;
                }
                // printf("%d %d\n", r, last);
                int n2 = 0, m2 = 0;

                m2 = m - cnt[1];
                n2 = tn - cnt[0];

                if(pnts[i].tp == 0){
                    n2--;
                }else{
                    m2--;
                }

                // if(v[l].tp == 0){
                //     n2--;
                // }else{
                //     m2--;
                // }

                if(last == 0){
                    if(v[(r + 1) % (n - 1)].tp == 0){
                        n2--;
                    }else{
                        m2--;
                    }
                }

                // if(min(n2 + cnt[1], m2 + cnt[0]) == 1){
                //     printf("pr = (%lld, %lld)\n", v[r % (n - 1)].x, v[r % (n - 1)].y);
                //     printf("a, b = (%lld, %lld)\n", a, b);
                //     printf("r: %d %d %d (%d, %d, |%d, %d| %d %d %d)\n", 
                //     i, l, r % (n - 1), cnt[0], cnt[1], n2, m2, pnts[i].tp, v[l].tp, last);
                // }

                ans = min(ans, min(n2 + cnt[1] - (v[l].tp == 1), m2 + cnt[0] - (v[l].tp == 0)));
            }
        }

        printf("%d\n", ans);

        pnts.clear();
    }

    return 0;
}