#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const double eps = 1e-13;

int main(){
    ll n, k;
    ll d, s;

    scanf("%lld %lld", &n, &k);
    scanf("%lld %lld", &d, &s);

    auto S = double(d * n - k * s) / (n - k);

    if(S < -eps || S - 100.0 > eps){
        printf("impossible\n");
    }else{
        printf("%.8lf\n", S);
    }
    return 0;
}