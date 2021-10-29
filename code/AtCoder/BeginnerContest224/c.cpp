#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

class Point {
    public:
    ll x, y;
};

Point sub(Point a, Point b){
    return {a.x - b.x, a.y - b.y};
}

ll cross(Point a, Point b){
    return a.x * b.y - b.x * a.y;
}

const int N = 310;
Point p[N];

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }

    int ans = 0;

    for(int i = 0 ;i  < n ; i++){
        for(int j = i + 1  ; j < n ; j++){
            for(int k = j + 1;  k < n ; k++){
                if(cross(sub(p[i], p[j]), sub(p[i], p[k])) != 0){
                    ans++;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}