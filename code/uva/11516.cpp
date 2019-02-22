//21, 11, 2018, 17:49:02 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
int a[N];
int n, m;
double eps = 1e-13;
const int LOG = 100;

bool can(double mid){
    int tn = n - 1;

    double cur = a[0] + mid;

    for(int i = 1 ; i < m ; i++){
        double dis = fabs(a[i] - cur);

        if(dis - mid > eps){
            if(tn == 0){
                return false;
            }

            cur = a[i] + mid;
            tn--;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < m ; i++){
            scanf("%d", &a[i]);
        }

        sort(a, a + m);

        double lo = 0.0, hi = 1e9;
        double r = -1.0;

        for(int i = 0 ; i < LOG ; i++){
            double mid = (lo + hi) / 2.0;

            if(can(mid)){
                hi = mid;
                r = mid;
            }else{
                lo = mid;
            }
        }

        printf("%.1lf\n", r);
    }
    
    return 0;
}