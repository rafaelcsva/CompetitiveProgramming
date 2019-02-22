//07, 10, 2018, 10:30:32 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));

    int t = 10;

    printf("%d\n", t);

    while(t--){
        printf("%d %d\n", rand() % 1000 + 1, rand() % 1000 + 1);
    }

    return 0;
}