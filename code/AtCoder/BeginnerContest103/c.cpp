//21, 07, 2018, 10:01:47 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int M = 2e8, N = 3010;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int ans = 0;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        ans += a[i] - 1;
    }    

    cout << ans << endl;

    return 0;
}