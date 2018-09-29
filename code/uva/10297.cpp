//29, 08, 2018, 16:53:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int LOG = 500;
const ld PI = 2.0L * acos(0);
const ld EPS = 0.000000000001L;

ld calc(ld d, ld D){
    ld h = (D - d) / 2.0L;
    ld r = d / 2.0L;
    ld R = D / 2.0L;
    
    return D * PI * R * R - ((2.0L * PI * h * (r * r + r * R + R * R)) / 3.0L + d * PI * r * r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int d;
    ld v;

    while(scanf("%d %Lf", &d, &v)){
        if(d == 0)
            break;
            
        ld lo = 0.0L, hi = d;
        ld r = 0.0L;
        // cout << calc(d, d) << endl;
        for(int i = 0 ; i < LOG ; i++){
            ld mid = (lo + hi) / 2.0L;
            ld vol = calc(mid, d);
            // cout << vol << " " << mid << endl;
            if(vol - v > EPS){
                lo = mid;
            }else{
                r = mid;
                hi = mid;
            }
        }

        printf("%.3Lf\n", r);
    }

    return 0;
}