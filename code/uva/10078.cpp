//06, 02, 2019, 19:30:01 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

class Point{
    public:
        int x, y;
};

class Vector{
    public:
        int x, y;

        Vector(Point &a, Point &b){
            this->x = b.x - a.x;
            this->y = b.y - a.y;
        }
};

int cross(Vector a, Vector b){
    if(a.x * b.y - a.y * b.x >= 0){
        return 1;
    }else{
        return 0;
    }
}

const int N = 100;
Point p[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    while(scanf("%d", &n) != EOF){
        if(n == 0)
            break;

        for(int i = 0 ; i < n ; i++){
            scanf("%d %d", &p[i].x, &p[i].y);
        }   

        int direction = cross(Vector(p[0], p[1]), Vector(p[0], p[2]));
        bool ok = true;

        for(int i = 0 ; i < n ; i++){
            int nxt_1 = (i + 1) % n;
            int nxt_2 = (i + 2) % n;

            if(cross(Vector(p[i], p[nxt_1]), Vector(p[i], p[nxt_2])) != direction){
                ok = false;
                break;
            }
        }

        if(ok){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }

    return 0;
}