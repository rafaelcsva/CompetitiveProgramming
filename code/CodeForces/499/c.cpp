//26, 07, 2018, 12:35:31 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 1010;
int n , m;
ld a[N];
ld b[N];
const ld EPS = 0.000000000001L;
int LOG = 101;

bool can(ld fuel){
    ld c1 = (m + fuel) / a[0];
    
    if(c1 - fuel > EPS){
        return false;
    }

    fuel -= c1;

    for(int i = 1 ; i < n ; i++){
        ld cost_1 = (m + fuel) / a[i];

        if(cost_1 - fuel > EPS){
            return false;
        }

        fuel -= cost_1;

        ld cost_2 = (m + fuel) / b[i];

        if(cost_2 - fuel > EPS){
            return false;
        }

        fuel -= cost_2;
    }

    ld c2 = (m + fuel) / b[0];

    if(c2 - fuel > EPS){
        return false;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    for(int i = 0 ; i < n ; i++){
        cin >> b[i];
    }

    ld st = 0.0L, en = 1e9 + 10;
    ld r = en;
    bool ok = false;

    for(int i = 0 ; i < LOG ; i++){
        ld mid = (st + en) / 2.0L;

        if(can(mid)){
            ok = true;
            r = mid;
            en = mid;        
        }else{
            st = mid;
        }
    }

    if(ok)
        cout << setprecision(7) << fixed << r << endl;
    else
        cout << -1 << endl;

    return 0;
}