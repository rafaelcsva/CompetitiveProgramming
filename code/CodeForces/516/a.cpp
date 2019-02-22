//14, 10, 2018, 07:06:38 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int a[4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0 ; i < 3 ; i++){
        cin >> a[i];
    }

    sort(a, a + 3);

    int r = max(0, a[2] - a[0] - a[1] + 1);

    cout << r << endl;

    return 0;
}