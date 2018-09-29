//18, 08, 2018, 09:03:53 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;

    scanf("%d %d", &a, &b);

    int have = a + b - 1;

    printf("%d\n", a * b - have);
    
    return 0;
}