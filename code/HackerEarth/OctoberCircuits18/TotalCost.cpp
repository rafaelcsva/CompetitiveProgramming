//26, 10, 2018, 21:41:02 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int p, s, t, h, x;

    scanf("%d %d %d %d %d", &p, &s, &t, &h, &x);

    int cost = 0;

    while(x && s > t){
        cost += p;
        x--, s--;
    }

    cost += x * h;

    printf("%d\n", cost);
    
    return 0;
}