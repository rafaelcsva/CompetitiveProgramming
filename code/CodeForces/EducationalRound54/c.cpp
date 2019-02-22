//12, 11, 2018, 12:57:56 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        int d;

        scanf("%d", &d);

        int delta = d * d - 4 * d;
        
        if(delta < 0){
            printf("N\n");
            continue;
        }

        if(d == 0){
            printf("Y 0.0000000 0.0000000\n");
            continue;
        }

        double sqrdelta = sqrt(delta);

        double x1 = (d + sqrdelta) / 2.0;

        printf("Y %.9lf %.9lf\n", x1, double(d) / x1);
    
    }

    return 0;
}