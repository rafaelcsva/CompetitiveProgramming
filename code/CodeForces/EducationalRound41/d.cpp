#include <bits/stdc++.h>

using namespace std;

#define x   first
#define y   second

typedef long long   ll;

typedef pair< ll, ll >  pll;

const int N = int(1e5) + 10;
int n;
pll p[N];
bool marked[N];

bool solve(int a, int b){
    memset(marked, false, sizeof marked);

    marked[a] = marked[b] = true;

    ll dy = p[b].y - p[a].y;
    ll dx = p[b].x - p[a].x;

    for(int i = b + 1 ; i < n ; i++){
        ll dxi = p[i].x - p[b].x;
        ll dyi = p[i].y - p[b].y;

        if(dyi * dx == dxi * dy){
            marked[i] = true;
        }
    }

    int f = -1;
    int s = -1;

    for(int i = 0; i < n ; i++){
        if(!marked[i]){
            if(f == -1){
                marked[i] = true;
                f = i;
            }else{
                marked[i] = true;
                s = i;
                break;
            }
        }
    }

    if(s == -1){
        return true;
    }

    dx = p[s].x - p[f].x;
    dy = p[s].y - p[f].y;

    for(int i = 0 ; i < n ; i++){
        if(!marked[i]){
            ll dxi = p[i].x - p[s].x;
            ll dyi = p[i].y - p[s].y;

            if(dyi * dx == dxi * dy){
                marked[i] = true;
            }else{
                return false;
            }
        }
    }

    return true;
}

int main(){
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }

    sort(p, p + n);

    if(n <= 3){
        printf("YES\n");
    }else{
        if(solve(0, 1) || solve(0, 2) || solve(1, 2)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}