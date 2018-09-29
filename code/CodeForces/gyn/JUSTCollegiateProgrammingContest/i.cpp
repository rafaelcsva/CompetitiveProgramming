//28, 07, 2018, 10:00:07 Rafaelcs cpp
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
        int a, b;
        double d;

        scanf("%d %d %lf", &a, &b, &d);

        printf("%.7lf\n", (d * d) / 2.0);
    }

    return 0;
}