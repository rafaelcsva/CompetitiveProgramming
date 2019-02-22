//06, 10, 2018, 09:13:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 100;
pii p[N + 10];
int h[N + 10];
int n;

int can(int i, int j){
    int h0 = 1;

    for(int k = 0 ; k < n ; k++){
        if(h[k] != 0){
            h0 = abs(p[k].first - i) + abs(p[k].second - j) + h[k];
            break;
        }
    }

    for(int k = 0 ; k < n ; k++){
        if(h[k] == 0)
            continue;

        int hi = abs(p[k].first - i) + abs(p[k].second - j) + h[k];

        if(hi != h0){
            return -1;
        }
    }

    return h0;
}

bool ver(int H, int cx, int cy){
    for(int i = 0 ; i < n ; i++){
        if(max(H - (abs(cx - p[i].first) + abs(cy - p[i].second)), 0) != h[i]){
            return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    scanf("%d", &n);
    
    for(int i = 0 ; i < n ; i++){
        scanf("%d %d %d", &p[i].first, &p[i].second, &h[i]);
    }

    for(int i = 0 ; i <= N ; i++){
        for(int j = 0 ; j <= N ; j++){
            int d = can(i, j);

            if(d != -1 && d > 0 && ver(d, i, j)){
                printf("%d %d %d\n", i, j, d);
                return 0;
            }
        }
    }

    assert(false);

    return 0;
}