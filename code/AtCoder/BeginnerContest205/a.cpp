#include <bits/stdc++.h>

using namespace std;

int main(){
    double a, b;

    scanf("%lf %lf", &a, &b);

    b /= 100.0;

    printf("%.8lf\n", a * b);

    return 0;
}