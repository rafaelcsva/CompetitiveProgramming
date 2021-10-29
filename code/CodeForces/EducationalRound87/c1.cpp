#include <bits/stdc++.h>

using namespace std;

double pi = acos(-1.0);

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        n *= 2;
        double r = 1.0 / (2.0 * tan(pi / n));

        printf("%.8lf\n", 2.0 * r);
    }

    return 0;
}