//16, 06, 2018, 09:30:28 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 1010;

typedef struct{
    ll x, y, z;
}Triple;

Triple t1[N], t2[N];
int n, m;

void transpor(int i, int j, int k){
    ll ca = 1, cb = 1, cc = 1;

    if(i){
        ca = -1;
    }

    if(j){
        cb = -1;
    }

    if(k){
        cc = -1;
    }

    for(int i = 0 ; i < n ; i++){
        t2[i].x = t1[i].x * ca;
        t2[i].y = t1[i].y * cb;
        t2[i].z = t1[i].z * cc;
    }
}

bool compar(Triple a, Triple b){
    return (a.x + a.y + a.z) > (b.x + b.y + b.z);
}

ll get(int m){
    ll sx = 0, sy = 0, sz = 0;

    for(int i = 0 ; i < m ; i++){
        sx += t2[i].x, sy += t2[i].y, sz += t2[i].z;
    }

    return abs(sx) + abs(sy) + abs(sz);
}

int main(){
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        cin >> t1[i].x >> t1[i].y >> t1[i].z;
    }    

    ll best = -1LL;

    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            for(int k = 0 ; k < 2 ; k++){
                transpor(i, j, k);

                sort(t2, t2 + n, compar);

                best = max(best, get(m));
            }
        }
    }

    cout << best << endl;

    return 0;
}