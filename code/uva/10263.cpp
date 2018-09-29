//23, 08, 2018, 18:12:52 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6);
const ld EPS = 0.00000000001L;

struct point{
    ld x, y;
    point(){
        x = y = 0.0L;
    }

    point(ld _x, ld _y) : x(_x), y(_y){}
    
};

point points[N];

// ld hypot(ld x1, ld x2){
//     return sqrt(x1 * x1 + x2 * x2);
// }

ld dist(point &p1, point &p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct line{
    ld a, b, c;
};

void pointsToLine(point p1, point p2, line &l){
    if(fabs(p1.x - p2.x) < EPS){
        l.a = 1.0L;
        l.b = 0.0L;
        l.c = -p1.x;
    }else{
        l.a = (p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0L;
        l.c = (l.a * p1.x) - p1.y;
    }
}

struct vec{
    ld x, y;
    vec(ld _x, ld _y) : x(_x), y(_y){}
};

vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, ld s){
    return vec(v.x * s, v.y * s);
}

point translate(point p, vec v){
    return point(p.x + v.x, p.y + v.y);
}

ld dot(vec a, vec b){
    return (a.x * b.x + a.y * b.y);
}

ld norm_sq(vec v){
    return v.x * v.x + v.y * v.y;
}

ld distToLine(point p, point a, point b, point &c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    ld u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));

    return dist(p, c);
}

ld distToLineSegment(point p, point a, point b, point &c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    ld u = dot(ap, ab) / norm_sq(ab);

    if(u < 0.0L){
        c = point(a.x, a.y);
        return dist(p, a);
    }
    if(u > 1.0){
        c = point(b.x, b.y);
        return dist(p, b);
    }

    return distToLine(p, a, b, c);
}

bool compar(point &a, point &b){
    return b.x - a.x > EPS;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    point m;
    
    while(scanf("%Lf", &m.x) != EOF){
        scanf("%Lf", &m.y);
        // printf("aqui\n");
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n + 1 ; i++){
            scanf("%Lf %Lf", &points[i].x, &points[i].y);
            // printf("%Lf")
        }

        ld best = 1e15;
        point mbest;
        
        for(int i = 0 ; i < n ; i++){
            point c;
            ld dis = distToLineSegment(m, points[i], points[i + 1], c);

            if(best - dis > EPS){
                best = dis;
                mbest = c;
            }
        }

        printf("%.4Lf\n%.4Lf\n", mbest.x, mbest.y);
    }

    return 0;
}