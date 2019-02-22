//15, 11, 2018, 18:03:18 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        ll a, b, c, x;

        scanf("%lld %lld %lld %lld", &a, &b, &c, &x);

        double f = (b + c);

        double h = a / 2.0;
        printf("h: %.2lf\n", h);

        double total = hypot(c, a / 2.0) + hypot(c + b, a / 2.0);
        double hp = hypot(a, b);
        double sen = b / hp;
        double per = (x / 100.0) * hp;
        total += per;
        printf("%.2lf\n", per);
        double difb = per * sen;
        double na = a - sqrt(per * per - difb * difb);
        double nb = b - difb;

        printf("difb = %.2lf %.2lf\n", difb, sqrt(per * per - difb * difb));
        
        total += hypot(c + nb, 2.0 * na / 3.0);

        total += hypot(c, na / 3.0);

        printf("%.9lf\n", total);
    }

    return 0;
}