//18, 03, 2019, 16:15:16 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

class CoffeeStation{
    public:
    int r;
    int b;
    int x, y;
};

const int N = 30100, M = 1010;
CoffeeStation stations[N];
int mark[N][M];

bool is_unreachable(int x, int y, int xx, int yy, int radius){
    int dx = abs(xx - x);
    int dy = abs(yy - y);

    return radius * radius < dx * dx + dy * dy;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %d", &n, &m);
    int k;

    scanf("%d", &k);

    for(int i = 0 ; i < k ; i++){
        scanf("%d %d %d %d", &stations[i].x, &stations[i].y, &stations[i].r, &stations[i].b);
        swap(stations[i].x, stations[i].y);
        stations[i].x--;
        stations[i].y--;

        int lo = stations[i].x - stations[i].r;
        int hi = stations[i].x + stations[i].r;
        int col = stations[i].y;

        while(col >= 0){
            while(lo <= hi && is_unreachable(hi, col, stations[i].x, stations[i].y, stations[i].r)){
                lo++, hi--;
            }

            if(lo > hi){
                break;
            }

            mark[max(lo, 0)][col] += stations[i].b;
            mark[min(hi + 1, n)][col] -= stations[i].b;

            col--;
        }

        lo = stations[i].x - stations[i].r;
        hi = stations[i].x + stations[i].r;
        col = stations[i].y + 1;

        // cout << "i = " << i << endl;

        while(col < m){
            // cout << "bef = " << col << " -- " << lo << " " << hi << " " << stations[i].x << endl; 
            while(lo <= hi && is_unreachable(hi, col, stations[i].x, stations[i].y, stations[i].r)){
                lo++, hi--;
            }

            // cout << "col = " << col << " -- " << lo << " " << hi << endl; 
            if(lo > hi){
                break;
            }

            mark[max(lo, 0)][col] += stations[i].b;
            mark[min(hi + 1, n)][col] -= stations[i].b;

            col++;
        }
    }

    int mx = 0;

    for(int j = 0 ; j < m ; j++){
        int tmp = 0;

        for(int d = 0 ; d < n ; d++){
            tmp += mark[d][j];

            mx = max(mx, tmp);
        }
    }

    int cnt = 0;

    for(int j = 0 ; j < m ; j++){
        int tmp = 0;

        for(int d = 0 ; d < n ; d++){
            tmp += mark[d][j];

            if(tmp == mx){
                cnt++;
            }
        }
    }

    cout << mx << endl;
    cout << cnt << endl;
    
    return 0;
}