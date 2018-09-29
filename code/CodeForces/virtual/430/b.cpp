//19, 07, 2018, 13:34:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const ld EPS = 0.0000000000001L;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int r, d;

    int n;

    cin >> r >> d;

    cin >> n;

    int cnt = 0;

    for(int i = 0 ; i < n ; i++){
        int x, y, R;

        cin >> x >> y >> R;

        ld distance = x * x + y * y;

        if(distance >= (r - d + R) * (r - d + R)){
            if(distance <= (r - R) * (r - R)){
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}