#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const double eps = double(1e-13);

int main(){
    double x, y, r;

    cin >> x >> y >> r;

    ll st = x - r - 10;

    ll ans = 0LL;

    double rq = r * r;
    while(st <= x + r + 10LL){
        double rst = fabs(x - double(st));
        if(double(rst * rst) - rq < eps){
            double sq = sqrt(rq - double(rst * rst));
            ll up = floor(sq + y);
            ll down = ceil(y - sq);
            // printf("%lld, %lf <%lld, %lld>\n", st, y - sq, up, down);
            ans += max(up - down + 1L, 0LL);
        }

        st++;
    }

    cout << ans << endl;

    return 0;
}