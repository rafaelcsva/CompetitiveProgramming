//02, 06, 2018, 07:33:25 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = 2010;
int h[N];

int main(){
    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 0 ; i < 2 * n ; i++){
            cin >> h[i];
        }

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            ans = max(ans, h[i] + h[2 * n - i - 1]);
        }

        cout << ans << endl;
    }

    return 0;
}