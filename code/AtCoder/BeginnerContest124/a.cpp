//13, 04, 2019, 09:35:28 Rafaelcs cpp
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

    cin >> a >> b;

    cout << max({a + max(a - 1, b), b + max(a, b - 1)}) << endl;

    
    return 0;
}