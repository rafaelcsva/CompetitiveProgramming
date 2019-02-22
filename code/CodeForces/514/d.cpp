//05, 10, 2018, 13:14:29 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6);
pii p[N];
const int LOG = 1000;
bool v = false;
const double eps = 1e-9;
int n;

ld dis(int i, double x, double y){
    return hypot(fabs(p[i].first - x), fabs(p[i].second - y));
}

double f(double mid){
    double ans = 0.0;

    for(int i = 0 ; i < n ; i++){
        double r = (mid - p[i].first) * ((mid - p[i].first) / (2.0 * p[i].second));
        r += p[i].second / 2.0;

        if(r - ans > eps){
            ans = r;
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d", &p[i].first, &p[i].second);

        if(i != 0){
            if(v){
                if(p[i].second > 0){
                    printf("-1\n");
                    return 0;
                }         
            }else{
                if(p[i].second < 0){
                    printf("-1\n");
                    return 0;
                }
            }
        }else{
            v = (p[i].second < 0);
        }

        p[i].second = abs(p[i].second);
    }    

    // printf("r = %.3lf\n", (1e8) * (1e8));
    double lo = -1e13, hi = 1e13;

    for(int i = 0 ; i < LOG ; i++){
        double m1 = (lo * 2.0 + hi) / 3.0;
        double m2 = (lo + 2.0 * hi) / 3.0;

        bool b1 = false, b2 = false;

        double r1 = f(m1);
        double r2 = f(m2);

        // printf("Mae eu to no debug!\n");
        // printf("%.2lf %.2lf\n", r1, r2);
        if(r2 - r1 > eps){
            hi = m2;
        }else{
            lo = m1;
        }
    }

    printf("%.8lf\n", f(lo));

    return 0;
}